#pragma once

#include <QtWidgets/QWidget>
#include "ui_GUI.h"
#include "Service.h"
#include <qmessagebox.h>

class GUI : public QWidget, public Observer
{
    Q_OBJECT

public:
    GUI(Service& srv, QWidget *parent = Q_NULLPTR);

private:
    Ui::GUIClass ui;
    Service& srv;

    void loadData();

    void update()override
    {
        this->loadData();
    }
};
