#include "mainwidget.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto localeName = QLocale::system().name();

    QTranslator qtTranslator;
    qtTranslator.load(QStringLiteral(":/qt_%1").arg(localeName));
    a.installTranslator(&qtTranslator);

    QTranslator appTranslator;
    appTranslator.load(QStringLiteral(":/%1").arg(localeName));
    a.installTranslator(&appTranslator);

    MainWidget w;
    w.show();

    return a.exec();
}
