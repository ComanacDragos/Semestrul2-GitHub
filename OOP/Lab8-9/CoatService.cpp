#include "CoatService.h"

CoatService::CoatService(CSVFileRepository& coatRepository, CoatValidator* coatsValidator)
{
	this->coatRepository = coatRepository;
	this->coatsIterator = this->getCoatsIterator();
	this->coatsValidator = coatsValidator;
	this->userRepository = new CSVFileRepository;
}

CoatService::CoatService(CSVFileRepository& coatRepository)
{
	this->coatRepository = coatRepository;
	this->coatsIterator = this->getCoatsIterator();
	this->coatsValidator = new CoatValidator;
	this->userRepository = new CSVFileRepository;
}

CoatService::CoatService(const CoatService& coatService)
{
	this->coatRepository = coatService.coatRepository;
	this->coatsIterator = coatService.coatsIterator;

	this->coatsValidator = new CoatValidator;
	*(this->coatsValidator) = *(coatService.coatsValidator);

	this->userRepository = new CSVFileRepository;
	*(this->userRepository) = *(coatService.userRepository);

}

CoatService& CoatService::operator=(const CoatService& coatService)
{
	if (this == &coatService)
		return *this;
	this->coatRepository = coatService.coatRepository;
	this->coatsIterator = coatService.coatsIterator;

	*(this->coatsValidator) = *(coatService.coatsValidator);
	*(this->userRepository) = *(coatService.userRepository);

	return *this;
}

CoatService::~CoatService()
{
	delete this->coatsValidator;
	delete this->userRepository;
}

void CoatService::storeCoatService(const std::string& name, const std::string& size, const std::string& photographSource, const std::string& price)
{
	this->coatsValidator->validateCoat(name, size, photographSource, price);

	TrenchCoat newCoat{ name, size, photographSource, atoi(price.c_str()) };
	this->coatRepository.storeCoat(newCoat);
}

void CoatService::deleteCoatService(const std::string name)
{
	this->coatRepository.deleteCoat(name);

	if (this->userRepository->existentCoat(name))
		this->userRepository->deleteCoat(name);
}

void CoatService::updateCoatService(const std::string& name, const std::string& size, const std::string& photographSource, const std::string& price)
{
	this->coatsValidator->validateCoat(name, size, photographSource, price);

	TrenchCoat updatedCoat{ name, size, photographSource, atoi(price.c_str()) };
	this->coatRepository.updateCoat(updatedCoat);

	if (this->userRepository->existentCoat(name))
		this->userRepository->updateCoat(updatedCoat);

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
	
	this->userRepository->storeCoat(newUserCoat);
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
	return this->userRepository->getAllCoats();
}

void CoatService::emptyUserCoats()
{
	std::vector<TrenchCoat> coats{ this->getUserCoats() };
	for (auto& coat : coats)
		this->userRepository->deleteCoat(coat.getName());
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

void CoatService::setPath(const std::string& filePath, const std::string& userRepositoryPath)
{
	this->coatRepository.setPath(filePath);

	if (userRepositoryPath.size() != 0)
	{
		std::string fileType = userRepositoryPath.substr(userRepositoryPath.find('.')+1, std::string::npos);

		if (fileType == "html")
		{
			delete this->userRepository;
			this->userRepository = new HTMLFileRepository{ userRepositoryPath };
		}
		if (fileType == "csv" || fileType == "txt")
		{
			delete this->userRepository;
			this->userRepository = new CSVFileRepository{userRepositoryPath};
		}
	}
}

void CoatService::clearFile()
{
	this->coatRepository.clearFile();
	this->userRepository->clearFile();
}

void CoatService::openUserFile(){this->userRepository->openFile();}

