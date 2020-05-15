#include "GUI.h"

GUI::GUI(QWidget* parent) :QWidget{ parent }
{
	this->readSettings();
	this->initializeGUI();
	this->listCoats();
}

void GUI::initializeGUI()
{
	
	this->windowLayout = new QHBoxLayout{this};
	
	this->initializeAdministratorGUI();

	this->saveToMyListButton = new QPushButton{ " > " };

	this->windowLayout->addWidget(this->saveToMyListButton);
	
	this->initializeUserGUI();

	this->initializeConnections();

	this->setStyleSheet(
		"QWidget{background-color: black; color: rgb(128, 233, 210);}"
		"QPushButton{background-color:rgb(128, 233, 210);color: black; border-radius: 15px;padding:10px;box-shadow: 5px 10px;}"
		"QPushButton:hover{background-color: rgb(0, 153, 120);color: black;}");
}

void GUI::initializeAdministratorGUI()
{
	QVBoxLayout* administratorLayout = new QVBoxLayout{};


	QFormLayout* filePathForm = new QFormLayout{};
	//QLabel* coatsLabel = new QLabel{ "&Coats file path:" };
	//this->coatsRepository = new QLineEdit{};
	//coatsLabel->setBuddy(this->coatsRepository);
	//filePathForm->addRow(coatsLabel, this->coatsRepository);

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

	this->addCoatButton = new QPushButton{ "Add Coat" };
	this->deleteCoatButton = new QPushButton{ "Delete Coat" };
	this->updateCoatButton = new QPushButton{ "Update Coat" };
	this->listButton = new QPushButton{ "List Coats" };
	this->filterCoatsButton = new QPushButton{ "Filter coats" };
	//this->barChart = new QPushButton{ "Bar chart" };

	buttons->addWidget(this->addCoatButton, 0, 0);
	buttons->addWidget(this->deleteCoatButton, 0, 1);
	buttons->addWidget(this->updateCoatButton, 0, 2);
	buttons->addWidget(this->listButton, 2, 0, 1, 3);
	buttons->addWidget(this->filterCoatsButton, 3, 0, 1, 3);
	//buttons->addWidget(this->barChart, 4, 0, 1, 3);

	administratorLayout->addLayout(buttons);

	QGridLayout* undoRedoButtons = new QGridLayout{};

	this->undoButton = new QPushButton{ "Undo" };
	this->redoButton = new QPushButton{ "Redo" };

	undoRedoButtons->addWidget(this->undoButton, 0, 1);
	undoRedoButtons->addWidget(this->redoButton, 0, 2);

	administratorLayout->addLayout(undoRedoButtons);

	this->windowLayout->addLayout(administratorLayout);

}

void GUI::initializeUserGUI()
{
	QVBoxLayout* userLayout = new QVBoxLayout{};

	//QFormLayout* filePathForm = new QFormLayout{};

	//this->userRepository = new QLineEdit{};
	//QLabel* userCoatsLabel = new QLabel{ "&User coats file path:" };
	//userCoatsLabel->setBuddy(this->userRepository);

	//filePathForm->addRow(userCoatsLabel, this->userRepository);

	//userLayout->addLayout(filePathForm);

	this->userList = new QListWidget{};

	this->nextCoatButton = new QPushButton{ "Next" };
	this->openUserCoatsButton = new QPushButton{ "Open user coats file" };
	//this->showUserList = new QPushButton{ "Show user coats" };
	this->exitButton = new QPushButton{ "Exit" };

	QGridLayout* buttons = new QGridLayout{};

	buttons->addWidget(this->nextCoatButton, 0, 0);
	buttons->addWidget(this->openUserCoatsButton, 0, 1);
	//buttons->addWidget(this->showUserList, 1, 0, 1, 2);
	buttons->addWidget(this->exitButton, 1, 0, 1, 2);

	userLayout->addWidget(this->userList);
	userLayout->addLayout(buttons);

	this->windowLayout->addLayout(userLayout); 
}

void GUI::initializeBarChart()
{
	BarChart* chart = new BarChart{this->coatService.listCoats()};
	chart->show();
}

void GUI::initializeConnections()
{
	QObject::connect(this->addCoatButton, &QPushButton::clicked, this, [this]() {this->storeCoat(); });

	QObject::connect(this->listButton, &QPushButton::clicked, this, [this]() {this->listCoats(); });
	
	QObject::connect(this->exitButton, &QPushButton::clicked, [this]() {close(); });
	
	QObject::connect(this->coatsList, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemSelected(); });
	
	QObject::connect(this->deleteCoatButton, &QPushButton::clicked, this, [this]() {this->deleteCoat(); });
	
	QObject::connect(this->updateCoatButton, &QPushButton::clicked, this, [this]() {this->updateCoat(); });
	
	QObject::connect(this->filterCoatsButton, &QPushButton::clicked, this, [this]() {this->filterCoats(); });
	
	QObject::connect(this->undoButton, &QPushButton::clicked, this, [this]() {this->undo(); });
	
	QObject::connect(this->redoButton, &QPushButton::clicked, this, [this]() {this->redo(); });
	
	QObject::connect(this->nextCoatButton, &QPushButton::clicked, this, [this]() {this->nextCoat(); });
	
	QObject::connect(this->userList, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemSelectedUserList(); });

	QObject::connect(this->openUserCoatsButton, &QPushButton::clicked, this, [this]() {this->openUserList(); });
	
	QObject::connect(this->saveToMyListButton, &QPushButton::clicked, this, [this]() {this->saveCoatToUserList(); });

	//QObject::connect(this->barChart, &QPushButton::clicked, this, [this]() {this->initializeBarChart(); });
}

