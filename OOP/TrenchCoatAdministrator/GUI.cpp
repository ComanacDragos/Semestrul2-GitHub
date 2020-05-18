#include "GUI.h"

GUI::GUI(QWidget* parent) :QMainWindow{ parent }
{
	this->readSettings();
	this->initializeGUI();
	this->listCoats();

}

void GUI::initializeGUI()
{
	QWidget* centralWidget = new QWidget{};
	this->administratorLayout = new QWidget{};
	this->userLayout = new QWidget{};

	//this->windowLayout = new QHBoxLayout{centralWidget};
	
	//this->windowLayout->addWidget(this->administratorLayout);

	//this->windowLayout->addWidget(this->userLayout);

	this->initializeAdministratorGUI();

	this->toUserMenu = new QAction{ "&User Mode", this };
	this->toAdministratorMenu = new QAction{ "&Administrator Mode", this };


	this->menuBar()->addAction(this->toAdministratorMenu);
	this->menuBar()->addAction(this->toUserMenu);

	this->initializeConnections();

	this->setStyleSheet(
		"QWidget{background-color: black; color: rgb(128, 233, 210);}"
		"QPushButton{background-color:rgb(128, 233, 210);color: black; border-radius: 15px;padding:10px;box-shadow: 5px 10px;}"
		"QPushButton:hover{background-color: rgb(0, 153, 120);color: black;}"
		"QMenu{background-color:rgb(128, 233, 210);color: black;}"
		"QMenu::item:selected{background-color: rgb(0, 153, 120);color: black;}"
		"QMenuBar{background-color:black;color: rgb(128, 233, 210);}"
		"QMenuBar::item:selected{background-color: rgb(0, 153, 120);color: black;}"
	);

	this->setCentralWidget(this->administratorLayout);
}

void GUI::initializeAdministratorGUI()
{
	QVBoxLayout* administratorLayout = new QVBoxLayout{ this->administratorLayout };


	//QFormLayout* filePathForm = new QFormLayout{};
	//QLabel* coatsLabel = new QLabel{ "&Coats file path:" };
	//this->coatsRepository = new QLineEdit{};
	//coatsLabel->setBuddy(this->coatsRepository);
	//filePathForm->addRow(coatsLabel, this->coatsRepository);

	//administratorLayout->addLayout(filePathForm);

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
	//this->barChart = new QPushButton{ "Bar chart" };
	

	buttons->addWidget(this->addCoatButton, 0, 0);
	buttons->addWidget(this->deleteCoatButton, 0, 1);
	buttons->addWidget(this->updateCoatButton, 0, 2);
	buttons->addWidget(this->listButton, 2, 0, 1, 3);
	//buttons->addWidget(this->filterCoatsButton, 3, 0, 1, 3);
	//buttons->addWidget(this->barChart, 4, 0, 1, 3);

	administratorLayout->addLayout(buttons);

	QGridLayout* undoRedoButtons = new QGridLayout{};

	this->undoButton = new QPushButton{ "Undo" };
	this->redoButton = new QPushButton{ "Redo" };
	this->exitButton = new QPushButton{ "Exit" };

	undoRedoButtons->addWidget(this->undoButton, 0, 1);
	undoRedoButtons->addWidget(this->redoButton, 0, 2);
	//undoRedoButtons->addWidget(this->exitButton, 1, 0, 1, 2);

	administratorLayout->addLayout(undoRedoButtons);

	administratorLayout->addWidget(this->exitButton);

	//this->windowLayout->addLayout(administratorLayout);

}

