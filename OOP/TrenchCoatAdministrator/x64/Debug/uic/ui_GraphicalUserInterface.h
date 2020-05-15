/********************************************************************************
** Form generated from reading UI file 'GraphicalUserInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICALUSERINTERFACE_H
#define UI_GRAPHICALUSERINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QListWidget *coatsList;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLineEdit *sizeEdit;
    QLineEdit *priceEdit;
    QLineEdit *photographSourceEdit;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *addCoatButton;
    QPushButton *deleteCoatButton;
    QPushButton *updateCoatButton;
    QPushButton *filterCoatsButton;
    QPushButton *listButton;
    QGridLayout *gridLayout_2;
    QPushButton *redoButton;
    QPushButton *undoButton;
    QPushButton *exitButton;
    QMenuBar *menubar;
    QMenu *menuAdministrator_Mode;
    QMenu *menuUser_Mode;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(662, 656);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        coatsList = new QListWidget(centralwidget);
        coatsList->setObjectName(QString::fromUtf8("coatsList"));

        verticalLayout->addWidget(coatsList);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        sizeEdit = new QLineEdit(centralwidget);
        sizeEdit->setObjectName(QString::fromUtf8("sizeEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, sizeEdit);

        priceEdit = new QLineEdit(centralwidget);
        priceEdit->setObjectName(QString::fromUtf8("priceEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, priceEdit);

        photographSourceEdit = new QLineEdit(centralwidget);
        photographSourceEdit->setObjectName(QString::fromUtf8("photographSourceEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, photographSourceEdit);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);


        verticalLayout->addLayout(formLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        addCoatButton = new QPushButton(centralwidget);
        addCoatButton->setObjectName(QString::fromUtf8("addCoatButton"));

        gridLayout->addWidget(addCoatButton, 0, 0, 1, 1);

        deleteCoatButton = new QPushButton(centralwidget);
        deleteCoatButton->setObjectName(QString::fromUtf8("deleteCoatButton"));

        gridLayout->addWidget(deleteCoatButton, 0, 1, 1, 2);

        updateCoatButton = new QPushButton(centralwidget);
        updateCoatButton->setObjectName(QString::fromUtf8("updateCoatButton"));

        gridLayout->addWidget(updateCoatButton, 0, 3, 1, 1);

        filterCoatsButton = new QPushButton(centralwidget);
        filterCoatsButton->setObjectName(QString::fromUtf8("filterCoatsButton"));

        gridLayout->addWidget(filterCoatsButton, 2, 0, 1, 4);

        listButton = new QPushButton(centralwidget);
        listButton->setObjectName(QString::fromUtf8("listButton"));

        gridLayout->addWidget(listButton, 1, 0, 1, 4);


        verticalLayout_2->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        redoButton = new QPushButton(centralwidget);
        redoButton->setObjectName(QString::fromUtf8("redoButton"));

        gridLayout_2->addWidget(redoButton, 0, 1, 1, 1);

        undoButton = new QPushButton(centralwidget);
        undoButton->setObjectName(QString::fromUtf8("undoButton"));

        gridLayout_2->addWidget(undoButton, 0, 0, 1, 1);

        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        gridLayout_2->addWidget(exitButton, 1, 0, 1, 2);


        verticalLayout_2->addLayout(gridLayout_2);


        verticalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 662, 21));
        menuAdministrator_Mode = new QMenu(menubar);
        menuAdministrator_Mode->setObjectName(QString::fromUtf8("menuAdministrator_Mode"));
        menuUser_Mode = new QMenu(menubar);
        menuUser_Mode->setObjectName(QString::fromUtf8("menuUser_Mode"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAdministrator_Mode->menuAction());
        menubar->addAction(menuUser_Mode->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Source", nullptr));
        addCoatButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        deleteCoatButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        updateCoatButton->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        filterCoatsButton->setText(QCoreApplication::translate("MainWindow", "Filter coats", nullptr));
        listButton->setText(QCoreApplication::translate("MainWindow", "List coats", nullptr));
        redoButton->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        undoButton->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menuAdministrator_Mode->setTitle(QCoreApplication::translate("MainWindow", "Administrator Mode", nullptr));
        menuUser_Mode->setTitle(QCoreApplication::translate("MainWindow", "User Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICALUSERINTERFACE_H