void GUI::readSettings()
{
	std::ifstream fileOut{ "settings.txt" };
	std::string coats, userCoats;
	std::getline(fileOut, coats, '=');
	std::getline(fileOut, coats);

	std::getline(fileOut, userCoats, '=');
	std::getline(fileOut, userCoats);

	this->coatService.setPath(coats, userCoats);
}

int GUI::getSelectedIndex(QListWidget* list)
{
	if (list->count() == 0)
		return -1;

	QModelIndexList index = list->selectionModel()->selectedIndexes();

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
	int index = this->getSelectedIndex(this->coatsList);
	             
	if (index == -1 || index >= this->coatService.getRepositoryLenght())
		return;

	TrenchCoat coat = this->coatService.getCoatFromRepository(index);

	this->nameEdit->setText(QString::fromStdString(coat.getName()));
	this->sizeEdit->setText(QString::fromStdString(coat.getSize()));
	this->priceEdit->setText(QString::fromStdString(std::to_string(coat.getPrice())));
	this->photographSourceEdit->setText(QString::fromStdString(coat.getPhotographSource()));

}

void GUI::listItemSelectedUserList()
{
	auto selectedCoat = this->userList->currentItem();

	std::vector<std::string> coatFields = tokenize(selectedCoat->text().toStdString(), ' ');

	std::string name = coatFields[0];
	std::string size = coatFields[1];
	std::string price = coatFields[2];
	std::string source = coatFields[3];

	this->nameEdit->setText(QString::fromStdString(name));
	this->sizeEdit->setText(QString::fromStdString(size));
	this->priceEdit->setText(QString::fromStdString(price));
	this->photographSourceEdit->setText(QString::fromStdString(source));
	
}

void GUI::storeCoat()
{	
	std::string name = this->nameEdit->displayText().toStdString();
	std::string size = this->sizeEdit->displayText().toStdString();
	std::string price = this->priceEdit->displayText().toStdString();
	std::string source = this->photographSourceEdit->displayText().toStdString();
	
	try
	{
		this->coatService.storeCoatService(name, size, source, price);
		QMessageBox::information(this, "Success", "Coat added successfully");
		this->listCoats();
		if (this->userList->count() > 0)
			this->userList->clear();
	}
	catch (Exceptions & exception)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(exception.what()));
	}
}

void GUI::listCoats()
{
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

void GUI::deleteCoat()
{
	std::string name = this->nameEdit->text().toStdString();

	try
	{
		this->coatService.deleteCoatService(name);
		QMessageBox::information(this, "Success", "Coat deleted successfully");
		this->listCoats();
		if (this->userList->count() > 0)
			this->userList->clear();
	}
	catch (Exceptions & exception)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(exception.what()));
	}
}

void GUI::updateCoat()
{
	std::string name = this->nameEdit->displayText().toStdString();
	std::string size = this->sizeEdit->displayText().toStdString();
	std::string price = this->priceEdit->displayText().toStdString();
	std::string source = this->photographSourceEdit->displayText().toStdString();

	try
	{
		this->coatService.updateCoatService(name, size, source, price);
		QMessageBox::information(this, "Success", "Coat updated successfully");
		this->listCoats();
		if (this->userList->count() > 0)
			this->userList->clear();
	}
	catch (Exceptions & exception)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(exception.what()));
	}
}

void GUI::filterCoats()
{
	std::string size = this->sizeEdit->displayText().toStdString();
	std::string price = this->priceEdit->displayText().toStdString();
	std::vector<TrenchCoat> filteredCoats;
	try
	{
		filteredCoats = this->coatService.listFilteredCoats(size, price);
	}
	catch (Exceptions & exception)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(exception.what()));
		return;
	}
	if (this->coatsList->count() > 0)
		this->coatsList->clear();

	for (auto& coat : filteredCoats)
	{
		QString itemInList = QString::fromStdString(coat.to_string());
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		this->coatsList->addItem(item);
	}
}

void GUI::undo()
{
	try
	{
		this->coatService.undo();
		QMessageBox::information(this, "Success", "Successful undo");
		this->listCoats();
		if (this->userList->count() > 0)
			this->userList->clear();
	}
	catch (Exceptions& exception)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(exception.what()));
	}
}

void GUI::redo()
{
	try
	{
		this->coatService.redo();
		QMessageBox::information(this, "Success", "Successful redo");
		this->listCoats();
		if(this->userList->count() > 0)
			this->userList->clear();
	}
	catch (Exceptions& exception)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(exception.what()));
	}
}

void GUI::saveCoatToUserList()
{
	std::string name = this->nameEdit->text().toStdString();

	try
	{
		this->coatService.saveTrenchCoatToUserList(name);
		QMessageBox::information(this, "Succes", "Coat saved to user list");
	}
	catch (Exceptions & exception)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(exception.what()));
	}
}

void GUI::nextCoat()
{
	int i = this->userList->count();
	if (this->userList->count() > 0)
		this->userList->clear();
	else
		this->coatService.setCoatsIterator();

	try
	{	
	std::string coat = this->coatService.getNextCoatFromIterator().to_string();

	QString itemInList = QString::fromStdString(coat);
	QListWidgetItem* item = new QListWidgetItem{ itemInList };
	this->userList->addItem(item);
	}
	catch (Exceptions & exception)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(exception.what()));
	}

}

void GUI::openUserList()
{
	this->coatService.openUserFile();
}
