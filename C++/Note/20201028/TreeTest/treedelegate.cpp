#include "treedelegate.h"
#include <QtWidgets>
#include "settings.h"
#include "patheditor.h"

TreeDelegate::TreeDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QWidget* TreeDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)

    auto ptr = reinterpret_cast<QObject*>(index.internalPointer());

    if (auto item = qobject_cast<ItemProperty*>(ptr)) {
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

void TreeDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    auto ptr = reinterpret_cast<QObject*>(index.internalPointer());

    if (auto item = qobject_cast<ItemProperty*>(ptr)) {
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

void TreeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    auto ptr = reinterpret_cast<QObject*>(index.internalPointer());

    if (auto item = qobject_cast<ItemProperty*>(ptr)) {
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

void TreeDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index)
    editor->setGeometry(option.rect);
}

QSize TreeDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    auto sz = QStyledItemDelegate::sizeHint(option, index);

    auto ptr = reinterpret_cast<QObject*>(index.internalPointer());
    if (auto item = qobject_cast<ItemProperty*>(ptr)) {
        if (item->type == ItemProperty::TYPE_PATH) {
            sz.setHeight(24);
        }
    }
    return sz;
}
