#include "GUI.h"

GUI::GUI(CoatService& coatService, QWidget* parent):QWidget{ parent }, coatService{coatService}
{
	this->initializeGUI();
}

void GUI::initializeGUI()
{
	this->windowLayout = new QHBoxLayout{ this };

	this->initializeAdministratorGUI();

	this->saveToMyList = new QPushButton{ " > " };

	this->windowLayout->addWidget(this->saveToMyList);
	
	this->initializeUserGUI();

	this->initializeConnections();
}

void GUI::initializeAdministratorGUI()
{
	QVBoxLayout* administratorLayout = new QVBoxLayout{};


	QFormLayout* filePathForm = new QFormLayout{};
	QLabel* coatsLabel = new QLabel{ "&Coats file path:" };
	this->coatsRepository = new QLineEdit{};
	coatsLabel->setBuddy(this->coatsRepository);
	filePathForm->addRow(coatsLabel, this->coatsRepository);

	administratorLayout->addLayout(filePathForm);

	this->coatsList = new QListWidget{};
	QGridLayout* buttons = new QGridLayout{};
	QFormLayout* formLayout = new QFormLayout{};

	administratorLayout->addWidget(this->coatsList);

	this->nameEdit = new QLineEdit{};
	QLabel* nameLabel = new QLabel{ "&Name:" };
	nameLabel->setBuddy(this->nameEdit);

	this->sizeEdit = new QLineEdit{};
	QLabel* sizeLabel = new QLabel{ "&Size:" };
	sizeLabel->setBuddy(this->sizeEdit);

	this->priceEdit = new QLineEdit{};
	QLabel* priceLabel = new QLabel{ "&Price:" };
	priceLabel->setBuddy(this->priceEdit);

	this->photographSourceEdit = new QLineEdit{};
	QLabel* sourceLabel = new QLabel{ "&Photograph Source:" };
	sourceLabel->setBuddy(this->photographSourceEdit);

	formLayout->addRow(nameLabel, this->nameEdit);
	formLayout->addRow(sizeLabel, this->sizeEdit);
	formLayout->addRow(priceLabel, this->priceEdit);
	formLayout->addRow(sourceLabel, this->photographSourceEdit);

	administratorLayout->addLayout(formLayout);

	this->addCoat = new QPushButton{ "Add Coat" };
	this->deleteCoat = new QPushButton{ "Delete Coat" };
	this->updateCoat = new QPushButton{ "Update Coat" };
	this->list = new QPushButton{ "List Coats" };
	this->filterCoats = new QPushButton{ "Filter coats" };

	buttons->addWidget(this->addCoat, 0, 0);
	buttons->addWidget(this->deleteCoat, 0, 1);
	buttons->addWidget(this->updateCoat, 0, 2);
	buttons->addWidget(this->list, 2, 0, 1, 3);
	buttons->addWidget(this->filterCoats, 3, 0, 1, 3);

	administratorLayout->addLayout(buttons);

	QGridLayout* undoRedoButtons = new QGridLayout{};

	this->undo = new QPushButton{ "Undo" };
	this->redo = new QPushButton{ "Redo" };

	undoRedoButtons->addWidget(this->undo, 0, 1);
	undoRedoButtons->addWidget(this->redo, 0, 2);

	administratorLayout->addLayout(undoRedoButtons);

	this->windowLayout->addLayout(administratorLayout);

}

