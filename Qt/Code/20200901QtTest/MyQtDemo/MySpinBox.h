#ifndef MYSPINBOX_H
#define MYSPINBOX_H

#include <QSpinBox>

class MySpinBox : public QSpinBox
{
public:
    MySpinBox(QWidget *parent = 0);

public:
    void setValueTimes(int times);

protected:
    virtual int valueFromText(const QString &text) const;
    virtual QString textFromValue(int value) const;
private:
    int mTimes;
};

#endif // MYSPINBOX_H
