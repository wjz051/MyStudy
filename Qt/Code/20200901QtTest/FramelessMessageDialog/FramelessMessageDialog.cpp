#include "FramelessMessageDialog.h"
#include "ui_FramelessMessageDialog.h"

#include <QPlainTextEdit>

#ifdef Q_OS_WIN
#include <qt_windows.h>
#include <Windowsx.h>
#endif

#define MESSAGEBOXEX_ROLETYPE   "Role"
#define TITLE_HIDE   "Title_Hide"

FramelessMessageDialog::FramelessMessageDialog(const QString &title, const QString &text, QMessageBox::StandardButtons buttons, QWidget *parent) :
    QWidget(parent),mEventLoop(nullptr),mIsFixed(false),
    ui(new Ui::FramelessMessageDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    initButtonBox(buttons);

    ui->label_title->setText(title);
    QPlainTextEdit *textEdit=new QPlainTextEdit(text,this);
    ui->verticalLayout->addWidget(textEdit);
}

FramelessMessageDialog::FramelessMessageDialog(const QString &title,QWidget *widget, QMessageBox::StandardButtons buttons, QWidget *parent):
    QWidget(parent),mEventLoop(nullptr),mIsFixed(false),
    ui(new Ui::FramelessMessageDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    initButtonBox(buttons);

    ui->label_title->setText(title);
    widget->setParent(ui->frame_body);
    ui->verticalLayout->addWidget(widget);
}

FramelessMessageDialog::~FramelessMessageDialog()
{
    delete ui;
}

int FramelessMessageDialog::exec()
{
    // 设置为模态;
    this->setWindowModality(Qt::ApplicationModal);
    show();
    // 使用事件循环QEventLoop ,不让exec()方法结束，在用户选择确定或者取消后，关闭窗口结束事件循环，并返回最后用户选择的结果;
    // 根据返回结果得到用户按下了确定还是取消，采取相应的操作。从而模拟出QDialog类的exec()方法;
    mEventLoop = new QEventLoop(this);
    mEventLoop->exec();

    return mResult;
}

int FramelessMessageDialog::showResult()
{
    return mResult;
}

void FramelessMessageDialog::initButtonBox(const QMessageBox::StandardButtons &buttons)
{
#define ADD_BUTTON(role, text)      do { \
                                          if(buttons & (role)) \
                                           { \
                                               QPushButton *btn = ui->buttonBox->addButton(text, QDialogButtonBox::ActionRole); \
                                               btn->setProperty(MESSAGEBOXEX_ROLETYPE, (role)); \
                                           } \
                                       }while(0)
    ADD_BUTTON(QDialogButtonBox::Ok, QStringLiteral("确定"));
    ADD_BUTTON(QDialogButtonBox::Open, QStringLiteral("打开"));
    ADD_BUTTON(QDialogButtonBox::Save, QStringLiteral("保存"));
    ADD_BUTTON(QDialogButtonBox::Cancel, QStringLiteral("取消"));
    ADD_BUTTON(QDialogButtonBox::Close, QStringLiteral("关闭"));
    ADD_BUTTON(QDialogButtonBox::Discard, QStringLiteral("取消下载"));
    ADD_BUTTON(QDialogButtonBox::Apply, QStringLiteral("应用"));
    ADD_BUTTON(QDialogButtonBox::Reset, QStringLiteral("重置"));
    ADD_BUTTON(QDialogButtonBox::RestoreDefaults, QStringLiteral("恢复默认"));
    ADD_BUTTON(QDialogButtonBox::Help, QStringLiteral("帮助"));
    ADD_BUTTON(QDialogButtonBox::SaveAll, QStringLiteral("保存全部"));
    ADD_BUTTON(QDialogButtonBox::YesToAll, QStringLiteral("全部选是"));
    ADD_BUTTON(QDialogButtonBox::NoToAll, QStringLiteral("全部选否"));
    ADD_BUTTON(QDialogButtonBox::Yes, QStringLiteral("是"));
    ADD_BUTTON(QDialogButtonBox::No, QStringLiteral("否"));
    ADD_BUTTON(QDialogButtonBox::Abort, QStringLiteral("终止"));
    ADD_BUTTON(QDialogButtonBox::Retry, QStringLiteral("重试"));
    ADD_BUTTON(QDialogButtonBox::Ignore, QStringLiteral("忽略"));
