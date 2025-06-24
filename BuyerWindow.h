#pragma once

#include <QMainWindow>
#include <memory>
#include <vector>

#include "Buyer.h"
#include "AppController.h"

namespace Ui {
class BuyerWindow;
}

class BuyerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BuyerWindow(std::shared_ptr<User> user, AppController* controller, QWidget *parent = nullptr);
    ~BuyerWindow();

signals:
    void logoutRequested();

private slots:
    void on_addToCartButton_clicked();
    void on_checkoutButton_clicked();
    void on_logoutButton_clicked();
    void on_viewCartButton_clicked();
    void on_viewPurchaseHistoryButton_clicked();
    void onSortChanged(int index);
    void showProductContextMenu(const QPoint& pos);

    void on_buttonAddReview_clicked();

    void on_comboBoxSort_currentIndexChanged(int index);

    void on_buttonRemoveFromCart_clicked();

private:
    Ui::BuyerWindow *ui;
    std::shared_ptr<Buyer> buyer;
    AppController* controller;


    void loadProducts();
    void updateCartDisplay();
    void updatePurchaseHistoryDisplay();
};
