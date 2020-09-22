#include "MySpinBox.h"
#include<QMessageBox>

MySpinBox::MySpinBox(QWidget *parent)
    :QSpinBox(parent),mTimes(1)
{

}
/**
 * @brief HtSpinBox::setValueTimes设置spinBox显示的倍数
 * @param times
 */
void MySpinBox::setValueTimes(int times)
{
    if(times>1)
    {
        mTimes=times;
        setSingleStep(times);
    }
}

int MySpinBox::valueFromText(const QString &text) const
{
    if(mTimes!=1)
    {
        int tmp=(text.toInt()/mTimes)*mTimes;
        return tmp?tmp:minimum();
    }
    return text.toInt();
}

QString MySpinBox::textFromValue(int value) const
{
    if(value%mTimes!=0)
    {
        int tmp=(value/mTimes)*mTimes;
        return tr("%1").arg(tmp?tmp:minimum());
    }
    return tr("%1").arg(value);
}