#undef ADD_BUTTON

    connect(ui->pushButton_close,SIGNAL(clicked()),this,SLOT(slotCloseBtnClicked()));
    connect(ui->buttonBox,SIGNAL(clicked(QAbstractButton*)),this,SLOT(slotButtonBoxClicked(QAbstractButton*)));
}


void FramelessMessageDialog::setDefault(const QMessageBox::StandardButtons &button)
{
    foreach(QAbstractButton *btn, ui->buttonBox->buttons())
    {
        if(btn->property(MESSAGEBOXEX_ROLETYPE).toInt() == button)
        {
            ((QPushButton *)btn)->setDefault(true);
            break;
        }
    }
}

void FramelessMessageDialog::setTitle(const QString &title)
{
    ui->label_title->setText(title);
    if(TITLE_HIDE==title)
    {
        ui->frame_title->hide();
    }
}

void FramelessMessageDialog::setWidgetFixed(bool isFixed)
{
    mIsFixed=isFixed;
    if(isFixed)
    {
        setFixedSize(this->width(), this->height());
    }
}

/**
 * @brief 点击按钮
 * @param button
 */
void FramelessMessageDialog::slotButtonBoxClicked(QAbstractButton *button)
{
    mResult = button->property(MESSAGEBOXEX_ROLETYPE).toInt();
    close();
}

void FramelessMessageDialog::slotCloseBtnClicked()
{
    mResult = QDialogButtonBox::Close;
    close();
}

void FramelessMessageDialog::closeEvent(QCloseEvent *event)
{
    // 关闭窗口时结束事件循环，在exec()方法中返回选择结果;
    if (mEventLoop != nullptr)
    {
        mEventLoop->exit();
    }
    event->accept();
}

//鼠标控制界面移动

void FramelessMessageDialog::mousePressEvent(QMouseEvent *event)
{
    if( event->button() == Qt::LeftButton)
    {
        mMouseFlag=true;
        mMousePos = event->globalPos();
    }
    QWidget::mousePressEvent(event);
}

void FramelessMessageDialog::mouseMoveEvent(QMouseEvent *event)
{
    if (!mMouseFlag||!event->buttons().testFlag(Qt::LeftButton))
        return;
    const QPoint position = pos() + event->globalPos() - mMousePos;
    move(position.x(), position.y());
    mMousePos = event->globalPos();

    QWidget::mouseMoveEvent(event);
}

void FramelessMessageDialog::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        mMouseFlag=false;
    QWidget::mouseReleaseEvent(event);
}

bool FramelessMessageDialog::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    if(mIsFixed)
    {
        return false;
    }

    int m_nBorder = 8;
    Q_UNUSED(eventType)
    MSG *param = static_cast<MSG *>(message);

    switch (param->message)
    {
    case WM_NCHITTEST:
    {
        int nX = GET_X_LPARAM(param->lParam) - this->geometry().x();
        int nY = GET_Y_LPARAM(param->lParam) - this->geometry().y();

        *result = HTCAPTION;

        // if mouse in the border of mainframe,we zoom mainframe
        if ((nX > 0) && (nX < m_nBorder))
            *result = HTLEFT;

        if ((nX > this->width() - (m_nBorder)) && (nX < this->width()))
            *result = HTRIGHT;

        if ((nY > 0) && (nY < m_nBorder))
            *result = HTTOP;

        if ((nY > this->height() - (m_nBorder)) && (nY < this->height()))
            *result = HTBOTTOM;

        if ((nX > 0) && (nX < m_nBorder) && (nY > 0)
                && (nY < m_nBorder))
            *result = HTTOPLEFT;

        if ((nX > this->width() - m_nBorder) && (nX < this->width())
                && (nY > 0) && (nY < m_nBorder))
            *result = HTTOPRIGHT;

        if ((nX > 0) && (nX < m_nBorder)
                && (nY > this->height() - m_nBorder) && (nY < this->height()))
            *result = HTBOTTOMLEFT;

        if ((nX > this->width() - m_nBorder) && (nX < this->width())
                && (nY > this->height() - m_nBorder) && (nY < this->height()))
            *result = HTBOTTOMRIGHT;

        if (*result == HTCAPTION)
        {
            return false;
        }
        return true;
    }
    }
    return false;
}
