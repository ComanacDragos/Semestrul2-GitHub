#include "UserInterface.h"
#include <string.h>
#include <stdio.h>

CommandBasedUI createUI(ProductService* productService)
{
	CommandBasedUI commandBasedUI;
	commandBasedUI.productService = productService;
	return commandBasedUI;
}

//the maximum lenght of a command
#define CommandLenght 20

#define WordInCommandLenght 20
//the maximum length in a word in a command

void startProgram(CommandBasedUI* commandUI)
{
	while (1)
	{
		char userInput[100];
		userInput[0] = '\0';
		printf("> ");
		gets(userInput);
		
		if (strcmp(userInput, "exit") == 0)
			break;

		char* splitPointer = strtok(userInput, " ,");
		
		char** parameters = (char**)malloc(sizeof(char*) * CommandLenght);

		if (parameters == '\0')
		{
			printf("something went wrong");
			return;
		}
		int i=0, numberOfParameters;
		
		while (splitPointer != NULL)
		{
			parameters[i] = (char*)malloc(sizeof(char) * (strlen(splitPointer) + 1));

			if (parameters[i] == '\0')
			{
				printf("something went wrong");
				return;
			}

			strcpy(parameters[i], splitPointer);
			splitPointer = strtok(NULL, " ,");
			i++;
		}
		numberOfParameters = i;
		
		if (strcmp(parameters[0], "add") == 0)
			storeProductUI(commandUI, parameters, numberOfParameters);
		
		if (strcmp(parameters[0], "list") == 0)
			listProductsUI(commandUI, parameters, numberOfParameters);

		if (strcmp(parameters[0], "delete") == 0)
			removeProductUI(commandUI, parameters, numberOfParameters);

		if (strcmp(parameters[0], "update") == 0)
			updateProductUI(commandUI, parameters, numberOfParameters);

		for (i = 0; i < numberOfParameters; i++)
			free(parameters[i]);
		free(parameters);
	}
}

void storeProductUI(CommandBasedUI* commandUI, char** parameters, int numberOfParameters)
{
	if (numberOfParameters != 5) 
	{
		printf("Bad command\n");
		return;
	}

	int succes = storeProductService(commandUI->productService, parameters[1], parameters[2], parameters[3], parameters[4]);
	if (succes == 0)
		printf("The product was succesfully stored\n");
	else
		printf("No!\n");
}

void removeProductUI(CommandBasedUI* commandUI, char** parameters, int numberOfParameters)
{
	if (numberOfParameters != 2)
	{
		printf("bad command\n");
		return;
	}

	int succes = removeProductService(commandUI->productService, parameters[1]);
	if (succes == 0)
		printf("The product was succesfully removed\n");
	else
		printf("No!\n");
}

void listProductsUI(CommandBasedUI* commandUI, char** parameters,int numberOfParameters)
{
	if (numberOfParameters == 1)
	{	
		int i, numberOfProducts = repositoryLengthService(commandUI->productService);

		for (i = 0; i <numberOfProducts; i++)
		{ 
			Product product = getProductFromRepository(commandUI->productService, i);
			printProduct(&product);
		}
	}
	else
		if (numberOfParameters == 2)
		{
			int i, numberOfProducts = repositoryLengthService(commandUI->productService);
			for (i = 0; i < numberOfProducts; i++)
			{
				Product product = getProductFromRepository(commandUI->productService, i);
				if(strcmp(parameters[1], getType(&product)) == 0)
					printProduct(&product);
			}
		}
}

void updateProductUI(CommandBasedUI* commandUI, char** parameters, int numberOfParameters)
{
	if (numberOfParameters != 5)
	{
		printf("Bad command\n");
		return;
	}
	updateProductService(commandUI->productService, parameters[1], parameters[2], parameters[3], parameters[4]);
	printf("The product was updated succesfully\n");
}

