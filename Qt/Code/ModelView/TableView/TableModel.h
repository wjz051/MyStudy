#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include<QModelIndex>
#include<QAbstractTableModel>

#include"DataType.h"



struct TableModelPrivate;
class TableModel : public QAbstractTableModel
{
public:
    TableModel(const QStringList &header_data,bool Checkable=false,QObject *parent=0);
    ~TableModel();

public:
    virtual int columnCount(const QModelIndex &parent) const;
    virtual int rowCount(const QModelIndex &parent) const;

    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    virtual Qt::ItemFlags flags(const QModelIndex &index) const;

    virtual bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    virtual bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

    virtual void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

public:
    void SetCheckable(bool Checkable);
    void SetHeaderColorable(bool HeaderColorable);
    void SetTextColorable(bool TextColorable);
    void SetEditable(bool Editable);

public:
    void UpdateData(const TableModelDataArray & tableData);

signals:
    void firstColumnChange();

private:
    TableModelPrivate *_p;
};

#endif // TABLEMODEL_H
