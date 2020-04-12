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

TrenchCoat::TrenchCoat(const TrenchCoat& trenchCoat)
{
	this->name = trenchCoat.name;
	this->photographSource = trenchCoat.photographSource;
	this->price = trenchCoat.price;
	this->size = trenchCoat.size;
}

TrenchCoat& TrenchCoat::operator=(const TrenchCoat& trenchCoat)
{
	if (this == &trenchCoat)
		return *this;

	
	this->price = trenchCoat.price;

	this->name = trenchCoat.name;
	
	this->size = trenchCoat.size;

	this->photographSource = trenchCoat.photographSource;


	return *this;
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
	return this->name + " " + this->size + " " + std::to_string(this->price) + " " + this->photographSource;
}

std::vector<std::string> tokenize(std::string string, const char delimiter)
{
	std::vector<std::string> result;
	
	std::stringstream stringStream{ string };
	std::string token;

	while (std::getline(stringStream, token, delimiter))
		if (token.size() != 0)
		{
			std::stringstream tokenStringStream { token };
			while (std::getline(tokenStringStream, token, ' '))
				if(token.size() != 0)
					result.push_back(token);
		}

	return result;
}


std::istream& operator>>(std::istream& istream, TrenchCoat& coat)
{
	std::string line;
	std::getline(istream, line);
	std::vector<std::string> tokens = tokenize(line, ',');

	if (tokens.size() != 4) // bad data
		return istream;

	std::string name{ tokens[0] };
	std::string size{ tokens[1] };
	std::string photographSource{ tokens[3] };
	std::string price{ tokens[2] };

	TrenchCoat newCoat{ name, size, photographSource, stoi(price) };
	coat = newCoat;
	
	return istream;
}

std::ostream& operator<<(std::ostream& ostream, const TrenchCoat& coat)
{
	ostream << coat.getName() << "," << coat.getSize() << "," << coat.getPrice() << "," << coat.getPhotographSource() << '\n';
	return ostream;
}
