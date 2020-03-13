#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "tests.h"
#include "domain.h"
#include "repository.h"
#include "service.h"

void testProduct()
{
	Product product = createProduct(123, "abc", "def", 456);
	assert(getCatalogueNumber(&product) == 123);
	assert(getValue(&product) == 456);
	assert(strcmp(getState(&product), "abc") == 0);
	assert(strcmp(getType(&product), "def") == 0);

	updateState(&product, "newState");
	updateType(&product, "newType");
	updateValue(&product, 999);

	assert(getValue(&product) == 999);
	assert(strcmp(getState(&product), "newState") == 0);
	assert(strcmp(getType(&product), "newType") == 0);
}

void testRepository()
{
	ProductRepository* productRepo = createProductRepository();
	Product product = createProduct(123, "abc", "def", 456);
	
	assert(storeProduct(productRepo, product) == 0);
	assert(productRepo->length == 1);

	assert(getCatalogueNumber(&productRepo->products[0]) == 123);
	assert(getValue(&productRepo->products[0]) == 456);
	assert(strcmp(getState(&productRepo->products[0]), "abc") == 0);
	assert(strcmp(getType(&productRepo->products[0]), "def") == 0);

	updateState(&productRepo->products[0], "newState");
	updateType(&productRepo->products[0], "newType");
	updateValue(&productRepo->products[0], 999);

	assert(getValue(&productRepo->products[0]) == 999);
	assert(strcmp(getState(&productRepo->products[0]), "newState") == 0);
	assert(strcmp(getType(&productRepo->products[0]), "newType") == 0);

	assert(getCatalogueNumber(getProduct(productRepo, 0)) == 123);
	assert(getValue(getProduct(productRepo, 0)) == 999);
	assert(strcmp(getState(getProduct(productRepo, 0)), "newState") == 0);
	assert(strcmp(getType(getProduct(productRepo, 0)), "newType") == 0);


	updateProduct(productRepo, 123, "abc", "def", 456);


	assert(getCatalogueNumber(&productRepo->products[0]) == 123);
	assert(getValue(&productRepo->products[0]) == 456);
	assert(strcmp(getState(&productRepo->products[0]), "abc") == 0);
	assert(strcmp(getType(&productRepo->products[0]), "def") == 0);


	assert(storeProduct(productRepo, product) == 1);

	assert(findProduct(productRepo, 123) == 0);
	
	assert(removeProduct(productRepo, 123)==0);

	assert(productRepo->length == 0);

	assert(removeProduct(productRepo, 123) == 1);


	storeProduct(productRepo, product);

	storeProduct(productRepo, createProduct(1,"asd","asd",4));

	storeProduct(productRepo, createProduct(2, "asd", "asd", 4));

	assert(productRepo->capacity == 4);

	removeProduct(productRepo, 2);

	assert(productRepo->capacity == 2);
	
	destroyRepository(productRepo);
}

void testService()
{
	ProductRepository* repo = createProductRepository();
	ProductService* service = createService(repo);
	
	assert(storeProductService(service, "123", "state", "type", "1") == 0);

	assert(storeProductService(service, "123", "state", "type", "1") == 1);
	Product product = getProductFromRepository(service, 0);

	assert(getCatalogueNumber(&product) == 123);
	assert(getValue(&product) == 1);
	assert(strcmp(getState(&product), "state") == 0);
	assert(strcmp(getType(&product), "type") == 0);

	updateProductService(service, "123", "newState", "newType", "5");

	product = getProductFromRepository(service, 0);

	assert(getCatalogueNumber(&product) == 123);
	assert(getValue(&product) == 5);
	assert(strcmp(getState(&product), "newState") == 0);
	assert(strcmp(getType(&product), "newType") == 0);
	
	assert(removeProductService(service, "123")==0);
	assert(removeProductService(service, "123") == 1);
	
	assert(findProduct(service->productRepository, 123) == -1);

	assert(storeProductService(service, "123", "state", "b", "1") == 0);
	assert(storeProductService(service, "124", "state", "a", "1") == 0);

	ProductRepository* filteredProducts = listMaximumPotencyValueService(service, "3");

	assert(getCatalogueNumber(getProduct(filteredProducts, 0)) == 124);
	assert(getValue(getProduct(filteredProducts, 0)) == 1);
	assert(strcmp(getState(getProduct(filteredProducts, 0)), "state") == 0);
	assert(strcmp(getType(getProduct(filteredProducts, 0)), "a") == 0);

	assert(getCatalogueNumber(getProduct(filteredProducts, 1)) == 123);
	assert(getValue(getProduct(filteredProducts, 1)) == 1);
	assert(strcmp(getState(getProduct(filteredProducts, 1)), "state") == 0);
	assert(strcmp(getType(getProduct(filteredProducts, 1)), "b") == 0);

	destroyRepository(filteredProducts);

	destroyService(service);
}

void testAll()
{
	testProduct();
	testRepository();
	testService();
	printf("\nThe tests were succesfull!\n");
}
