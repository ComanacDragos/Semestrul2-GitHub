#include "CoatService.h"

CoatService::CoatService(FileRepository& coatRepository)
{
	this->coatRepository = coatRepository;
	this->coatsIterator = this->getCoatsIterator();
}

CoatService::CoatService(const CoatService& coatService)
{
	this->coatRepository = coatService.coatRepository;
	this->userCoats = coatService.userCoats;
	this->coatsIterator = coatService.coatsIterator;
}

CoatService& CoatService::operator=(const CoatService& coatService)
{
	if (this == &coatService)
		return *this;
	this->coatRepository = coatService.coatRepository;
	this->userCoats = coatService.userCoats;
	this->coatsIterator = coatService.coatsIterator;
	return *this;
}

void CoatService::storeCoatService(const std::string& name, const std::string& size, const std::string& photographSource, const std::string& price)
{
	if (this->isNumber(price) == false)
		throw BadPrice{ "Bad price\n" };

	TrenchCoat newCoat{ name, size, photographSource, atoi(price.c_str()) };
	this->coatRepository.storeCoat(newCoat);
}

void CoatService::deleteCoatService(const std::string name)
{
	this->coatRepository.deleteCoat(name);

	auto iterator = std::remove_if(this->userCoats.begin(), this->userCoats.end(), [name](const TrenchCoat& coat) {return coat.getName() == name; });
}

void CoatService::updateCoatService(const std::string& name, const std::string& size, const std::string& photographSource, const std::string& price)
{
	if (this->isNumber(price) == false)
		throw BadPrice{ "Bad price\n" };

	TrenchCoat updatedCoat{ name, size, photographSource, atoi(price.c_str()) };
	this->coatRepository.updateCoat(updatedCoat);

	std::replace_if(this->userCoats.begin(), this->userCoats.end(),
					[updatedCoat](const TrenchCoat& coat) {return coat.getName() == updatedCoat.getName(); }, updatedCoat);
}

std:: vector<TrenchCoat> CoatService::listCoats()
{
	return this->coatRepository.getAllCoats();
}


TrenchCoat CoatService::getCoatFromRepository(int position)
{
	return this->coatRepository.getCoatFromRepository(position);
}

int CoatService::getRepositoryLenght()
{
	return this->coatRepository.getRepositoryLength();
}


CoatsIterator CoatService::getCoatsIterator()
{
	return CoatsIterator(this->listCoats());
}

void CoatService::saveTrenchCoatToUserList(const std::string& name)
{
	TrenchCoat newUserCoat = this->coatRepository.findCoatFromRepository(name);
	this->userCoats.push_back(newUserCoat);
}

std:: vector<TrenchCoat> CoatService::listFilteredCoats(const std::string& size, const std::string& price)
{
	std::vector<TrenchCoat> coatsFromRepository = this->listCoats();
	std::vector<TrenchCoat> filteredCoats{ coatsFromRepository.size() };
	auto iterator = std::copy_if(coatsFromRepository.begin(), coatsFromRepository.end(), filteredCoats.begin(),
		[size, price](const TrenchCoat& currentCoat) {return currentCoat.getSize().compare(size) == 0 && currentCoat.getPrice() <= atoi(price.c_str()); });

	filteredCoats.resize(iterator - filteredCoats.begin());
	
	return filteredCoats;
}

std::vector<TrenchCoat> CoatService::getUserCoats()
{
	return this->userCoats;
}

void CoatService::emptyUserCoats()
{
	std::vector<TrenchCoat> emptyList;
	this->userCoats = emptyList;
}

void CoatService::setCoatIteratorToFirst()
{
	this->coatsIterator = this->getCoatsIterator();
}

TrenchCoat CoatService::getNextCoatFromIterator()
{
	TrenchCoat nextCoat = this->coatsIterator.getCurrent();
	this->coatsIterator.next();
	return nextCoat;
}

bool CoatService::isNumber(const std::string& number)
{
	for (auto it : number)
		if (isdigit(it) == false)
			return false;
	return true;
}

void CoatService::setPath(const std::string& filePath)
{
	this->coatRepository.setPath(filePath);
}

void CoatService::clearFile()
{
	this->coatRepository.clearFile();
}

