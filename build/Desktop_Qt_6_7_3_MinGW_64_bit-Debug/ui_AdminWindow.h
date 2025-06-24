/********************************************************************************
** Form generated from reading UI file 'AdminWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QPushButton *logoutButton;
    QPushButton *removeReviewButton;
    QPushButton *buttonViewReviews;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *deleteUserButton;
    QPushButton *viewUsersButton;
    QListWidget *listWidgetUsers;
    QVBoxLayout *verticalLayout_4;
    QListWidget *listWidgetCategories;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *deleteCategoryButton;
    QPushButton *addCategoryButton;
    QPushButton *viewCategoriesButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *deleteProductButton;
    QPushButton *viewProductsButton;
    QListWidget *listWidgetProducts;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBoxRatingFilter;
    QPushButton *buttonDeleteReview;
    QListWidget *listWidgetReviews;
    QMenuBar *menubar;
    QMenu *menuAdmin_cocpit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(800, 600);
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName("centralwidget");
        logoutButton = new QPushButton(centralwidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(690, 510, 90, 29));
        removeReviewButton = new QPushButton(centralwidget);
        removeReviewButton->setObjectName("removeReviewButton");
        removeReviewButton->setGeometry(QRect(670, 360, 90, 29));
        buttonViewReviews = new QPushButton(centralwidget);
        buttonViewReviews->setObjectName("buttonViewReviews");
        buttonViewReviews->setGeometry(QRect(570, 360, 90, 29));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 0, 461, 513));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        deleteUserButton = new QPushButton(layoutWidget);
        deleteUserButton->setObjectName("deleteUserButton");

        horizontalLayout_2->addWidget(deleteUserButton);

        viewUsersButton = new QPushButton(layoutWidget);
        viewUsersButton->setObjectName("viewUsersButton");

        horizontalLayout_2->addWidget(viewUsersButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        listWidgetUsers = new QListWidget(layoutWidget);
        listWidgetUsers->setObjectName("listWidgetUsers");

        verticalLayout_2->addWidget(listWidgetUsers);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        listWidgetCategories = new QListWidget(layoutWidget);
        listWidgetCategories->setObjectName("listWidgetCategories");

        verticalLayout_4->addWidget(listWidgetCategories);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        deleteCategoryButton = new QPushButton(layoutWidget);
        deleteCategoryButton->setObjectName("deleteCategoryButton");

        horizontalLayout_3->addWidget(deleteCategoryButton);

        addCategoryButton = new QPushButton(layoutWidget);
        addCategoryButton->setObjectName("addCategoryButton");

        horizontalLayout_3->addWidget(addCategoryButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        viewCategoriesButton = new QPushButton(layoutWidget);
        viewCategoriesButton->setObjectName("viewCategoriesButton");

        verticalLayout_3->addWidget(viewCategoriesButton);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        deleteProductButton = new QPushButton(layoutWidget);
        deleteProductButton->setObjectName("deleteProductButton");

        horizontalLayout->addWidget(deleteProductButton);

        viewProductsButton = new QPushButton(layoutWidget);
        viewProductsButton->setObjectName("viewProductsButton");

        horizontalLayout->addWidget(viewProductsButton);


        verticalLayout->addLayout(horizontalLayout);

        listWidgetProducts = new QListWidget(layoutWidget);
        listWidgetProducts->setObjectName("listWidgetProducts");

        verticalLayout->addWidget(listWidgetProducts);


        verticalLayout_5->addLayout(verticalLayout);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(500, 110, 258, 232));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        comboBoxRatingFilter = new QComboBox(layoutWidget1);
        comboBoxRatingFilter->addItem(QString());
        comboBoxRatingFilter->addItem(QString());
        comboBoxRatingFilter->addItem(QString());
        comboBoxRatingFilter->addItem(QString());
        comboBoxRatingFilter->addItem(QString());
        comboBoxRatingFilter->addItem(QString());
        comboBoxRatingFilter->setObjectName("comboBoxRatingFilter");
        comboBoxRatingFilter->setMaxVisibleItems(5);

        horizontalLayout_5->addWidget(comboBoxRatingFilter);

        buttonDeleteReview = new QPushButton(layoutWidget1);
        buttonDeleteReview->setObjectName("buttonDeleteReview");

        horizontalLayout_5->addWidget(buttonDeleteReview);


        verticalLayout_6->addLayout(horizontalLayout_5);

        listWidgetReviews = new QListWidget(layoutWidget1);
        listWidgetReviews->setObjectName("listWidgetReviews");

        verticalLayout_6->addWidget(listWidgetReviews);

        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuAdmin_cocpit = new QMenu(menubar);
        menuAdmin_cocpit->setObjectName("menuAdmin_cocpit");
        AdminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminWindow);
        statusbar->setObjectName("statusbar");
        AdminWindow->setStatusBar(statusbar);

        menubar->addAction(menuAdmin_cocpit->menuAction());

        retranslateUi(AdminWindow);

        comboBoxRatingFilter->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "MainWindow", nullptr));
        logoutButton->setText(QCoreApplication::translate("AdminWindow", "Wyloguj", nullptr));
        removeReviewButton->setText(QCoreApplication::translate("AdminWindow", "Censore", nullptr));
        buttonViewReviews->setText(QCoreApplication::translate("AdminWindow", "Show Revievs", nullptr));
        deleteUserButton->setText(QCoreApplication::translate("AdminWindow", "Delete User", nullptr));
        viewUsersButton->setText(QCoreApplication::translate("AdminWindow", "Urzytkownicy", nullptr));
        deleteCategoryButton->setText(QCoreApplication::translate("AdminWindow", "Delete Category", nullptr));
        addCategoryButton->setText(QCoreApplication::translate("AdminWindow", "Add category", nullptr));
        viewCategoriesButton->setText(QCoreApplication::translate("AdminWindow", "Refresh Categories", nullptr));
        deleteProductButton->setText(QCoreApplication::translate("AdminWindow", "Delete product", nullptr));
        viewProductsButton->setText(QCoreApplication::translate("AdminWindow", "Refresh Producs", nullptr));
        comboBoxRatingFilter->setItemText(0, QCoreApplication::translate("AdminWindow", "0", nullptr));
        comboBoxRatingFilter->setItemText(1, QCoreApplication::translate("AdminWindow", "1", nullptr));
        comboBoxRatingFilter->setItemText(2, QCoreApplication::translate("AdminWindow", "2", nullptr));
        comboBoxRatingFilter->setItemText(3, QCoreApplication::translate("AdminWindow", "3", nullptr));
        comboBoxRatingFilter->setItemText(4, QCoreApplication::translate("AdminWindow", "4", nullptr));
        comboBoxRatingFilter->setItemText(5, QCoreApplication::translate("AdminWindow", "5", nullptr));

        buttonDeleteReview->setText(QCoreApplication::translate("AdminWindow", "Delete Revievs", nullptr));
        menuAdmin_cocpit->setTitle(QCoreApplication::translate("AdminWindow", "Admin cocpit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
