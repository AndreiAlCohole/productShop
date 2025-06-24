/********************************************************************************
** Form generated from reading UI file 'RegisterWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QPushButton *pushButton_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *usernameEdit;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QComboBox *accountTypeComboBox;
    QPushButton *registerButton;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(400, 300);
        pushButton_2 = new QPushButton(RegisterWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(300, 260, 90, 29));
        widget = new QWidget(RegisterWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(130, 40, 127, 190));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        usernameEdit = new QLineEdit(widget);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout->addWidget(usernameEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        passwordEdit = new QLineEdit(widget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(passwordEdit);

        accountTypeComboBox = new QComboBox(widget);
        accountTypeComboBox->addItem(QString());
        accountTypeComboBox->addItem(QString());
        accountTypeComboBox->setObjectName("accountTypeComboBox");

        verticalLayout->addWidget(accountTypeComboBox);

        registerButton = new QPushButton(widget);
        registerButton->setObjectName("registerButton");

        verticalLayout->addWidget(registerButton);


        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RegisterWindow", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "UserName", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterWindow", "Password", nullptr));
        accountTypeComboBox->setItemText(0, QCoreApplication::translate("RegisterWindow", "Buyer", nullptr));
        accountTypeComboBox->setItemText(1, QCoreApplication::translate("RegisterWindow", "Seller", nullptr));

        registerButton->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
