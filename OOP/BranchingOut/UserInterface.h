#pragma once
#include "service.h"

typedef struct
{
	ProductService* productService;
}CommandBasedUI;

CommandBasedUI createUI(ProductService* productService);


void startProgram();

void storeProductUI();

void removeProductUI(char parameters[],int numberOfParameters);

void listProductsUI(char parameters[],int numberOfParameters);

void listProductsByType(char parameters[],int numberOfParameters);