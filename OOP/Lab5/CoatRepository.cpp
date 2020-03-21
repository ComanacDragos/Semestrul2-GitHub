#include "CoatRepository.h"


CoatRepository::CoatRepository(const CoatRepository& coatRepository)
{
	this->coats = coatRepository.coats;
}

CoatRepository& CoatRepository::operator=(const CoatRepository& coatRepository)
{
	if (this == &coatRepository)
		return *this;
	this->coats = coatRepository.coats;
	return *this;
}

int CoatRepository::storeCoat(const TrenchCoat& coat)
{
	if (this->coats.findElement(coat) != -1)
		return 1;

	this->coats.addElement(coat);

	return 0;
}

int CoatRepository::deleteCoat(const std::string& name)
{
	for (int i = 0; i < this->coats.getLength(); i++)
		if (this->coats.getElement(i).getName().compare(name) == 0)
		{
			this->coats.removeFromPosition(i);
			return 0;
		}
	return 1;
}

void CoatRepository::updateCoat(const TrenchCoat& coat)
{
	for (int i = 0; i < this->coats.getLength(); i++)
		if (this->coats.getElement(i).getName().compare(coat.getName()) == 0)
			this->coats.getElement(i) = coat;
}

TrenchCoat CoatRepository::getCoatFromRepository(int position)
{
	return this->coats.getElement(position);
}

int CoatRepository::getRepositoryLength()
{
	return this->coats.getLength();
}
