#include "MyQtDemo.h"
#include "ui_MyQtDemo.h"

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
