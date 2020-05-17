#pragma once
#include "CoatService.h"
#include "BarChart.h"
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <qmessagebox.h>
#include <QDebug>
#include <QObject>
#include <QtQuick/QQuickPaintedItem>
#include <QPainter>
#include <qchar.h>
#include <QWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>

class GUI : public QMainWindow
{
	Q_OBJECT

public:
	GUI(QWidget* parent = 0);
	~GUI() {}

private:
	QWidget* administratorLayout, * userLayout;
	CoatService coatService;
	QHBoxLayout* windowLayout;
	QListWidget *coatsList, *userList;
	QLineEdit* nameEdit, * sizeEdit, * priceEdit, * photographSourceEdit, * userCoatEdit;
	QPushButton* addCoatButton, * deleteCoatButton, * updateCoatButton, * filterCoatsButton, * openUserCoatsButton, * nextCoatButton, * listButton, * saveToMyListButton, * showUserListButton, * undoButton, * redoButton, * exitButton, * barChart;

	QAction* toUserMenu;
	QAction* toAdministratorMenu;


	void initializeGUI();
	void initializeAdministratorGUI();
	void initializeUserGUI();
	void initializeBarChart();

	void initializeConnections();

	void readSettings();

	int getSelectedIndex(QListWidget* list);
	void listItemSelected();
	void listItemSelectedUserList();
	
	void storeCoat();
	void listCoats();
	void deleteCoat();
	void updateCoat();
	void filterCoats();
	void undo();
	void redo();
	void saveCoatToUserList();
	void nextCoat();
	void openUserList();
};

