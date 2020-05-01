#include "TrenchCoatAdministrator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TrenchCoatAdministrator w;
	w.show();
	return a.exec();
}
