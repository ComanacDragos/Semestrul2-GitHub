#include "service.h"


ProductService createService(ProductRepository* productRepository)
{
	ProductService productService;
	productService.productRepository = productRepository;
	return productService;
}

int storeProductService(ProductService* productService, char catalogueNumber[], char state[], char type[], char value[])
{
	Product newProduct = createProduct(atoi(catalogueNumber), state, type, atoi(value));

	return storeProduct(productService->productRepository, newProduct);
}

int removeProductService(ProductService* productService, char catalogueNumber[])
{
	return removeProduct(productService->productRepository, atoi(catalogueNumber));
}

Product getProductFromRepository(ProductService* productService, int index)
{
	return *getProduct(productService->productRepository, index);
}

void updateProductService(ProductService* productService, char catalogueNumber[], char state[], char type[], char value[])
{
	updateProduct(productService->productRepository, atoi(catalogueNumber), state, type, atoi(value));
}

int repositoryLengthService(ProductService* productService)
{
	return repositoryLength(productService->productRepository);
}

void destroyService(ProductService* productService)
{
	destroyRepository(productService->productRepository);
}
