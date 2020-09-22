#include<QMouseEvent>
#include "ComboBoxItem.h"


ComboBoxItem::ComboBoxItem(const QString &str, QWidget *parent)
    :QWidget(parent)
{
    m_img=new QLabel("X",this);
    m_label=new QLabel(str,this);

    m_layout=new QHBoxLayout(this);
    m_layout->addWidget(m_label);
    m_layout->addStretch();
    m_layout->addWidget(m_img);

    m_layout->setSpacing(5);
    m_layout->setContentsMargins(5,1,5,1);

    setLayout(m_layout);

}

ComboBoxItem::~ComboBoxItem()
{
    delete m_img;
    delete m_label;
    delete m_layout;
}

void ComboBoxItem::setText(const QString &str)
{
    m_label->setText(str);
}

const QString ComboBoxItem::text()
{
    return m_label->text();
}

void ComboBoxItem::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint pos=event->pos();

    QWidget *widget=childAt(pos.x(),pos.y());
    if(QLabel *label=dynamic_cast<QLabel *>(widget))
    {
        if(label->text()=="X")
        {
            emit deleteItem(m_label->text());
            return;
        }
    }

    emit chooseItem(m_label->text());
}

ComboBoxAddItem::ComboBoxAddItem(QWidget *parent)
    :QWidget(parent)
{
    m_label=new QLabel("+",this);

    m_layout=new QHBoxLayout(this);
    m_layout->addStretch();
    m_layout->addWidget(m_label);
    m_layout->addStretch();

    m_layout->setSpacing(5);
    m_layout->setContentsMargins(5,1,5,1);

    setLayout(m_layout);

}

ComboBoxAddItem::~ComboBoxAddItem()
{
    delete m_label;
    delete m_layout;
}

void ComboBoxAddItem::mouseReleaseEvent(QMouseEvent *event)
{
    emit addItem();
}
