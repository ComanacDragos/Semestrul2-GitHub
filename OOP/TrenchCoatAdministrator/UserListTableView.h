#pragma once

#include <QWidget>
#include "ui_UserListTableView.h"
#include "CoatService.h"
#include "CoatsTableModel.h"
#include "PictureDelegate.h"

class UserListTableView : public QWidget
{
	Q_OBJECT

public:
	UserListTableView(CoatService& service, QWidget *parent = Q_NULLPTR);
	~UserListTableView();

	void beginAddRow();
	void endAddRow();

private:
	CoatService& service;
	CoatsTableModel* tableModel;
	Ui::UserListTableView ui;

};
