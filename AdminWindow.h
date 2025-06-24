#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "Admin.h"
#include "AppController.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(std::shared_ptr<User> user, AppController* controller, QWidget *parent = nullptr);
    ~AdminWindow();

signals:
    void logoutRequested();  // <-- tutaj dodajesz sygnał

private slots:
    void on_viewUsersButton_clicked();
    void on_addCategoryButton_clicked();
    void on_deleteCategoryButton_clicked();
    void on_viewProductsButton_clicked();
    void on_deleteProductButton_clicked();
    void on_viewCategoriesButton_clicked();
    void on_buttonViewReviews_clicked();
    void on_logoutButton_clicked();
    void loadReviews(int filterRating);
    void on_buttonDeleteReview_clicked();
    void on_comboBoxRatingFilter_currentIndexChanged(int index);

private:
    Ui::AdminWindow *ui;
    std::shared_ptr<Admin> admin;
    AppController* controller;
    std::vector<std::pair<std::shared_ptr<Product>, Review>> currentReviews; // do usuwania

    void refreshProducts();
    void refreshCategories();
};

#endif // ADMINWINDOW_H
