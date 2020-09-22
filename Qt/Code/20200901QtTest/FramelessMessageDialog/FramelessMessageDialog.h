#ifndef FRAMELESSMESSAGEDIALOG_H
#define FRAMELESSMESSAGEDIALOG_H

#include <QWidget>
#include <QMessageBox>
#include <QEventLoop>

namespace Ui {
class FramelessMessageDialog;
}

class FramelessMessageDialog : public QWidget
{
    Q_OBJECT

public:
    explicit FramelessMessageDialog(const QString &title,const QString &text
                                    ,QMessageBox::StandardButtons buttons = QMessageBox::NoButton,QWidget *parent = 0);
    explicit FramelessMessageDialog(const QString &title,QWidget *widget
                                    ,QMessageBox::StandardButtons buttons = QMessageBox::NoButton,QWidget *parent = 0);
    ~FramelessMessageDialog();

public:
    //模态运行，非模态直接show
    int exec();
    int showResult();

    void initButtonBox(const QMessageBox::StandardButtons &buttons);
    void setDefault(const QMessageBox::StandardButtons &button);

    //设置标题
    void setTitle(const QString &title);
    //设置窗口大小固定
    void setWidgetFixed(bool isFixed);

protected:
    virtual void closeEvent(QCloseEvent *event) override;
    //界面可拖拽
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    //界面缩放
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private slots:
    void slotButtonBoxClicked(QAbstractButton *button);
    void slotCloseBtnClicked();

private:
    Ui::FramelessMessageDialog *ui;

    //控制拖拽
    bool mMouseFlag;
    QPoint mMousePos;
    //模态控制
    QEventLoop *mEventLoop;
    int mResult;
    bool mIsFixed;
};

#endif // FRAMELESSMESSAGEDIALOG_H
