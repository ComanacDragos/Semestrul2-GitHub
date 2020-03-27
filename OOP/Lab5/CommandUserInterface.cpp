#include "CommandUserInterface.h"

CommandUserInterface::CommandUserInterface(const CoatService& coatService)
{
	this->coatService = coatService;


	this->administratorUserInterface = AdministratorUserInterface(this->coatService);
	this->clientUserInterface = ClientUserInterface(this->coatService);

	this->initializeRepository();
}

CommandUserInterface::CommandUserInterface(const CommandUserInterface& commandUserInterface)
{
	this->coatService = commandUserInterface.coatService;
	this->administratorUserInterface = commandUserInterface.administratorUserInterface;
	this->clientUserInterface = commandUserInterface.clientUserInterface;
}

CommandUserInterface& CommandUserInterface::operator=(const CommandUserInterface& commandUserInterface)
{
	if (this == &commandUserInterface)
		return *this;
	this->coatService = commandUserInterface.coatService;
	this->administratorUserInterface = commandUserInterface.administratorUserInterface;
	this->clientUserInterface = commandUserInterface.clientUserInterface;
	return *this;
}

void CommandUserInterface::startProgram()
{
	int isRunning = -1;
	while (isRunning == -1)
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

		if (numberOfParameters == 2)
		{
			
			if(strcmp(command, "mode") == 0 && strcmp(commandParameters[1], "A") == 0)
			{
				isRunning = AdministratorMode;
			}

			if (strcmp(command, "mode") == 0 && strcmp(commandParameters[1], "B") == 0)
			{
				isRunning = ClientMode;
			}
		}

		while(isRunning == AdministratorMode || isRunning == ClientMode)
		{
			if(isRunning == AdministratorMode)
			{
				isRunning = this->administratorUserInterface.startAdministratorMode();
			}

			if(isRunning == ClientMode)
			{
				isRunning = this->clientUserInterface.startClientUserInterface();
			}
		}

		for (i = 0; i < numberOfParameters; i++)
			delete[] commandParameters[i];
		delete[] commandParameters;
	}
}

void CommandUserInterface::initializeRepository()
{
	this->coatService.storeCoatService("coat1", "S", "https://m.media-amazon.com/images/I/515R11jmKQL._SR500,500_.jpg", "100");
	this->coatService.storeCoatService("coat2", "M", "https://m.media-amazon.com/images/I/515R11jmKQL._SR500,500_.jpg", "150");
	this->coatService.storeCoatService("coat3", "L", "https://m.media-amazon.com/images/I/515R11jmKQL._SR500,500_.jpg", "120");
	this->coatService.storeCoatService("coat4", "XL", "https://m.media-amazon.com/images/I/515R11jmKQL._SR500,500_.jpg", "130");
	this->coatService.storeCoatService("coat5", "XXL", "https://m.media-amazon.com/images/I/515R11jmKQL._SR500,500_.jpg", "200");
	this->coatService.storeCoatService("coat6", "S", "https://m.media-amazon.com/images/I/515R11jmKQL._SR500,500_.jpg", "130");
	this->coatService.storeCoatService("coat7", "M", "https://m.media-amazon.com/images/I/515R11jmKQL._SR500,500_.jpg", "120");
	this->coatService.storeCoatService("coat8", "L", "https://m.media-amazon.com/images/I/515R11jmKQL._SR500,500_.jpg", "100");
	this->coatService.storeCoatService("coat9", "XL", "https://m.media-amazon.com/images/I/515R11jmKQL._SR500,500_.jpg", "100");
	this->coatService.storeCoatService("coat10", "XXL", "https://m.media-amazon.com/images/I/515R11jmKQL._SR500,500_.jpg", "100");
}


