#pragma once
#include "CoatService.h"
#include "AdministratorUserInterface.h"
#include "ClientUserInterface.h"

#define AdministratorMode 2
#define ClientMode 1

class CommandUserInterface
{
private:
	CoatService coatService;
	AdministratorUserInterface administratorUserInterface;
	ClientUserInterface clientUserInterface;

public:
	CommandUserInterface(){}

	CommandUserInterface(const CoatService& coatService);

	CommandUserInterface(const CommandUserInterface& commandUserInterface);

	CommandUserInterface& operator=(const CommandUserInterface& commandUserInterface);

	~CommandUserInterface(){}

	void startProgram();

	void initializeRepository();
};

