#include "ModelView.h"
#include "ui_ModelView.h"

ModelView::ModelView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelView)
{
    ui->setupUi(this);

    ui->comboBox->updateItems(QStringList());
}

ModelView::~ModelView()
{
    delete ui;
}