void GUI::initializeUserGUI()
{
	QVBoxLayout* userLayout = new QVBoxLayout{ this->userLayout };

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
	this->filterCoatsButton = new QPushButton{ "Filter coats" };

	QGridLayout* buttons = new QGridLayout{};

	buttons->addWidget(this->nextCoatButton, 0, 0);
	buttons->addWidget(this->openUserCoatsButton, 0, 1);
	//buttons->addWidget(this->showUserList, 1, 0, 1, 2);
	buttons->addWidget(this->filterCoatsButton, 1, 0, 1, 2);
	buttons->addWidget(this->exitButton, 2, 0, 1, 2);

	userLayout->addWidget(this->userList);

	QFormLayout* formLayout = new QFormLayout{};

	QLabel* userCoatNameLabel = new QLabel{ "&Name: " };
	this->userCoatEdit = new QLineEdit{};
	userCoatNameLabel->setBuddy(this->userCoatEdit);
	formLayout->addRow(userCoatNameLabel, this->userCoatEdit);

	QLabel* userCoatSizeLabel = new QLabel{ "&Size" };
	this->userCoatSizeEdit = new QLineEdit{};
	userCoatSizeLabel->setBuddy(this->userCoatSizeEdit);
	formLayout->addRow(userCoatSizeLabel, this->userCoatSizeEdit);

	QLabel* userCoatPriceLabel = new QLabel{ "&Price" };
	this->userCoatPriceEdit = new QLineEdit{};
	userCoatPriceLabel->setBuddy(this->userCoatPriceEdit);
	formLayout->addRow(userCoatPriceLabel, this->userCoatPriceEdit);

	userLayout->addLayout(formLayout);

	this->saveToMyListButton = new QPushButton{ "Save " };

	userLayout->addWidget(this->saveToMyListButton);

	userLayout->addLayout(buttons);

	//this->windowLayout->addLayout(userLayout); 
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

	
	QObject::connect(this->toAdministratorMenu, &QAction::triggered, this, [this]() {
		this->administratorLayout = new QWidget();
		this->initializeAdministratorGUI();
		this->initializeConnections();
		this->listCoats();
		this->setCentralWidget(this->administratorLayout); });

	QObject::connect(this->toUserMenu, &QAction::triggered, this, [this]() {
		this->userLayout = new QWidget();
		this->initializeUserGUI();
		this->initializeConnections();
		this->coatService.setCoatsIterator();
		this->setCentralWidget(this->userLayout); 
		});
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
	//std::string source = coatFields[3];

	this->userCoatEdit->setText(QString::fromStdString(name));
	this->userCoatSizeEdit->setText(QString::fromStdString(size));
	this->userCoatPriceEdit->setText(QString::fromStdString(price));
	//this->photographSourceEdit->setText(QString::fromStdString(source));
	
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
		//if (this->userList->count() > 0)
		//	this->userList->clear();
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
		//if (this->userList->count() > 0)
		//	this->userList->clear();
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
		//if (this->userList->count() > 0)
		//	this->userList->clear();
	}
	catch (Exceptions & exception)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(exception.what()));
	}
}

void GUI::filterCoats()
{
	std::string size = this->userCoatSizeEdit->displayText().toStdString();
	std::string price = this->userCoatPriceEdit->displayText().toStdString();
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
	if (this->userList->count() > 0)
		this->userList->clear();

	for (auto& coat : filteredCoats)
	{
		QString itemInList = QString::fromStdString(coat.to_string());
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		this->userList->addItem(item);
	}
}

void GUI::undo()
{
	try
	{
		this->coatService.undo();
		QMessageBox::information(this, "Success", "Successful undo");
		this->listCoats();
		//if (this->userList->count() > 0)
		//	this->userList->clear();
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
		//if(this->userList->count() > 0)
		//	this->userList->clear();
	}
	catch (Exceptions& exception)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(exception.what()));
	}
}

void GUI::saveCoatToUserList()
{
	if (this->userCoatEdit->text().size() == 0)
	{
		QMessageBox::warning(this, "Warning", "Select a coat");
		return;
	}

	std::string name = this->userCoatEdit->text().toStdString();
	/*
	std::string name;
	std::string coat{ this->userList->item(0)->text().toStdString() };
	std::stringstream stringStream{ coat };
	std::getline(stringStream, name, ' ');
	*/
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
	try
	{	
	TrenchCoat trenchCoat = this->coatService.getNextCoatFromIterator();
	std::string coat = trenchCoat.to_string();

	QString itemInList = QString::fromStdString(coat);
	QListWidgetItem* item = new QListWidgetItem{ itemInList };
	this->userList->addItem(item);

	this->userCoatEdit->setText(QString::fromStdString(trenchCoat.getName()));
	this->userCoatSizeEdit->setText(QString::fromStdString(trenchCoat.getSize()));
	this->userCoatPriceEdit->setText(QString::fromStdString(std::to_string(trenchCoat.getPrice())));

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
