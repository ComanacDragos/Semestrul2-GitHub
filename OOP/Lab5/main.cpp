#include <crtdbg.h>
#include "tests.h"

#include "DynamicVector.h"

int main()
{

	{

		testAll();
	}

	_CrtDumpMemoryLeaks();
	
	return 0;
}