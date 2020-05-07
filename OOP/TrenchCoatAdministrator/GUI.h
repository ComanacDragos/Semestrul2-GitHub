#pragma once
#include "CoatService.h"
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <qmessagebox.h>
#include <QDebug>

class GUI : public QWidget
{
	Q_OBJECT

public:
	GUI(CoatService& coatService, QWidget* parent = 0);
	~GUI() {}

private:
	CoatService coatService;
	QHBoxLayout* windowLayout;
	QListWidget *coatsList, *userList;
	QLineEdit* nameEdit, * sizeEdit, * priceEdit, * photographSourceEdit, * coatsRepository, * userRepository;
	QPushButton* addCoat, * deleteCoat, * updateCoat, * filterCoats, * openUserCoats, * nextCoat, * list, * saveToMyList, * showUserList, *undo, *redo, *exit;

	void initializeGUI();
	void initializeAdministratorGUI();
	void initializeUserGUI();

	void initializeConnections();

	//returns true if the paths were set successfully or false otherwise
	bool setCoatRepositoryPath();
	bool setUserRepositoryPath();

	int getSelectedIndex();
	void listItemSelected();
	
	void storeCoat();
	void listCoats();



};

