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

	for (int i = 0; i < price.length(); i++)
		if (price[i] < '0' || price[i] > '9')
			return 1;

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

DynamicVector<TrenchCoat> CoatService::listCoats()
{
	return this->coatRepository.getAllCoats();
}

void CoatService::openInBrowser(const std::string& name)
{
	TrenchCoat coat = this->coatRepository.findCoatFromRepository(name);
	coat.openInBrowser();
}
