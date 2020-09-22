#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H

#include <QStyledItemDelegate>

class ComboBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    ComboBoxDelegate(const QStringList & dataList,QObject *parent=0);

public:
    //创建编辑器窗口
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,  const QModelIndex &index) const override;
    //设置编辑器数据
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    //设置Model数据
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    //更新编辑器大小
    void updateEditorGeometry(QWidget *editor,  const QStyleOptionViewItem &option, const QModelIndex &index) const override;

signals:
    void dataChange(QString data)const;

private:
    QStringList _DataList;
};

#endif // COMBOBOXDELEGATE_H
