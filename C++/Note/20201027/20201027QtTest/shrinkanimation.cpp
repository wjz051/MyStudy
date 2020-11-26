#include "shrinkanimation.h"
#include "statuswidget.h"

#include <QPropertyAnimation>
#include <QPushButton>

ShrinkAnimation::ShrinkAnimation(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initControl();
}

ShrinkAnimation::~ShrinkAnimation()
{

}

void ShrinkAnimation::initControl()
{
	ui.titleWidget->setFixedWidth(this->width());
	StatusWidget* pWidget = new StatusWidget(ui.upWidget);
	pWidget->setFixedSize(this->width(), 48);
	pWidget->move(0, ui.titleWidget->height());

	connect(ui.pushButton, &QPushButton::clicked, [this, pWidget](){
		QPropertyAnimation *animation = new QPropertyAnimation(ui.upWidget, "fixSizeHeight");
		animation->setDuration(500);
		animation->setEasingCurve(QEasingCurve::InQuad);
		if (ui.upWidget->height() > 32)
		{
			animation->setEndValue(32);
		}
		else
		{
			animation->setEndValue(pWidget->height() + 32);
		}
		animation->start(QAbstractAnimation::DeleteWhenStopped);
	});
}

void ShrinkAnimation::resizeEvent(QResizeEvent *)
{
	ui.titleWidget->setFixedWidth(this->width());
	ui.pushButton->move(this->width() - ui.pushButton->width(), 0);
}
