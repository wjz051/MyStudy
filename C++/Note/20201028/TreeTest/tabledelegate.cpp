#include "tabledelegate.h"
#include <QtWidgets>
#include "settings.h"
#include "patheditor.h"

TableDelegate::TableDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

TableDelegate::~TableDelegate()
{

}

QModelIndex TableDelegate::sourceIndex(const QModelIndex &index) const
{
    auto proxyModel = qobject_cast<const QSortFilterProxyModel*>(index.model());
    if (!proxyModel) return QModelIndex();

    return proxyModel->mapToSource(index);
}

ItemProperty* TableDelegate::item(const QModelIndex &index) const
{
    auto row = index.row();

    Group* g = Q_NULLPTR;
    for (auto group: qSetting->groups()) {
        if (row < group->items.size()) {
            g = group;
            break;
        } else {
            row -= group->items.size();
        }
    }
    if (!g) return Q_NULLPTR;

    return g->items.value(row);
}

QWidget* TableDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)

    if (auto item = this->item(this->sourceIndex(index))) {
        switch(item->type) {
        case ItemProperty::TYPE_FONT:
        {
            auto box = new QFontComboBox(parent);
            box->setAutoFillBackground(true);
            return box;
        }
            break;
        case ItemProperty::TYPE_INTEGER:
        {
            auto spin = new QSpinBox(parent);
            spin->setRange(1, 10000);
            spin->setAutoFillBackground(true);
            return spin;
        }
            break;
        case ItemProperty::TYPE_LANGUAGE:
        {
            auto box = new QComboBox(parent);
            box->addItems({tr("Chinese"), tr("English"), tr("French")});
            box->setAutoFillBackground(true);
            return box;
        }
            break;
        case ItemProperty::TYPE_PATH:
        {
            auto edit = new PathEditor(parent);
            return edit;
        }
            break;
        }
    }

    return Q_NULLPTR;
}

void TableDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (auto item = this->item(this->sourceIndex(index))) {
        switch(item->type) {
        case ItemProperty::TYPE_LANGUAGE:
        {
            if (auto box = qobject_cast<QComboBox*>(editor)) {
                box->setCurrentText(index.data().toString());
            }
        }
            break;
        case ItemProperty::TYPE_FONT:
        {
            if (auto box = qobject_cast<QFontComboBox*>(editor)) {
                box->setCurrentFont(QFont(index.data().toString()));
            }
        }
            break;
        case ItemProperty::TYPE_INTEGER:
        {
            if (auto spin = qobject_cast<QSpinBox*>(editor)) {
                spin->setValue(index.data().toString().toInt());
            }
        }
            break;
        case ItemProperty::TYPE_PATH:
        {
            if (auto edit = qobject_cast<PathEditor*>(editor)) {
                edit->setPath(index.data().toString());
            }
        }
            break;
        }
    }
}

void TableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if (auto item = this->item(this->sourceIndex(index))) {
        switch(item->type) {
        case ItemProperty::TYPE_LANGUAGE:
        {
            if (auto box = qobject_cast<QComboBox*>(editor)) {
                model->setData(index, box->currentText(), Qt::EditRole);
            }
        }
            break;
        case ItemProperty::TYPE_FONT:
        {
            if (auto box = qobject_cast<QFontComboBox*>(editor)) {
                model->setData(index, box->currentFont(), Qt::EditRole);
            }
        }
            break;
        case ItemProperty::TYPE_INTEGER:
        {
            if (auto spin = qobject_cast<QSpinBox*>(editor)) {
                model->setData(index, spin->value(), Qt::EditRole);
            }
        }
            break;
        case ItemProperty::TYPE_PATH:
        {
            if (auto edit = qobject_cast<PathEditor*>(editor)) {
                model->setData(index, edit->path(), Qt::EditRole);
            }
        }
            break;
        }
    }
}

void TableDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index)
    editor->setGeometry(option.rect);
}

QSize TableDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    auto sz = QStyledItemDelegate::sizeHint(option, index);

    if (auto item = this->item(this->sourceIndex(index))) {
        if (item->type == ItemProperty::TYPE_PATH) {
            sz.setHeight(24);
        }
    }
    return sz;
}

