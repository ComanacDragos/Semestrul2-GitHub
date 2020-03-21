#include "TrenchCoat.h"

TrenchCoat::TrenchCoat()
{
	this->name = "";
	this->size = "";
	this->photographSource = "";
	this->price = -1;
}

TrenchCoat::TrenchCoat(const std::string& name, const std::string& size, const std::string photographSource, const int price)
{
	this->name = name;
	this->size = size;
	this->photographSource = photographSource;
	this->price = price;
}

std::string TrenchCoat::getName() const
{
	return this->name;
}

std::string TrenchCoat::getSize() const
{
	return this->size;
}

std::string TrenchCoat::getPhotographSource() const
{
	return this->photographSource;
}

int TrenchCoat::getPrice() const
{
	return this->price;
}

bool TrenchCoat::operator==(const TrenchCoat& trenchCoat)
{
	if (this->name.compare(trenchCoat.name) == 0)
		return true;
	return false;
}

std::string TrenchCoat::to_string()
{
	return this->name + " " + this->size + " " + this->photographSource + " " + std::to_string(this->price);
}
