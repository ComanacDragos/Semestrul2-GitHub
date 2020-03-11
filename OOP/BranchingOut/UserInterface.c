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
#define CommandLenght 50


//the maximum length in a word in a command
#define WordInCommandLenght 50

void startProgram(CommandBasedUI* commandUI)
{
	while (1)
	{
		char userInput[CommandLenght];
		userInput[0] = '\0';
		printf("> ");
		gets(userInput);
		
		if (strcmp(userInput, "exit") == 0)
			break;

		char* splitPointer = strtok(userInput, " ,");
		
		char** commandParameters = (char**)malloc(sizeof(char*) * CommandLenght);
		
		if (commandParameters == '\0')
		{
			printf("something went wrong");
			return;
		}
		int i=0, numberOfParameters;
		
		while (splitPointer != NULL)
		{
			commandParameters[i] = (char*)malloc(sizeof(char) * (strlen(splitPointer) + 1));

			if (commandParameters[i] == '\0')
			{
				printf("something went wrong");
				return;
			}

			strcpy(commandParameters[i], splitPointer);
			splitPointer = strtok(NULL, " ,");
			i++;
		}
		numberOfParameters = i;
		
		if (strcmp(commandParameters[0], "add") == 0)
			storeProductUI(commandUI, commandParameters, numberOfParameters);
		
		if (strcmp(commandParameters[0], "list") == 0)
			listProductsUI(commandUI, commandParameters, numberOfParameters);

		if (strcmp(commandParameters[0], "delete") == 0)
			removeProductUI(commandUI, commandParameters, numberOfParameters);

		if (strcmp(commandParameters[0], "update") == 0)
			updateProductUI(commandUI, commandParameters, numberOfParameters);

		for (i = 0; i < numberOfParameters; i++)
			free(commandParameters[i]);
		free(commandParameters);
	}
}

void storeProductUI(CommandBasedUI* commandUI, char** parameters, int numberOfParameters)
{
	if (numberOfParameters != 5) 
	{
		printf("Bad command\n");
		return;
	}

	char catalogueNumber[WordInCommandLenght], state[WordInCommandLenght], type[WordInCommandLenght], value[WordInCommandLenght];
	strcpy(catalogueNumber, parameters[1]);
	strcpy(state, parameters[2]);
	strcpy(type, parameters[3]);
	strcpy(value, parameters[4]);

	int succes = storeProductService(commandUI->productService, catalogueNumber, state, type, value);
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

	char catalogueNumber[WordInCommandLenght];
	strcpy(catalogueNumber, parameters[1]);

	int succes = removeProductService(commandUI->productService, catalogueNumber);
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
	char catalogueNumber[WordInCommandLenght], state[WordInCommandLenght], type[WordInCommandLenght], value[WordInCommandLenght];
	strcpy(catalogueNumber, parameters[1]);
	strcpy(state, parameters[2]);
	strcpy(type, parameters[3]);
	strcpy(value, parameters[4]);
	updateProductService(commandUI->productService, catalogueNumber, state, type, value);
	printf("The product was updated succesfully\n");
}

destroyUserInterface(CommandBasedUI* commandUI)
{
	destroyService(commandUI->productService);
}

