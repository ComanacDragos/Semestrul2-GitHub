#pragma once
#include "service.h"

typedef struct
{
	ProductService* productService;
}CommandBasedUI;

CommandBasedUI createUI(ProductService* productService);


void startProgram(CommandBasedUI* commandUI);

void storeProductUI(CommandBasedUI* commandUI, char** parameters, int numberOfParameters);

void removeProductUI(CommandBasedUI* commandUI, char** parameters, int numberOfParameters);

void listProductsUI(CommandBasedUI* commandUI, char** parameters, int numberOfParameters);

void updateProductUI(CommandBasedUI* commandUI, char** parameters, int numberOfParameters);