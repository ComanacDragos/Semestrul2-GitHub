#include "ClientUserInterface.h"

ClientUserInterface::ClientUserInterface(const CoatService& coatService)
{
	this->coatService = coatService;
}

ClientUserInterface::ClientUserInterface(const ClientUserInterface& clientUserInterface)
{
	this->coatService = clientUserInterface.coatService;
}

ClientUserInterface& ClientUserInterface::operator=(const ClientUserInterface& clientUserInterface)
{
	if (this == &clientUserInterface)
		return *this;
	this->coatService = clientUserInterface.coatService;
}

void ClientUserInterface::startClientUserInterface()
{
	while (1)
	{
		char userInput[CommandLenght];
		std::cout << "> ";

		std::cin.get(userInput, CommandLenght);
		std::cin.get();

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

		if (strcmp(command, "exit") == 0)
			return;


		for (i = 0; i < numberOfParameters; i++)
			delete[] commandParameters[i];
		delete[] commandParameters;
	}
}

