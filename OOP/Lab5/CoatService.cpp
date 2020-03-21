#include "CoatService.h"


CoatService::CoatService(CoatRepository& coatRepository)
{
	this->coatRepository = coatRepository;
}

CoatService::CoatService(const CoatService& coatService)
{
	this->coatRepository = coatService.coatRepository;
}

CoatService& CoatService::operator=(const CoatService& coatService)
{
	if (this == &coatService)
		return *this;
	this->coatRepository = coatService.coatRepository;
	return *this;
}

int CoatService::storeCoatService(const std::string& name, const std::string& size, const std::string& photographSource, const std::string& price)
{
	TrenchCoat newCoat{ name, size, photographSource, atoi(price.c_str()) };
	int succes = this->coatRepository.storeCoat(newCoat);
	return succes;
}

int CoatService::deleteCoatService(const std::string name)
{
	int succes = this->coatRepository.deleteCoat(name);
	return succes;
}

void CoatService::updateCoatService(const std::string& name, const std::string& size, const std::string& photographSource, const std::string& price)
{
	TrenchCoat updatedCoat{ name, size, photographSource, atoi(price.c_str()) };
	this->coatRepository.updateCoat(updatedCoat);
}

std::string CoatService::listCoats()
{
	std::string listOfCoats = "";
	for (int i = 0; i < this->coatRepository.getRepositoryLength(); i++)
		listOfCoats += this->coatRepository.getCoatFromRepository(i).to_string() + "\n";
	
	return listOfCoats;
}
