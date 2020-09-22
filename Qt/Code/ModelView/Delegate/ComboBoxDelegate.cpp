#include<QComboBox>
#include "ComboBoxDelegate.h"

ComboBoxDelegate::ComboBoxDelegate(const QStringList &dataList, QObject *parent)
    :QStyledItemDelegate(parent)
{
    _DataList=dataList;
}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *editor=new QComboBox(parent);
    editor->addItems(_DataList);

    return editor;
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value=index.model()->data(index,Qt::EditRole).toString();

    QComboBox *comboBox=static_cast<QComboBox *>(editor);
    comboBox->setCurrentIndex(comboBox->findText(value));
}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox=static_cast<QComboBox *>(editor);
    QString value=comboBox->currentText();
    QString oldStr=index.model()->data(index,Qt::EditRole).toString();

    if(oldStr!=value)
    {
        model->setData(index,value,Qt::EditRole);
        emit dataChange(value);
    }
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
