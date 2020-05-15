#include "GraphicalUserInterface.h"

GraphicalUserInterface::GraphicalUserInterface(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setStyleSheet(
		"QWidget{background-color: black; color: rgb(128, 233, 210);}"
		"QPushButton{background-color:rgb(128, 233, 210);color: black; border-radius: 15px;padding:10px;box-shadow: 5px 10px;}"
		"QPushButton:hover{background-color: rgb(0, 153, 120);color: black;}"
		"QMenu:hover{background-color: rgb(0, 153, 120);color: black;}"
	);
	
}

GraphicalUserInterface::~GraphicalUserInterface()
{
}
