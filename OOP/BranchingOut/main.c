#include <stdio.h>
#include <crtdbg.h>
#include "domain.h"
#include "tests.h"
int main()
{
	
	testAll();



	_CrtDumpMemoryLeaks();
	return 0;
}