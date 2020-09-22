#include<QMessageBox>

#include "TableModel.h"

Q_DECLARE_METATYPE(TableModelDataPtr)

struct TableModelPrivate
{
    TableModelPrivate()
        :Checkable(false),HeaderColorable(false),TextColorable(false),Editable(false){}

    TableModelDataArray table_data;
    QStringList header_data;
    bool Checkable;
    bool HeaderColorable;
    bool TextColorable;
    bool Editable;
};

TableModel::TableModel(const QStringList &header_data, bool Checkable, QObject *parent)
    :QAbstractTableModel(parent)
{
    _p=new TableModelPrivate;
    _p->header_data=header_data;
    _p->Checkable=Checkable;
}

TableModel::~TableModel()
{
    delete _p;
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    return _p->header_data.size();
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    return _p->table_data.size();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    switch(role)
    {
    case Qt::DisplayRole:
        return _p->table_data[index.row()]->TableData[index.column()];
    case Qt::UserRole:
        return _p->table_data[index.row()]->TablePoint;
    case Qt::EditRole://编辑显示信息
        return _p->table_data[index.row()]->TableData[index.column()];
    case Qt::ToolTipRole://提示信息
        return _p->table_data[index.row()]->TableData[index.column()];
    case Qt::DecorationRole://Table前面颜色块
        if(_p->HeaderColorable)
        {
            return _p->table_data[index.row()]->TableColor;
        }
        break;
    case Qt::ForegroundRole://Table文字颜色
        if(_p->TextColorable)
        {
            return _p->table_data[index.row()]->TextColor;
        }
        break;
    case Qt::CheckStateRole://选择框
        if(_p->Checkable&&index.column()==0)
        {
            return 0?Qt::Checked:Qt::Unchecked;
        }
        break;
    case Qt::BackgroundColorRole://背景色
        if(index.row()%2!=0)
        {
            //return QColor(RGB(227,238,229));
        }
        break;
     default:
        break;
    }
    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid()) return false;
    switch (role)
    {
    case Qt::EditRole:
        if(_p->Editable)
        {
            _p->table_data[index.row()]->TableData[index.column()]=value.toString();

            emit dataChanged(this->index(index.row(),0),this->index(index.row(),_p->header_data.size()-1));
        }
        break;
    case Qt::ForegroundRole:
        if(_p->TextColorable)
        {
            _p->table_data[index.row()]->TextColor=value.value<QColor>();
            emit dataChanged(this->index(index.row(),0),this->index(index.row(),_p->header_data.size()-1));
        }
    case Qt::CheckStateRole:
        if(_p->Checkable&&index.column()==0)
        {

        }
        break;
    default:
        break;
    }
    return true;
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole&&orientation==Qt::Horizontal)
    {
        if(section<_p->header_data.size())
        {
            return _p->header_data[section];
        }
    }
    return QVariant();
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if(index.column()==0&&_p->Editable)
    {
        return Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled|Qt::ItemIsEditable;
    }
    return Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled;
}

bool TableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    if(count<1||row<0||row>rowCount(parent))
    {
        return false;
    }

    beginInsertRows(QModelIndex(),row,row+count-1);
    for(int i=0;i<count;++i)
    {
        TableModelDataPtr data=QSharedPointer<TableModelData>(new TableModelData);
        _p->table_data.push_back(data);
    }
    endInsertRows();
    return true;

}

bool TableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(count<1||row<0||(row+count)>rowCount(parent))
    {
        return false;
    }
    beginRemoveRows(QModelIndex(),row,row+count-1);
    for(int i=0;i<count;++i)
    {
        _p->table_data.erase(_p->table_data.begin()+row);
    }
    endRemoveRows();
    return true;
}

void TableModel::sort(int column, Qt::SortOrder order)
{
    //排序算法

    //reset();
}

void TableModel::SetCheckable(bool Checkable)
{
    _p->Checkable=Checkable;
}

void TableModel::SetHeaderColorable(bool HeaderColorable)
{
    _p->HeaderColorable=HeaderColorable;
}

void TableModel::SetTextColorable(bool TextColorable)
{
    _p->TextColorable=TextColorable;
}

void TableModel::SetEditable(bool Editable)
{
    _p->Editable=Editable;
}

void TableModel::UpdateData(const TableModelDataArray &tableData)
{
    beginResetModel();
    _p->table_data=tableData;
    endResetModel();
}
