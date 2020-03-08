#include "repository.h"

ProductRepository createProductRepository()
{
	ProductRepository productRepository;
	productRepository.capacity = 50;
	productRepository.length = 0;
	return productRepository;
}

int storeProduct(ProductRepository* productRepository, Product product)
{
	if (findProduct(productRepository, getCatalogueNumber(&product)) == -1)
	{
		productRepository->products[productRepository->length] = product;
		productRepository->length += 1;
		return 0;
	}
	return 1;
}

int removeProduct(ProductRepository* productRepository, int catalogueNumber)
{
	int productIndex = findProduct(productRepository, catalogueNumber);
	if(productIndex != -1)
	{
		int i;
		for (i = productIndex; i < productRepository->length; i++)
			productRepository->products[i] = productRepository->products[i + 1];
			productRepository->length -= 1;
			return 0;
	}
	return 1;
}

int findProduct(ProductRepository* productRepository, int catalogueNumber)
{
	int i;
	for(i=0; i<productRepository->length;i++)
		if(getCatalogueNumber(&productRepository->products[i]) == catalogueNumber)
			return i;
	return -1;
}

Product* getProduct(ProductRepository* productRepository, int index)
{
	if (index < 0 || index > productRepository->length)
		return NULL;

	return &productRepository->products[index];
}

void updateProduct(ProductRepository* productRepository, int catalogueNumber, char newState[], char newType[], int newValue)
{
	int index = findProduct(productRepository, catalogueNumber);
	Product* product = getProduct(productRepository, index);
	updateState(product, newState);
	updateType(product, newType);
	updateValue(product, newValue);
}

int repositoryLength(ProductRepository* productRepository)
{
	return productRepository->length;
}

