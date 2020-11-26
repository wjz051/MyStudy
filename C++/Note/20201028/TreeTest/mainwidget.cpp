#include "mainwidget.h"
#include <QtWidgets>
#include "settings.h"
#include "treemodel.h"
#include "tablemodel.h"
#include "treedelegate.h"
#include "tabledelegate.h"

class MainWidget::MainWidgetPrivate
{
public:
    QStackedWidget* stack = Q_NULLPTR;
    QToolButton* expandBtn = Q_NULLPTR;
    QToolButton* collpaseBtn = Q_NULLPTR;
    QToolButton* sortAscendBtn = Q_NULLPTR;
    QToolButton* sortDescendBtn = Q_NULLPTR;

    QTreeView* tree = Q_NULLPTR;
    QTableView* table = Q_NULLPTR;
};

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent), d(new MainWidgetPrivate)
{
    setWindowTitle(tr("Test Program"));
    setWindowIcon(QIcon(":/tree.ico"));

    auto layout = new QVBoxLayout(this);
    layout->addWidget(d->stack = new QStackedWidget);
    layout->addLayout([this] {
       auto layout = new QHBoxLayout;
       layout->addWidget(d->expandBtn = new QToolButton);
       layout->addWidget(d->collpaseBtn = new QToolButton);
       layout->addWidget(d->sortAscendBtn = new QToolButton);
       layout->addWidget(d->sortDescendBtn = new QToolButton);
       layout->addStretch(1);
       return layout;
    }());

    d->expandBtn->setIcon(QIcon(":/images/expand.png"));
    d->collpaseBtn->setIcon(QIcon(":/images/collpase.png"));
    d->sortAscendBtn->setIcon(QIcon(":/images/sortascend.png"));
    d->sortDescendBtn->setIcon(QIcon(":/images/sortdescend.png"));
    d->expandBtn->setIconSize({24, 24});
    d->collpaseBtn->setIconSize({24, 24});
    d->sortAscendBtn->setIconSize({24, 24});
    d->sortDescendBtn->setIconSize({24, 24});

    d->stack->addWidget(d->tree = new QTreeView);
    d->stack->addWidget(d->table = new QTableView);

    d->tree->setModel(new TreeModel(this));
    d->tree->setAnimated(true);
    d->tree->header()->hide();
    d->tree->header()->setSectionResizeMode(QHeaderView::Fixed);
    d->tree->header()->setDefaultSectionSize(220);
    d->tree->header()->setStretchLastSection(true);
    d->tree->expandAll();
    d->tree->setItemDelegateForColumn(1, new TreeDelegate(this));
    d->tree->setEditTriggers(QTreeView::AllEditTriggers);

    auto tableModel = new TableModel(this);
    auto proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(tableModel);
    d->table->setModel(proxyModel);
    d->table->horizontalHeader()->hide();
    d->table->verticalHeader()->hide();
    d->table->setSortingEnabled(true);
    d->table->sortByColumn(0, Qt::AscendingOrder);
    d->table->horizontalHeader()->setDefaultSectionSize(220);
    d->table->horizontalHeader()->setStretchLastSection(true);
    d->table->setSelectionBehavior(QTableView::SelectRows);
    d->table->setItemDelegateForColumn(1, new TableDelegate(this));
    d->table->setEditTriggers(QTableView::AllEditTriggers);

    this->resize(800, 600);

    connect(d->expandBtn, &QToolButton::clicked, this, [this] {
        d->stack->setCurrentIndex(0);
        d->tree->expandAll();
    });
    connect(d->collpaseBtn, &QToolButton::clicked, this, [this] {
        d->stack->setCurrentIndex(0);
        d->tree->collapseAll();
    });
    connect(d->sortAscendBtn, &QToolButton::clicked, this, [this] {
        d->stack->setCurrentIndex(1);
        d->table->sortByColumn(0, Qt::AscendingOrder);
    });
    connect(d->sortDescendBtn, &QToolButton::clicked, this, [this] {
        d->stack->setCurrentIndex(1);
        d->table->sortByColumn(0, Qt::DescendingOrder);
    });
}

MainWidget::~MainWidget()
{

}
