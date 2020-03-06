#pragma once
#include "repository.h"

typedef struct
{
	ProductRepository* productRepository;
}ProductService;

ProductService createService(ProductRepository* productRepository);

/*
Creates a product and adds it to the repository
Returns 0 if the operation was succesful and 1 if the product already exists in repository
*/
int storeProduct(ProductService* productService, int catalogueNumber, char state[], char type[], int value);

/*
Removes from the repository a product with a given catalogue number
Returns 0 if the operation was succesful and 1 if the product does not exist
*/
int removeProduct(ProductService* productService, int catalogueNumber);

/*
Returns the product at the index i in repository
*/
Product getProductFromRepository(ProductService* productService, int index);