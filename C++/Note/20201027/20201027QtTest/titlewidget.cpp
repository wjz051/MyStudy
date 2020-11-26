#include "titlewidget.h"

TitleWidget::TitleWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

TitleWidget::~TitleWidget()
{

}

void TitleWidget::setCusfixSizeHeight(int height)
{
	this->setFixedHeight(height);
}

int TitleWidget::fixSizeHeight()
{
	return this->height();
}
