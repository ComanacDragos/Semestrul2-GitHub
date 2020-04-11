#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "TrenchCoat.h"
#include "Exceptions.h"

class FileRepository
{
private:
	std::string filePath;

public:
	FileRepository() {}

	FileRepository(const std::string& filePath);

	~FileRepository(){}

	//throws an exception if the coat already exists
	void storeCoat(const TrenchCoat& coat);

	//throws an exception if the coat does not exist
	void deleteCoat(const std::string& name);

	//throws an exception if the coat doesn't exist
	void updateCoat(const TrenchCoat& coat);

	//throws an exception if position is invalid
	TrenchCoat getCoatFromRepository(int position);

	//returns a coat with a given name and throws an exception if there is no such coat
	TrenchCoat findCoatFromRepository(const std::string& name);

	int getRepositoryLength();

	std::vector<TrenchCoat> getAllCoats();

	void setPath(std::string filePath);

	void clearFile();

private:

	void storeCoatsToFile(const std::vector<TrenchCoat>& coats);

	std::vector<TrenchCoat> loadCoatsFromFile();

};
