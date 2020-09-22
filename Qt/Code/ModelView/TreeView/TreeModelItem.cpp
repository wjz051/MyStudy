#include "TreeModelItem.h"

Q_DECLARE_METATYPE(TreeModelDataPtr)


struct TreeModelItemPrivate
{
    TreeModelItem *parentItem;
    TreeModelDataPtr itemData;
    QList<TreeModelItem *> childItems;
};

TreeModelItem::TreeModelItem(TreeModelDataPtr data, TreeModelItem *parent)
{
    _p=new TreeModelItemPrivate;
    _p->parentItem=parent;
    _p->itemData=data;
}

TreeModelItem::~TreeModelItem()
{
    qDeleteAll(_p->childItems);
    delete _p;
}

void TreeModelItem::appendChild(TreeModelItem *child)
{
    _p->childItems.append(child);
}

void TreeModelItem::removeChild(TreeModelItem *child)
{
    _p->childItems.removeOne(child);
}

int TreeModelItem::childCount() const
{
    return _p->childItems.count();
}

int TreeModelItem::colunmCount() const
{
    return _p->itemData->TreeData.size();
}

TreeModelItem *TreeModelItem::child(int row)
{
    return _p->childItems.value(row);
}

TreeModelItem *TreeModelItem::parent()
{
    return _p->parentItem;
}

int TreeModelItem::row() const
{
    return _p->parentItem?_p->parentItem->_p->childItems.indexOf(const_cast<TreeModelItem *>(this)):0;
}

QVariant TreeModelItem::data() const
{
    return QVariant::fromValue(_p->itemData);
}
