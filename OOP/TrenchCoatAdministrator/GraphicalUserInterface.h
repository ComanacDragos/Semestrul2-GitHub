#pragma once

#include <QWidget>
#include "ui_GraphicalUserInterface.h"
#include "ui_UserMode.h"

class GraphicalUserInterface : public QMainWindow
{
	Q_OBJECT

public:
	GraphicalUserInterface(QWidget *parent = Q_NULLPTR);
	~GraphicalUserInterface();

private:
	Ui::MainWindow ui;
	Ui::UserMode userUi;


};
