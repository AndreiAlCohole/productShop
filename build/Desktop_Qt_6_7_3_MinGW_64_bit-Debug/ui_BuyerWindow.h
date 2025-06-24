/********************************************************************************
** Form generated from reading UI file 'BuyerWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYERWINDOW_H
#define UI_BUYERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuyerWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *viewProductsButton;
    QComboBox *comboBoxSort;
    QVBoxLayout *verticalLayout_6;
    QListWidget *listViewProducts;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addToCartButton;
    QSpinBox *spinBoxQuantity;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QSpinBox *spinBoxRating;
    QTextEdit *textEditReview;
    QPushButton *buttonAddReview;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *textEditReviewComment;
    QListWidget *listWidgetCart;
    QPushButton *logoutButton;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonRemoveFromCart;
    QVBoxLayout *verticalLayout_3;
    QPushButton *viewCartButton;
    QPushButton *checkoutButton;
    QLabel *labelTotalPrice;
    QVBoxLayout *verticalLayout_2;
    QPushButton *viewPurchaseHistoryButton;
    QListWidget *listWidgetPurchaseHistory;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BuyerWindow)
    {
        if (BuyerWindow->objectName().isEmpty())
            BuyerWindow->setObjectName("BuyerWindow");
        BuyerWindow->resize(1048, 554);
        centralwidget = new QWidget(BuyerWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 1015, 481));
        horizontalLayout_7 = new QHBoxLayout(widget);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        viewProductsButton = new QPushButton(widget);
        viewProductsButton->setObjectName("viewProductsButton");

        horizontalLayout_2->addWidget(viewProductsButton);

        comboBoxSort = new QComboBox(widget);
        comboBoxSort->addItem(QString());
        comboBoxSort->addItem(QString());
        comboBoxSort->addItem(QString());
        comboBoxSort->addItem(QString());
        comboBoxSort->addItem(QString());
        comboBoxSort->setObjectName("comboBoxSort");

        horizontalLayout_2->addWidget(comboBoxSort);


        verticalLayout_7->addLayout(horizontalLayout_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        listViewProducts = new QListWidget(widget);
        listViewProducts->setObjectName("listViewProducts");

        verticalLayout_6->addWidget(listViewProducts);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer = new QSpacerItem(308, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        addToCartButton = new QPushButton(widget);
        addToCartButton->setObjectName("addToCartButton");

        horizontalLayout_3->addWidget(addToCartButton);

        spinBoxQuantity = new QSpinBox(widget);
        spinBoxQuantity->setObjectName("spinBoxQuantity");

        horizontalLayout_3->addWidget(spinBoxQuantity);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout_7->addLayout(verticalLayout_6);


        verticalLayout_8->addLayout(verticalLayout_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        spinBoxRating = new QSpinBox(widget);
        spinBoxRating->setObjectName("spinBoxRating");
        spinBoxRating->setMinimum(1);
        spinBoxRating->setMaximum(5);

        verticalLayout->addWidget(spinBoxRating);

        textEditReview = new QTextEdit(widget);
        textEditReview->setObjectName("textEditReview");

        verticalLayout->addWidget(textEditReview);

        buttonAddReview = new QPushButton(widget);
        buttonAddReview->setObjectName("buttonAddReview");

        verticalLayout->addWidget(buttonAddReview);


        horizontalLayout_6->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        textEditReviewComment = new QTextEdit(widget);
        textEditReviewComment->setObjectName("textEditReviewComment");

        horizontalLayout_5->addWidget(textEditReviewComment);

        listWidgetCart = new QListWidget(widget);
        listWidgetCart->setObjectName("listWidgetCart");

        horizontalLayout_5->addWidget(listWidgetCart);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        logoutButton = new QPushButton(widget);
        logoutButton->setObjectName("logoutButton");

        horizontalLayout_6->addWidget(logoutButton);


        verticalLayout_8->addLayout(horizontalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout_8);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        buttonRemoveFromCart = new QPushButton(widget);
        buttonRemoveFromCart->setObjectName("buttonRemoveFromCart");

        horizontalLayout->addWidget(buttonRemoveFromCart);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        viewCartButton = new QPushButton(widget);
        viewCartButton->setObjectName("viewCartButton");

        verticalLayout_3->addWidget(viewCartButton);

        checkoutButton = new QPushButton(widget);
        checkoutButton->setObjectName("checkoutButton");

        verticalLayout_3->addWidget(checkoutButton);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        labelTotalPrice = new QLabel(widget);
        labelTotalPrice->setObjectName("labelTotalPrice");

        verticalLayout_4->addWidget(labelTotalPrice);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        viewPurchaseHistoryButton = new QPushButton(widget);
        viewPurchaseHistoryButton->setObjectName("viewPurchaseHistoryButton");

        verticalLayout_2->addWidget(viewPurchaseHistoryButton);

        listWidgetPurchaseHistory = new QListWidget(widget);
        listWidgetPurchaseHistory->setObjectName("listWidgetPurchaseHistory");

        verticalLayout_2->addWidget(listWidgetPurchaseHistory);


        verticalLayout_5->addLayout(verticalLayout_2);


        horizontalLayout_7->addLayout(verticalLayout_5);

        BuyerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BuyerWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1048, 25));
        BuyerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(BuyerWindow);
        statusbar->setObjectName("statusbar");
        BuyerWindow->setStatusBar(statusbar);

        retranslateUi(BuyerWindow);

        QMetaObject::connectSlotsByName(BuyerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BuyerWindow)
    {
        BuyerWindow->setWindowTitle(QCoreApplication::translate("BuyerWindow", "MainWindow", nullptr));
        viewProductsButton->setText(QCoreApplication::translate("BuyerWindow", "Products", nullptr));
        comboBoxSort->setItemText(0, QCoreApplication::translate("BuyerWindow", "Default", nullptr));
        comboBoxSort->setItemText(1, QCoreApplication::translate("BuyerWindow", "Price Up", nullptr));
        comboBoxSort->setItemText(2, QCoreApplication::translate("BuyerWindow", "Price Down", nullptr));
        comboBoxSort->setItemText(3, QCoreApplication::translate("BuyerWindow", "Quanity Up", nullptr));
        comboBoxSort->setItemText(4, QCoreApplication::translate("BuyerWindow", "Quanity Down", nullptr));

        addToCartButton->setText(QCoreApplication::translate("BuyerWindow", "addToCart", nullptr));
        buttonAddReview->setText(QCoreApplication::translate("BuyerWindow", "Add reviev", nullptr));
        logoutButton->setText(QCoreApplication::translate("BuyerWindow", "Wyloguj", nullptr));
        buttonRemoveFromCart->setText(QCoreApplication::translate("BuyerWindow", "Remove", nullptr));
        viewCartButton->setText(QCoreApplication::translate("BuyerWindow", "View Cart", nullptr));
        checkoutButton->setText(QCoreApplication::translate("BuyerWindow", "Checkout", nullptr));
        labelTotalPrice->setText(QCoreApplication::translate("BuyerWindow", "TextLabel", nullptr));
        viewPurchaseHistoryButton->setText(QCoreApplication::translate("BuyerWindow", "History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuyerWindow: public Ui_BuyerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYERWINDOW_H
