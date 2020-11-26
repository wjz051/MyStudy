#ifndef SHRINKANIMATION_H
#define SHRINKANIMATION_H

#include <QtWidgets/QWidget>
#include "ui_shrinkanimation.h"

class ShrinkAnimation : public QWidget
{
	Q_OBJECT

public:
	ShrinkAnimation(QWidget *parent = 0);
	~ShrinkAnimation();

private:
	void initControl();
	void resizeEvent(QResizeEvent *);

private:
	Ui::ShrinkAnimationClass ui;
};

#endif // SHRINKANIMATION_H
