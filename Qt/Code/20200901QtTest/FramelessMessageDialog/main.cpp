#include "FramelessMessageDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FramelessMessageDialog w("1233","2233",QMessageBox::Ok|QMessageBox::Cancel);
    w.exec();

    return a.exec();
}
