/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *tasksList;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *descEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *removeTask;
    QPushButton *startButton;
    QPushButton *doneButton;

    void setupUi(QWidget *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QString::fromUtf8("GUIClass"));
        GUIClass->resize(600, 400);
        verticalLayout = new QVBoxLayout(GUIClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tasksList = new QListWidget(GUIClass);
        tasksList->setObjectName(QString::fromUtf8("tasksList"));

        verticalLayout->addWidget(tasksList);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(GUIClass);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        descEdit = new QLineEdit(GUIClass);
        descEdit->setObjectName(QString::fromUtf8("descEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, descEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addButton = new QPushButton(GUIClass);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout->addWidget(addButton);

        removeTask = new QPushButton(GUIClass);
        removeTask->setObjectName(QString::fromUtf8("removeTask"));

        horizontalLayout->addWidget(removeTask);

        startButton = new QPushButton(GUIClass);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        horizontalLayout->addWidget(startButton);

        doneButton = new QPushButton(GUIClass);
        doneButton->setObjectName(QString::fromUtf8("doneButton"));

        horizontalLayout->addWidget(doneButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QWidget *GUIClass)
    {
        GUIClass->setWindowTitle(QCoreApplication::translate("GUIClass", "GUI", nullptr));
        label->setText(QCoreApplication::translate("GUIClass", "Description", nullptr));
        addButton->setText(QCoreApplication::translate("GUIClass", "Add", nullptr));
        removeTask->setText(QCoreApplication::translate("GUIClass", "Remove", nullptr));
        startButton->setText(QCoreApplication::translate("GUIClass", "Start", nullptr));
        doneButton->setText(QCoreApplication::translate("GUIClass", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
