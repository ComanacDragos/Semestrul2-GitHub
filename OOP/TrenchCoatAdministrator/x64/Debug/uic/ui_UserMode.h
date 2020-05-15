/********************************************************************************
** Form generated from reading UI file 'UserMode.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMODE_H
#define UI_USERMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMode
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *userCoat;
    QPushButton *exitButton;

    void setupUi(QWidget *UserMode)
    {
        if (UserMode->objectName().isEmpty())
            UserMode->setObjectName(QString::fromUtf8("UserMode"));
        UserMode->resize(307, 149);
        verticalLayout = new QVBoxLayout(UserMode);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        userCoat = new QListWidget(UserMode);
        userCoat->setObjectName(QString::fromUtf8("userCoat"));

        verticalLayout->addWidget(userCoat);

        exitButton = new QPushButton(UserMode);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        verticalLayout->addWidget(exitButton);


        retranslateUi(UserMode);

        QMetaObject::connectSlotsByName(UserMode);
    } // setupUi

    void retranslateUi(QWidget *UserMode)
    {
        UserMode->setWindowTitle(QCoreApplication::translate("UserMode", "Form", nullptr));
        exitButton->setText(QCoreApplication::translate("UserMode", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserMode: public Ui_UserMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMODE_H
