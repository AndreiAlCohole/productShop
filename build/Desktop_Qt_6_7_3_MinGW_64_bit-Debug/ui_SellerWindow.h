/********************************************************************************
** Form generated from reading UI file 'SellerWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELLERWINDOW_H
#define UI_SELLERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SellerWindow
{
public:
    QWidget *centralwidget;
    QPushButton *logoutButton;
    QPushButton *createStoreButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidgetProducts;
    QVBoxLayout *verticalLayout;
    QPushButton *addProductButton;
    QPushButton *removeProductButton;
    QPushButton *viewProductsButton;
    QPushButton *editProductButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SellerWindow)
    {
        if (SellerWindow->objectName().isEmpty())
            SellerWindow->setObjectName("SellerWindow");
        SellerWindow->resize(800, 600);
        centralwidget = new QWidget(SellerWindow);
        centralwidget->setObjectName("centralwidget");
        logoutButton = new QPushButton(centralwidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(620, 520, 90, 29));
        createStoreButton = new QPushButton(centralwidget);
        createStoreButton->setObjectName("createStoreButton");
        createStoreButton->setGeometry(QRect(20, 10, 90, 29));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(120, 40, 591, 451));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidgetProducts = new QListWidget(layoutWidget);
        listWidgetProducts->setObjectName("listWidgetProducts");

        horizontalLayout->addWidget(listWidgetProducts);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        addProductButton = new QPushButton(layoutWidget);
        addProductButton->setObjectName("addProductButton");

        verticalLayout->addWidget(addProductButton);

        removeProductButton = new QPushButton(layoutWidget);
        removeProductButton->setObjectName("removeProductButton");

        verticalLayout->addWidget(removeProductButton);

        viewProductsButton = new QPushButton(layoutWidget);
        viewProductsButton->setObjectName("viewProductsButton");

        verticalLayout->addWidget(viewProductsButton);

        editProductButton = new QPushButton(layoutWidget);
        editProductButton->setObjectName("editProductButton");

        verticalLayout->addWidget(editProductButton);


        horizontalLayout->addLayout(verticalLayout);

        SellerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SellerWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        SellerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SellerWindow);
        statusbar->setObjectName("statusbar");
        SellerWindow->setStatusBar(statusbar);

        retranslateUi(SellerWindow);

        QMetaObject::connectSlotsByName(SellerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SellerWindow)
    {
        SellerWindow->setWindowTitle(QCoreApplication::translate("SellerWindow", "MainWindow", nullptr));
        logoutButton->setText(QCoreApplication::translate("SellerWindow", "Wyloguj", nullptr));
        createStoreButton->setText(QCoreApplication::translate("SellerWindow", "Create Store", nullptr));
        addProductButton->setText(QCoreApplication::translate("SellerWindow", "Add product", nullptr));
        removeProductButton->setText(QCoreApplication::translate("SellerWindow", "Remove product", nullptr));
        viewProductsButton->setText(QCoreApplication::translate("SellerWindow", "View Products", nullptr));
        editProductButton->setText(QCoreApplication::translate("SellerWindow", "Edit Product", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SellerWindow: public Ui_SellerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLERWINDOW_H
