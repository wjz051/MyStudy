#include <QApplication>
#include "TcTableWidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TcTableWidget w;
    w.show();

    return a.exec();
}
