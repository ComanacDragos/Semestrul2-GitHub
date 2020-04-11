#include "FileRepository.h"

FileRepository::FileRepository(const std::string& filePath)
{
	this->filePath = filePath;
}

void FileRepository::storeCoat(const TrenchCoat& coat)
{
	std::vector<TrenchCoat> coats = this->loadCoatsFromFile();
	if (std::find(coats.begin(), coats.end(), coat) != coats.end())
		throw ExistentTrenchCoat{ "Coat already exists\n" };

	coats.push_back(coat);
	this->storeCoatsToFile(coats);
}

void FileRepository::deleteCoat(const std::string& name)
{
	std::vector<TrenchCoat> coats = this->loadCoatsFromFile();
	auto iterator = find(coats.begin(), coats.end(), TrenchCoat(name, "size", "source", 0));
	if (iterator == coats.end())
		throw InexistentTrenchCoat{ "Coat doesn't exist\n" };

	coats.erase(iterator);
	this->storeCoatsToFile(coats);

}

void FileRepository::updateCoat(const TrenchCoat& coat)
{
	std::vector<TrenchCoat> coats = this->loadCoatsFromFile();
	auto iterator = find(coats.begin(), coats.end(), coat);
	if (iterator == coats.end())
		throw InexistentTrenchCoat{ "Coat doesn't exist\n" };

	*iterator = coat;
	this->storeCoatsToFile(coats);
}

TrenchCoat FileRepository::getCoatFromRepository(int position)
{
	std::vector<TrenchCoat> coats = this->getAllCoats();
	if (position < 0 || position >= coats.size())
		throw BadPosition{ "Invalid position\n" };

	return *(coats.begin() + position);
}

TrenchCoat FileRepository::findCoatFromRepository(const std::string& name)
{
	std::vector<TrenchCoat> coats = this->getAllCoats();
	auto iterator = find(coats.begin(), coats.end(), TrenchCoat(name, "size", "source", 0));
	if (iterator == coats.end())
		throw InexistentTrenchCoat{ "Coat doesn't exist\n" };

	return *iterator;
}

int FileRepository::getRepositoryLength()
{
	return this->loadCoatsFromFile().size();
}

std::vector<TrenchCoat> FileRepository::getAllCoats()
{
	return this->loadCoatsFromFile();
}


void FileRepository::setPath(std::string filePath)
{
	this->filePath = filePath;
}

void FileRepository::clearFile()
{
	std::ofstream fout(this->filePath);
	fout.close();
}


void FileRepository::storeCoatsToFile(const std::vector<TrenchCoat>& coats)
{
	std::ofstream fout (this->filePath, std::ios::trunc | std::ios::out);
	for (auto& coat : coats)
		fout << coat;

	fout.close();
}

std::vector<TrenchCoat> FileRepository::loadCoatsFromFile()
{
	std::ifstream fin(this->filePath, std::ios::in);

	std::vector<TrenchCoat> coats;
	TrenchCoat currentCoat;

	while (fin >> currentCoat)
		coats.push_back(currentCoat);

	fin.close();
	return coats;
}