void GUI::initializeUserGUI()
{
	QVBoxLayout* userLayout = new QVBoxLayout{};

	QFormLayout* filePathForm = new QFormLayout{};

	this->userRepository = new QLineEdit{};
	QLabel* userCoatsLabel = new QLabel{ "&User coats file path:" };
	userCoatsLabel->setBuddy(this->userRepository);

	filePathForm->addRow(userCoatsLabel, this->userRepository);

	userLayout->addLayout(filePathForm);

	QListWidget* userCoats = new QListWidget{};

	this->nextCoat = new QPushButton{ "Next" };
	this->openUserCoats = new QPushButton{ "Open user coats file" };
	//this->showUserList = new QPushButton{ "Show user coats" };
	this->exit = new QPushButton{ "Exit" };

	QGridLayout* buttons = new QGridLayout{};

	buttons->addWidget(this->nextCoat, 0, 0);
	buttons->addWidget(this->openUserCoats, 0, 1);
	//buttons->addWidget(this->showUserList, 1, 0, 1, 2);
	buttons->addWidget(this->exit, 1, 0, 1, 2);

	userLayout->addWidget(userCoats);
	userLayout->addLayout(buttons);

	this->windowLayout->addLayout(userLayout); 
}

void GUI::initializeConnections()
{
	QObject::connect(this->addCoat, &QPushButton::clicked, this, [this]() {this->storeCoat(); });
	QObject::connect(this->list, &QPushButton::clicked, this, [this]() {this->listCoats(); });
	QObject::connect(this->exit, &QPushButton::clicked, [this]() {close(); });
	QObject::connect(this->coatsList, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemSelected(); });
}

bool GUI::setCoatRepositoryPath()
{
	std::string repoFilePath = this->coatsRepository->displayText().toStdString();
	
	if (repoFilePath == "")
	{
		QMessageBox::warning(this, "Warning", "Provide a path for the repository");
		return false;
	}

	this->coatService.setCoatRepositoryPath(repoFilePath);

	return true;
}

bool GUI::setUserRepositoryPath()
{
	std::string userRepoFilePath = this->userRepository->displayText().toStdString();

	if (userRepoFilePath == "")
	{
		QMessageBox::warning(this, "Warning", "Provide a path for the user repository");
		return false;
	}

	this->coatService.setUserRepositoryPath(userRepoFilePath);
	return true;
}

int GUI::getSelectedIndex()
{
	if (this->coatsList->count() == 0)
		return -1;

	QModelIndexList index = this->coatsList->selectionModel()->selectedIndexes();

	if (index.size() == 0)
	{
		this->nameEdit->clear();
		this->sizeEdit->clear();
		this->priceEdit->clear();
		this->photographSourceEdit->clear();
		return -1;
	}
	int integerIndex = index.at(0).row();
	return integerIndex;
}

void GUI::listItemSelected()
{
	int index = this->getSelectedIndex();

	if (index == -1 || index >= this->coatService.getRepositoryLenght())
		return;
		
	TrenchCoat coat = this->coatService.getCoatFromRepository(index);
	this->nameEdit->setText(QString::fromStdString(coat.getName()));
	this->sizeEdit->setText(QString::fromStdString(coat.getSize()));
	this->priceEdit->setText(QString::fromStdString(std::to_string(coat.getPrice())));
	this->photographSourceEdit->setText(QString::fromStdString(coat.getPhotographSource()));

}

void GUI::storeCoat()
{
	if (this->setCoatRepositoryPath() == false)
		return;
	
	std::string name = this->nameEdit->displayText().toStdString();
	std::string size = this->sizeEdit->displayText().toStdString();
	std::string price = this->priceEdit->displayText().toStdString();
	std::string source = this->photographSourceEdit->displayText().toStdString();
	
	try
	{
		this->coatService.storeCoatService(name, size, source, price);
		QMessageBox::information(this, "Success", "Coat added successfully");
	}
	catch (Exceptions & exception)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(exception.what()));
	}

	this->listCoats();
}

void GUI::listCoats()
{
	if (this->setCoatRepositoryPath() == false)
		return;

	if(this->coatsList->count() > 0)
		this->coatsList->clear();

	for (auto& coat : this->coatService.listCoats())
	{
		QString itemInList = QString::fromStdString(coat.to_string());
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		this->coatsList->addItem(item);
	}

	//if (this->coatsList->count() > 0)
	//	this->coatsList->setCurrentRow(0);
}
