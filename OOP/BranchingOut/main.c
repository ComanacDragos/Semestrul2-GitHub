#include <stdio.h>
#include <crtdbg.h>
#include "domain.h"
#include "repository.h"
#include "service.h"
#include "tests.h"
#include "UserInterface.h"

int main()
{
	//testAll();
	
	ProductRepository* productRepository = createProductRepository();
	//ProductService productService = createService(&productRepository);
	//CommandBasedUI commandBasedUI = createUI(&productService);
	//storeProduct(&productRepository, createProduct(3, "as", "asd", 4));
	
	//startProgram(&commandBasedUI);

	//destroyUserInterface(&commandBasedUI);
	destroyRepository(productRepository);
	//free(productRepository.products);

	
	_CrtDumpMemoryLeaks();
	return 0;
}