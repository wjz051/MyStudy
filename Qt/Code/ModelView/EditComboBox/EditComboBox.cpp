#include"ComboBoxItem.h"
#include "EditComboBox.h"


EditComboBox::EditComboBox(QWidget *parent)
    :QComboBox(parent)
{
    m_listWidget=new QListWidget(this);

    m_lineEdit=new QLineEdit(this);
    setLineEdit(m_lineEdit);
    connect(m_lineEdit,SIGNAL(returnPressed()),this,SLOT(OnReturnPressed()));

    setEditable(true);
    setModel(m_listWidget->model());
    setView(m_listWidget);
}

EditComboBox::~EditComboBox()
{

}

int EditComboBox::FindItemIndex(const QString &text)
{
    int listCount=m_listWidget->count();
    for(int i=0;i<=listCount;++i)
    {
        QListWidgetItem *item=m_listWidget->item(i);
        if(ComboBoxItem *boxItem=dynamic_cast<ComboBoxItem *>(m_listWidget->itemWidget(item)))
        {
            if(boxItem->text()==text)
            {
                return i;
            }
        }
    }
    return -1;
}

void EditComboBox::SetText(const QString &text)
{
    m_text=text;
    setEditText(text);
}

QStringList EditComboBox::TextList()
{
    QStringList list;
    int listCount=m_listWidget->count();
    for(int i=0;i<listCount;++i)
    {
        QListWidgetItem *item=m_listWidget->item(i);
        if(ComboBoxItem *boxItem=dynamic_cast<ComboBoxItem *>(m_listWidget->itemWidget(item)))
        {
            list<<boxItem->text();
        }
    }
    return list;
}

void EditComboBox::CulTextNextCount(const QString &text, int &nextCount)
{
    QString compareText=text;
    if(nextCount!=0)
    {
        compareText+=QString::number(nextCount);
    }

    int listCount=m_listWidget->count();
    for(int i=0;i<listCount;++i)
    {
        QListWidgetItem *item=m_listWidget->item(i);
        if(ComboBoxItem *boxItem=dynamic_cast<ComboBoxItem *>(m_listWidget->itemWidget(item)))
        {
            if(boxItem->text()==compareText)
            {
                CulTextNextCount(text,++nextCount);
                break;
            }
        }
    }
}

void EditComboBox::updateItems(const QStringList &itemList)
{
    ComboBoxAddItem *addItem=new ComboBoxAddItem(this);
    connect(addItem,SIGNAL(addItem()),this,SLOT(OnAddItem()));

    QListWidgetItem *item=new QListWidgetItem(m_listWidget);
    m_listWidget->setItemWidget(item,addItem);

    for(int i=0;i<itemList.size();++i)
    {
        ComboBoxItem *itemWidget=new ComboBoxItem(itemList[i],this);
        connect(itemWidget,SIGNAL(chooseItem(const QString &)),this,SLOT(OnChooseItem(const QString &)));
        connect(itemWidget,SIGNAL(deleteItem(const QString &)),this,SLOT(OnDeleteItem(const QString &)));

        item=new QListWidgetItem;
        m_listWidget->insertItem(i,item);
        m_listWidget->setItemWidget(item,itemWidget);
    }

    if(itemList.size())
    {
        SetText(itemList[0]);
    }
}

void EditComboBox::OnChooseItem(const QString &str)
{
    SetText(str);
    hidePopup();
}

void EditComboBox::OnDeleteItem(const QString &str)
{
    int index=FindItemIndex(str);
    if(index!=-1)
    {
        QListWidgetItem *item=m_listWidget->takeItem(index);
        QWidget *widget=m_listWidget->itemWidget(item);
        delete widget;
        delete item;
    }
    SetText("");
    hidePopup();
    showPopup();
}

void EditComboBox::OnAddItem()
{
    int nextCount=0;
    CulTextNextCount("Input Text",nextCount);
    QString text=nextCount?QString("Input Text%1").arg(nextCount):"Input Text";

    ComboBoxItem *itemWidget=new ComboBoxItem(text,this);
    connect(itemWidget,SIGNAL(chooseItem(const QString &)),this,SLOT(OnChooseItem(const QString &)));
    connect(itemWidget,SIGNAL(deleteItem(const QString &)),this,SLOT(OnDeleteItem(const QString &)));

    QListWidgetItem *item=new QListWidgetItem;
    m_listWidget->insertItem(count()-1,item);
    m_listWidget->setItemWidget(item,itemWidget);

    SetText(text);

    hidePopup();
}

void EditComboBox::OnReturnPressed()
{
    QString lineText=m_lineEdit->text();

    if(lineText=="")
    {
        return;
    }

    removeItem(count()-1);
    int index=FindItemIndex(m_text);
    if(index!=-1)
    {
        ComboBoxItem *item=(ComboBoxItem *)m_listWidget->itemWidget(m_listWidget->item(index));
        item->setText(lineText);
        SetText(lineText);
    }
}
