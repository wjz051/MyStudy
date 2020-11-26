#include "MyQtDemo.h"
#include "ui_MyQtDemo.h"
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QDebug>

MyQtDemo::MyQtDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyQtDemo)
{
    ui->setupUi(this);

    ui->spinBox->setValueTimes(4);

    ui->spinBox_2->setFocus();
    //ui->spinBox_2->lineEdit()->selectAll();

    ui->lineEdit->setAttribute(Qt::WA_InputMethodEnabled, false);

    int childCount=ui->treeWidget->topLevelItemCount();
    QTreeWidgetItem *item=ui->treeWidget->takeTopLevelItem(1);
    item->takeChild(0);
    QString text="item->text(0)";
    if(!item)
    {
        QString text="null";
        text=text+";;;;";
    }
    text=text+";";
}

MyQtDemo::~MyQtDemo()
{
    delete ui;
}

void MyQtDemo::on_pushButton_clicked()
{
    QString filePth = QCoreApplication::applicationDirPath() + "/report";
    QString fileName = QFileDialog::getSaveFileName(this, tr("导出PDF文件"), filePth, "*.pdf");
    if (!fileName.isEmpty())
    {
        // 如果文件后缀为空，则默认使用.pdf
        if (QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".pdf");
        }

        ui->scrollArea->setFixedHeight(1000);
        int h=1000;
        int w=width();
        int num=h/(1.4*w)+1;
        qDebug()<<h<<" "<<w<<" "<<num;

        QPrinter *printer = new QPrinter(QPrinter::ScreenResolution);
        // 指定输出格式为pdf
        //    printer.setResolution(QPrinter::ScreenResolution);
        printer->setPageSize(QPrinter::A4);
        printer->setOutputFormat(QPrinter::PdfFormat);
        printer->setOutputFileName(fileName);
        printer->setWinPageSize(num);
        QPainter painter_pixmap(ui->scrollArea);

        for (int index = 0; index < num; index++)
        {
            QPixmap pixmap = ui->scrollArea->grab(QRect(0,1.4*w*index,w,1.4*w));
            //currentWidgetList << pixmap;

            painter_pixmap.begin(printer);
            QRect rect = painter_pixmap.viewport();
            painter_pixmap.scale(1, 1);

            painter_pixmap.drawPixmap(0, 0, rect.width(), rect.height(), pixmap);
            if (index < num-1)
            {
                printer->newPage();
            }
//            printer->newPage();

        }

        painter_pixmap.end();



        //    注意:如果要导出多张pdf，一定要将QPainter得对象实例化再循环外面，不然，只会导出最后一张，end()接口，放再循环外面，

        //    如果导出得pdf文档最后一页是空白页，一定要根据情况加上

//        if (index < ui.stackedWidget->count() - 1)
//        {
//            printer->newPage();
//        }
    }
}
