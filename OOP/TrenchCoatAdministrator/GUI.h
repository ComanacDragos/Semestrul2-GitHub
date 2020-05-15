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

class GUI : public QWidget
{
	Q_OBJECT

public:
	GUI(QWidget* parent = 0);
	~GUI() {}

private:
	CoatService coatService;
	QHBoxLayout* windowLayout;
	QListWidget *coatsList, *userList;
	QLineEdit* nameEdit, * sizeEdit, * priceEdit, * photographSourceEdit;
	QPushButton* addCoatButton, * deleteCoatButton, * updateCoatButton, * filterCoatsButton, * openUserCoatsButton, * nextCoatButton, * listButton, * saveToMyListButton, * showUserListButton, * undoButton, * redoButton, * exitButton, * barChart;

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

