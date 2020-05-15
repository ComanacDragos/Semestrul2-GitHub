#include "GUI.h"
#include "GraphicalUserInterface.h"
#include "tests.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>
int main(int argc, char *argv[])
{
	testAll();

	QApplication a(argc, argv);
	
	//GUI gui{};
	//gui.show();
	GraphicalUserInterface gui{};
	gui.show();

	return a.exec();
}
