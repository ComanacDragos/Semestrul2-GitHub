#include "TrenchCoatAdministrator.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QLabel l{ "Henlo" };
	l.show();
	return a.exec();
}
