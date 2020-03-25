#pragma once
#include "CoatRepository.h"

class CoatService
{
private:
	CoatRepository coatRepository;

public:
	CoatService(){}

	//copy constructor
	CoatService(CoatRepository& coatRepository);

	CoatService(const CoatService& coatService);

	CoatService& operator=(const CoatService& coatService);

	~CoatService(){}

	//returns 1 if the coat already is in the repository, 0 otherwise
	int storeCoatService(const std::string& name, const std::string& size, const std::string& photographSource, const std::string& price);

	//returns 1 if the coat does not exist in the repository, 0 otherwise
	int deleteCoatService(const std::string name);

	void updateCoatService(const std::string& name, const std::string& size, const std::string& photographSource, const std::string& price);
	
	DynamicVector listCoats();
	
	void openInBrowser(const std::string& name);
};

