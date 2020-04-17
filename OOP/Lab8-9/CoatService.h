#pragma once
#include "FileRepository.h"
#include "CoatsIterator.h"
#include "FileRepository.h"
#include "CoatValidator.h"

class CoatService
{
private:
	CSVFileRepository coatRepository;
	std::vector <TrenchCoat> userCoats;
	CoatsIterator coatsIterator;
	CoatValidator* coatsValidator;
	FileRepository* userRepository;

public:
	CoatService() :coatsValidator{ new CoatValidator }, userRepository{ new CSVFileRepository } {}

	CoatService(CSVFileRepository& coatRepository, CoatValidator* coatsValidator);

	CoatService(CSVFileRepository& coatRepository);

	CoatService(const CoatService& coatService);

	CoatService& operator=(const CoatService& coatService);

	~CoatService();

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

	void setPath(const std::string& filePath, const std::string& userRepositoryPath="");

	void clearFile();
};

