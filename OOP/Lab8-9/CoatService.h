#pragma once
#include "FileRepository.h"
#include "CoatsIterator.h"
#include "FileRepository.h"

class CoatService
{
private:
	FileRepository coatRepository;
	std::vector <TrenchCoat> userCoats;
	CoatsIterator coatsIterator;

public:
	CoatService(){}

	//copy constructor
	CoatService(FileRepository& coatRepository);

	CoatService(const CoatService& coatService);

	CoatService& operator=(const CoatService& coatService);

	~CoatService(){}

	//raises an exception if price is not a number
	void storeCoatService(const std::string& name, const std::string& size, const std::string& photographSource, const std::string& price);

	void deleteCoatService(const std::string name);

	//raises an exception if price is not a number
	void updateCoatService(const std::string& name, const std::string& size, const std::string& photographSource, const std::string& price);
	
	std::vector<TrenchCoat> listCoats();

	TrenchCoat getCoatFromRepository(int position);

	int getRepositoryLenght();

	//returns an interator over the list of coats
	CoatsIterator getCoatsIterator();

	void saveTrenchCoatToUserList(const std::string& name);

	std::vector<TrenchCoat> listFilteredCoats(const std::string& size, const std::string& price);

	std::vector<TrenchCoat> getUserCoats();

	void emptyUserCoats();

	void setCoatIteratorToFirst();

	TrenchCoat getNextCoatFromIterator();

	bool isNumber(const std::string& number);

	void setPath(const std::string& filePath);

	void clearFile();
};

