#include "GUI.h"
#include "tests.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>
int main(int argc, char *argv[])
{
	testAll();

	QApplication a(argc, argv);
	
	CSVFileRepository coatsRepository;
	CoatValidator* coatsValidator = new CoatValidator{};
	CoatService coatService{ coatsRepository, coatsValidator };

	GUI gui{coatService};
	gui.show();

	return a.exec();
}
