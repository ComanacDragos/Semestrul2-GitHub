#include "UserInterface.h"
#include <string.h>
#include <stdio.h>

CommandBasedUI createUI(ProductService* productService)
{
	CommandBasedUI commandBasedUI;
	commandBasedUI.productService = productService;
	return commandBasedUI;
}

void startProgram()
{
	char* commands[5];
	commands[0] = "add";
	commands[1] = "update";
	commands[2] = "delete";
	commands[3] = "list";

	while (1)
	{
		char userInput[50];
		gets(userInput);
		
		if (strcmp(userInput, "exit") == 0)
			break;

		char parameters[20][20], * splitPointer = strtok(userInput, " ");
		int i = 0, numberOfParameters;
		while (splitPointer != NULL)
		{
			strcpy(parameters[i], splitPointer);
			splitPointer = strtok(NULL, " ");
			
			i++;
		}
		
		numberOfParameters = i;
		for (i = 0; i < numberOfParameters; i++)
			printf("%s\n", parameters[i]);
	
	
	}
}

void storeProductUI()
{
}

void removeProductUI(char parameters[], int numberOfParameters)
{
}

void listProductsUI(char parameters[],int numberOfParameters)
{
}

void listProductsByType(char parameters[],int numberOfParameters)
{
}
