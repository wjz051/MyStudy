#ifndef TREEMODEL_H
#define TREEMODEL_H

#include<QModelIndex>
#include<QAbstractItemModel>

#include"TreeModelItem.h"

struct TreeModelPrivate;

class TreeModel : public QAbstractItemModel
{
public:
    TreeModel();
    ~TreeModel();

public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;

    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    virtual QModelIndex index(int row,int column,const QModelIndex &parent=QModelIndex()) const;
    virtual QModelIndex parent(const QModelIndex &index) const;

    virtual Qt::ItemFlags flags(const QModelIndex &index) const;

public:
    void setTextColorable(bool TextColorable);
    void setBindable(bool Bindable);

    void setChildItemColor(const QModelIndex &index, const QVariant &value);
    void setParentItemColor(const QModelIndex &index, const QVariant &value);

public:
    void UpdateData(TreeModelItem *item);

private:
    TreeModelPrivate *_p;

};

#endif // TREEMODEL_H
