#include <crtdbg.h>
#include "tests.h"
#include "CommandUserInterface.h"

int main()
{

	{
		testAll();
		CSVFileRepository coatRepository;
		CoatValidator* coatsValidator = new CoatValidator;

		CoatService coatService{ coatRepository, coatsValidator };
		CommandUserInterface commandUserInterface{ coatService };
		commandUserInterface.startProgram();
	}
	_CrtDumpMemoryLeaks();

	return 0;
}