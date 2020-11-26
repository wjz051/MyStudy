#include "shrinkanimation.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ShrinkAnimation w;
	w.show();
	return a.exec();
}
