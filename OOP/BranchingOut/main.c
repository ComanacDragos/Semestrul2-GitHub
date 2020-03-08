#include <stdio.h>
#include <crtdbg.h>
#include "domain.h"
#include "repository.h"
#include "service.h"
#include "tests.h"
#include "UserInterface.h"

#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[60];
	struct Nod* next;
}Nod;


int main()
{
	
	testAll();
	

	ProductRepository productRepository = createProductRepository();
	ProductService productService = createService(&productRepository);
	CommandBasedUI commandBasedUI = createUI(&productService);

	startProgram(&commandBasedUI);
	/*
	char** m = '\0';
	char a[4] = "abc", b[4] = "def";
	m = (char**)malloc(2 * sizeof(char*));
	int i;
	for (i= 0; i < 2; i++)
		m[i] = (char*)malloc(sizeof(char) * 4);
	
	strcpy(m[0], a); // m[0] = *(m+0)
	strcpy(m[1], b);
	f(m);
	*/
	_CrtDumpMemoryLeaks();
	return 0;
}