#include "TreeModel.h"

Q_DECLARE_METATYPE(TreeModelDataPtr)

struct TreeModelPrivate
{
    TreeModelPrivate()
        :rootItem(new TreeModelItem(QSharedPointer<TreeModelData>(new TreeModelData))),Bindable(false),TextColorable(false){}
    TreeModelItem *rootItem;
    bool Bindable;
    bool TextColorable;
};

TreeModel::TreeModel()
{
    _p=new TreeModelPrivate;
}

TreeModel::~TreeModel()
{
    delete _p;
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    if(parent.column()>0) return 0;
    TreeModelItem *parentItem=parent.isValid()?static_cast<TreeModelItem*>(parent.internalPointer()):_p->rootItem;
    return parentItem->childCount();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid()?static_cast<TreeModelItem*>(parent.internalPointer())->colunmCount():_p->rootItem->colunmCount();
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();

    switch (role) {
    case Qt::DisplayRole:
        return static_cast<TreeModelItem *>(index.internalPointer())->data().value<TreeModelDataPtr>()->TreeData[index.column()];
        break;
    case Qt::UserRole:
        return QVariant::fromValue(static_cast<TreeModelItem *>(index.internalPointer())->data().value<TreeModelDataPtr>());
        break;
    case Qt::UserRole+1:
        return static_cast<TreeModelItem *>(index.internalPointer())->data().value<TreeModelDataPtr>()->ModelID;
        break;
    case Qt::ForegroundRole:
        if(_p->Bindable||_p->TextColorable)
        {
            return static_cast<TreeModelItem *>(index.internalPointer())->data().value<TreeModelDataPtr>()->TreeColor;
        }
        break;
    case Qt::BackgroundColorRole:
        if(index.row()%2!=0)
        {
            return QColor();
        }
        break;
    default:
        break;
    }
    return QVariant();
}

bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid()) return false;

    switch (role) {
    case Qt::ForegroundRole:
        if(_p->Bindable||_p->TextColorable)
        {
            static_cast<TreeModelItem *>(index.internalPointer())->data().value<TreeModelDataPtr>()->TreeColor=value.value<QColor>();
            emit dataChanged(this->index(index.row(),0,parent(index)),this->index(index.row(),_p->rootItem->colunmCount()-1,parent(index)));
            if(_p->Bindable)
            {
                setChildItemColor(index,value);
                setParentItemColor(index,value);
            }
            break;
        }
        break;
    default:
        break;
    }
    return true;
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation==Qt::Horizontal&&role==Qt::DisplayRole)
        return _p->rootItem->data().value<TreeModelDataPtr>()->TreeData[section];

    return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row,column,parent)) return QModelIndex();
    TreeModelItem *parentItem=parent.isValid()?static_cast<TreeModelItem *>(parent.internalPointer()):_p->rootItem;
    TreeModelItem *childItem=parentItem->child(row);
    return childItem?createIndex(row,column,childItem):QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if(!index.isValid()) return QModelIndex();
    TreeModelItem *childItem=static_cast<TreeModelItem *>(index.internalPointer());
    TreeModelItem *parentItem=childItem->parent();

    return parentItem==_p->rootItem?QModelIndex():createIndex(parentItem->row(),0,parentItem);
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    return index.isValid()?Qt::ItemIsEnabled|Qt::ItemIsSelectable:Qt::NoItemFlags;
}

void TreeModel::setTextColorable(bool TextColorable)
{
    _p->TextColorable=TextColorable;
}

void TreeModel::setBindable(bool Bindable)
{
    _p->Bindable=Bindable;
}

void TreeModel::setChildItemColor(const QModelIndex &index, const QVariant &value)
{
    if(rowCount(index)==0) return;

    for(int i=0,num=rowCount(index);i<num;++i)
    {
        //设置下级状态
        static_cast<TreeModelItem *>(index.internalPointer())->child(i)->data().value<TreeModelDataPtr>()->TreeColor=value.value<QColor>();
        emit dataChanged(this->index(i,0,index),this->index(i,_p->rootItem->childCount()-1,index));

        //递归设置下级状态
        setChildItemColor(this->index(i,0,index),value);

    }
}

void TreeModel::setParentItemColor(const QModelIndex &index, const QVariant &value)
{
    QModelIndex parentIndex=parent(index);
    if(!parentIndex.isValid()) return;

    int childCount=rowCount(parentIndex);
    for(int i=0;i<rowCount(parentIndex);++i)
    {
        if(static_cast<TreeModelItem *>(index.internalPointer())->child(i)->data().value<TreeModelDataPtr>()->TreeColor==value.value<QColor>())
        {
            childCount--;
        }
    }
    static_cast<TreeModelItem *>(index.internalPointer())->data().value<TreeModelDataPtr>()->TreeColor=childCount?Qt::blue:value.value<QColor>();
    emit dataChanged(this->index(parentIndex.row(),0,parent(parentIndex)),this->index(parentIndex.row(),_p->rootItem->childCount()-1,parent(parentIndex)));

    //递归设置父级状态
    setParentItemColor(parentIndex,value);

}

void TreeModel::UpdateData(TreeModelItem *item)
{
    _p->rootItem=item;
    //reset();
}
