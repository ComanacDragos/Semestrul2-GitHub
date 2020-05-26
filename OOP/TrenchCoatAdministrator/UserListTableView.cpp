#include "UserListTableView.h"

UserListTableView::UserListTableView(CoatService& service, QWidget *parent)
	: service{ service }, QWidget(parent)
{
	ui.setupUi(this);
	this->tableModel = new CoatsTableModel{ this->service };
	ui.userTableView->setModel(this->tableModel);
	ui.userTableView->resizeColumnsToContents();
	ui.userTableView->verticalHeader()->hide();	
}

UserListTableView::~UserListTableView()
{
}

void UserListTableView::beginAddRow()
{
	this->tableModel->beginAddRow();
}

void UserListTableView::endAddRow()
{
	this->tableModel->endAddRow();
}

