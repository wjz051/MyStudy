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

public slots:
    void on_pushButton_clicked();

private:
    Ui::MyQtDemo *ui;
};

#endif // MYQTDEMO_H
