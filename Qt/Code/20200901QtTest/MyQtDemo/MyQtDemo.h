#ifndef MYQTDEMO_H
#define MYQTDEMO_H

#include <QWidget>

namespace Ui {
class MyQtDemo;
}

class MyQtDemo : public QWidget
{
    Q_OBJECT

public:
    explicit MyQtDemo(QWidget *parent = 0);
    ~MyQtDemo();

private:
    Ui::MyQtDemo *ui;
};

#endif // MYQTDEMO_H
