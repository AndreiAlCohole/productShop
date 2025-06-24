#ifndef SELLERWINDOW_H
#define SELLERWINDOW_H

#include <QMainWindow>
#include <memory>
#include "User.h"
#include "AppController.h"
#include "Seller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SellerWindow; }
QT_END_NAMESPACE

class SellerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SellerWindow(std::shared_ptr<User> user, AppController* ctrl, QWidget *parent = nullptr);
    ~SellerWindow();

signals:
    void logoutRequested();

private slots:
    void on_createStoreButton_clicked();
    void on_addProductButton_clicked();
    void on_removeProductButton_clicked();
    void on_viewProductsButton_clicked();
    void on_viewStatisticsButton_clicked();
    void on_logoutButton_clicked();
    void on_editProductButton_clicked();
private:
    Ui::SellerWindow *ui;
    AppController* controller;
    std::shared_ptr<Seller> seller;

    void refreshProductList();
};

#endif // SELLERWINDOW_H
