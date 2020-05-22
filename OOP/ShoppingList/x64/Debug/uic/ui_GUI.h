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
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *itemsList;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLineEdit *categoryEdit;
    QPushButton *listButton;
    QPushButton *filterButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QString::fromUtf8("GUIClass"));
        GUIClass->resize(600, 400);
        verticalLayout_2 = new QVBoxLayout(GUIClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        itemsList = new QListWidget(GUIClass);
        itemsList->setObjectName(QString::fromUtf8("itemsList"));

        verticalLayout->addWidget(itemsList);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(GUIClass);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        nameEdit = new QLineEdit(GUIClass);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        label_2 = new QLabel(GUIClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        categoryEdit = new QLineEdit(GUIClass);
        categoryEdit->setObjectName(QString::fromUtf8("categoryEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, categoryEdit);


        verticalLayout->addLayout(formLayout);

        listButton = new QPushButton(GUIClass);
        listButton->setObjectName(QString::fromUtf8("listButton"));

        verticalLayout->addWidget(listButton);

        filterButton = new QPushButton(GUIClass);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));

        verticalLayout->addWidget(filterButton);

        deleteButton = new QPushButton(GUIClass);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        verticalLayout->addWidget(deleteButton);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QWidget *GUIClass)
    {
        GUIClass->setWindowTitle(QCoreApplication::translate("GUIClass", "GUI", nullptr));
        label->setText(QCoreApplication::translate("GUIClass", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("GUIClass", "Category", nullptr));
        listButton->setText(QCoreApplication::translate("GUIClass", "List", nullptr));
        filterButton->setText(QCoreApplication::translate("GUIClass", "Filter", nullptr));
        deleteButton->setText(QCoreApplication::translate("GUIClass", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
