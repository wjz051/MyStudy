#include "treemodel.h"
#include <QtWidgets>
#include "settings.h"

class TreeModel::TreeModelPrivate
{
public:
};

TreeModel::TreeModel(QObject *parent)
    : QAbstractItemModel(parent), d(new TreeModelPrivate)
{

}

TreeModel::~TreeModel()
{

}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    auto ptr = reinterpret_cast<QObject*>(parent.internalPointer());
    if (auto group = qobject_cast<Group*>(ptr)) {
        return this->createIndex(row, column, group->items.value(row));
    } else if (!ptr) {
        return this->createIndex(row, column, qSetting->groups().value(row));
    }
    return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &child) const
{
    auto ptr = reinterpret_cast<QObject*>(child.internalPointer());
    if (auto item = qobject_cast<ItemProperty*>(ptr)) {
        if (auto group = qobject_cast<Group*>(item->parent())) {
            return this->createIndex(qSetting->groups().indexOf(group), 0, group);
        }
    }
    return QModelIndex();
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    auto ptr = reinterpret_cast<QObject*>(parent.internalPointer());
    if (auto group = qobject_cast<Group*>(ptr)) {
        return group->items.size();
    } else if (!ptr) {
        return 2;
    }
    return 0;
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    auto ptr = reinterpret_cast<QObject*>(parent.internalPointer());
    if (qobject_cast<Group*>(ptr)) {
        return 2;
    } else if (!ptr) {
        return 2;
    }
    return 0;
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    auto ptr = reinterpret_cast<QObject*>(index.internalPointer());

    auto col = index.column();

    if (auto group = qobject_cast<Group*>(ptr)) {
        if (col == 0 && role == Qt::DisplayRole) return group->name;
    } else if (auto item = qobject_cast<ItemProperty*>(ptr)) {
        if (col == 0 && role == Qt::DisplayRole) return item->name;
        if (col == 1 && role == Qt::DisplayRole) {
            if (item->type == ItemProperty::TYPE_INTEGER) {
                return QString::number(item->value.toInt());
            } else if (item->type == ItemProperty::TYPE_LANGUAGE) {
                return item->value;
            } else if (item->type == ItemProperty::TYPE_FONT) {
                auto font = item->value.value<QFont>();
                return font.family();
            } else if (item->type == ItemProperty::TYPE_PATH) {
                return QDir::toNativeSeparators(item->value.toString());
            }
        }
    }
    return QVariant();
}

bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole) return false;

    if (!index.isValid()) return false;

    auto ptr = reinterpret_cast<QObject*>(index.internalPointer());

    auto col = index.column();

    if (col == 0) return false;

    if (auto item = qobject_cast<ItemProperty*>(ptr)) {
        item->value = value;
        emit dataChanged(index, index, {Qt::DisplayRole});
        return true;
    }

    return false;
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags f = Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    auto ptr = reinterpret_cast<QObject*>(index.internalPointer());
    if (qobject_cast<ItemProperty*>(ptr)) {
        if (index.column() == 1) f |= Qt::ItemIsEditable;
    }
    return f;
}
