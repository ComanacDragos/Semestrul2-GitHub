#pragma once
#include "CoatService.h"

//the maximum lenght of a command
#define CommandLenght 200


//the maximum length in a word in a command
#define WordInCommandLenght 50

class ClientUserInterface
{
private:
	CoatService coatService;

public:
	ClientUserInterface(){}
	
	ClientUserInterface(const CoatService& coatService);

	ClientUserInterface(const ClientUserInterface& clientUserInterface);

	ClientUserInterface& operator=(const ClientUserInterface& clientUserInterface);

	~ClientUserInterface(){}

	void startClientUserInterface();
};

