#ifndef STATUSWIDGET_H
#define STATUSWIDGET_H

#include <QWidget>
#include "ui_statuswidget.h"

class StatusWidget : public QWidget
{
	Q_OBJECT

public:
	StatusWidget(QWidget *parent = 0);
	~StatusWidget();

private:
	Ui::StatusWidget ui;

private:
	void paintEvent(QPaintEvent* event);
};

#endif // STATUSWIDGET_H
