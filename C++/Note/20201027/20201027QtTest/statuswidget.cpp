#include "statuswidget.h"
#include <QPainter>
#include <QStyleOption>

StatusWidget::StatusWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

StatusWidget::~StatusWidget()
{

}

void StatusWidget::paintEvent(QPaintEvent* event)
{
	// ±³¾°Í¼
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}
