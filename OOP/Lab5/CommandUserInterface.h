#pragma once
#include "CoatService.h"
#include "AdministratorUserInterface.h"



class CommandUserInterface
{
private:
	CoatService coatService;
	AdministratorUserInterface administratorUserInterface;

public:
	CommandUserInterface(){}

	CommandUserInterface(const CoatService& coatService, const AdministratorUserInterface& administratorUserInterface);

	CommandUserInterface(const CommandUserInterface& commandUserInterface);

	CommandUserInterface& operator=(const CommandUserInterface& commandUserInterface);

	void startProgram();

};

