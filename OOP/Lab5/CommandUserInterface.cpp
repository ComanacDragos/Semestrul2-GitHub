#include "CommandUserInterface.h"

CommandUserInterface::CommandUserInterface(const CoatService& coatService, const AdministratorUserInterface& administratorUserInterface)
{
	this->coatService = coatService;
	this->administratorUserInterface = administratorUserInterface;
}

CommandUserInterface::CommandUserInterface(const CommandUserInterface& commandUserInterface)
{
	this->administratorUserInterface = commandUserInterface.administratorUserInterface;
	this->coatService = commandUserInterface.coatService;
}

CommandUserInterface& CommandUserInterface::operator=(const CommandUserInterface& commandUserInterface)
{
	if (this == &commandUserInterface)
		return *this;
	this->coatService = commandUserInterface.coatService;
	this->administratorUserInterface = commandUserInterface.administratorUserInterface;
	return *this;
}

void CommandUserInterface::startProgram()
{
	while (1)
	{
		char userInput[CommandLenght];
		std::cout << "> ";

		std::cin.get(userInput, CommandLenght);

		if (strcmp(userInput, "exit") == 0)
			break;

		char* splitPointer = strtok(userInput, " ,");

		char** commandParameters = new char* [CommandLenght];

		int i = 0, numberOfParameters;

		while (splitPointer != NULL)
		{
			commandParameters[i] = new char[strlen(splitPointer) + 1];

			strcpy(commandParameters[i], splitPointer);
			splitPointer = strtok(NULL, " ,");
			i++;
		}
		numberOfParameters = i;
		char command[WordInCommandLenght];
		strcpy(command, commandParameters[0]);



		for (i = 0; i < numberOfParameters; i++)
			delete[] commandParameters[i];
		delete[] commandParameters;
	}
}
