#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
private:
    class MainWidgetPrivate;
    const QScopedPointer<MainWidgetPrivate> d;
};

#endif // MAINWIDGET_H
