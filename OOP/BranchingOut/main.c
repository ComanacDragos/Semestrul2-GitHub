#include <stdio.h>
#include <crtdbg.h>
#include "domain.h"
#include "repository.h"
#include "service.h"
#include "tests.h"
#include "UserInterface.h"


typedef struct {
	char name[60];
	struct Nod* next;
}Nod;

int main()
{
	
	testAll();
	
	startProgram();
	_CrtDumpMemoryLeaks();
	return 0;
}