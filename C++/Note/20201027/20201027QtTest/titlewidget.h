#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include "ui_titlewidget.h"

class TitleWidget : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(int fixSizeHeight READ fixSizeHeight WRITE setCusfixSizeHeight)

public:
	TitleWidget(QWidget *parent = 0);
	~TitleWidget();

public:
	void setCusfixSizeHeight(int height);
	int  fixSizeHeight();

private:
	Ui::TitleWidget ui;
};

#endif // TITLEWIDGET_H
