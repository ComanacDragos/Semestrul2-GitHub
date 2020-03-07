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
int storeProductService(ProductService* productService, char catalogueNumber[], char state[], char type[], char value[]);

/*
Removes from the repository a product with a given catalogue number
Returns 0 if the operation was succesful and 1 if the product does not exist
*/
int removeProductService(ProductService* productService, char catalogueNumber[]);

/*
Returns the product at the index i in repository
*/
Product* getProductFromRepository(ProductService* productService, int index);

/*
Updates the statem type and value of a product
*/
void updateProductService(ProductService* productService, char catalogueNumber[], char state[], char type[], char value[]);