#include "service.h"

ProductService createService(ProductRepository* productRepository)
{
	return ProductService();
}

int storeProduct(ProductService* productService, int catalogueNumber, char state[], char type[], int value)
{
	return 0;
}

int removeProduct(ProductService* productService, int catalogueNumber)
{
	return 0;
}

Product getProductFromRepository(ProductService* productService, int index)
{
	return Product();
}
