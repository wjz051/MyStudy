#include "tablemodel.h"
#include <QtWidgets>
#include "settings.h"

class TableModel::TableModelPrivate
{
public:
};

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent), d(new TableModelPrivate)
{

}

TableModel::~TableModel()
{

}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    int res = 0;
    for (auto group: qSetting->groups()) {
        res += group->items.size();
    }
    return res;
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return 2;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    auto row = index.row();
    auto col = index.column();

    if (role == Qt::DisplayRole) {
        Group* g = Q_NULLPTR;
        for (auto group : qSetting->groups()) {
            if (row < group->items.size()) {
                g = group;
                break;
            } else {
                row -= group->items.size();
            }
        }
        if (g) {
            if (auto item = g->items.value(row)) {
                if (col == 0) {
                    return item->name;
                } else if (col == 1) {
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
        }
    }
    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole) return false;

    auto row = index.row();
    auto col = index.column();

    if (col == 0) return false;

    Group* g = Q_NULLPTR;
    for (auto group : qSetting->groups()) {
        if (row < group->items.size()) {
            g = group;
            break;
        } else {
            row -= group->items.size();
        }
    }
    if (g) {
        if (auto item = g->items.value(row)) {
            item->value = value;
            emit dataChanged(index, index, {Qt::DisplayRole});
            return true;
        }
    }

    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags f = Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    if (index.column() == 1) {
        f |= Qt::ItemIsEditable;
    }
    return f;
}
