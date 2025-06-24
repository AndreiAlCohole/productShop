#include "AdminWindow.h"
#include "ui_AdminWindow.h"
#include <QInputDialog>
#include <QMessageBox>

AdminWindow::AdminWindow(std::shared_ptr<User> user, AppController* ctrl, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::AdminWindow), controller(ctrl)
{
    ui->setupUi(this);
    admin = std::dynamic_pointer_cast<Admin>(user);
    refreshCategories();
    refreshProducts();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_viewUsersButton_clicked()
{
    ui->listWidgetUsers->clear();
    for (const auto& u : controller->getUsersRef()) {
        ui->listWidgetUsers->addItem(QString::fromStdString(u->getUsername() + " (" + u->getType() + ")"));
    }
}

void AdminWindow::on_addCategoryButton_clicked()
{
    bool ok;
    QString cname = QInputDialog::getText(this, "Dodaj kategorię", "Nazwa:", QLineEdit::Normal, "", &ok);
    if (ok && !cname.isEmpty()) {
        admin->addCategory(controller->getCategoriesRef(), cname.toStdString());
        refreshCategories();
    }
}

void AdminWindow::on_viewCategoriesButton_clicked()
{
    refreshCategories();
}

void AdminWindow::on_deleteCategoryButton_clicked()
{
    auto item = ui->listWidgetCategories->currentItem();
    if (!item) return;

    QString catName = item->text();
    auto& cats = controller->getCategoriesRef();
    cats.erase(std::remove_if(cats.begin(), cats.end(), [&](auto& c) {
                   return c->getName() == catName.toStdString();
               }), cats.end());

    refreshCategories();
}

void AdminWindow::on_viewProductsButton_clicked()
{
    refreshProducts();
}

void AdminWindow::on_deleteProductButton_clicked()
{
    auto item = ui->listWidgetProducts->currentItem();
    if (!item) return;

    QString text = item->text(); // Format: "ID: 123 | Name: xyz"
    int idStart = text.indexOf("ID: ") + 4;
    int idEnd = text.indexOf(" |");
    int id = text.mid(idStart, idEnd - idStart).toInt();

    auto& products = controller->getAllProductsRef();
    products.erase(std::remove_if(products.begin(), products.end(), [&](auto& p) {
                       return p->getId() == id;
                   }), products.end());

    refreshProducts();
}

// ----- pomocnicze funkcje -----

void AdminWindow::refreshCategories()
{
    ui->listWidgetCategories->clear();
    for (const auto& cat : controller->getCategoriesRef()) {
        ui->listWidgetCategories->addItem(QString::fromStdString(cat->getName()));
    }
}

void AdminWindow::refreshProducts()
{
    ui->listWidgetProducts->clear();
    for (const auto& p : controller->getAllProductsRef()) {
        QString entry = QString("ID: %1 | Name: %2 | Price: %3 zł")
                            .arg(p->getId())
                            .arg(QString::fromStdString(p->getName()))
                            .arg(p->getPrice());
        ui->listWidgetProducts->addItem(entry);
    }
}

void AdminWindow::on_buttonViewReviews_clicked()
{
    ui->comboBoxRatingFilter->setCurrentIndex(0); // reset filtra
    loadReviews(0); // 0 = brak filtra
}

void AdminWindow::loadReviews(int filterRating)
{
    ui->listWidgetReviews->clear();
    currentReviews.clear(); // zeruj poprzednie

    auto& products = controller->getAllProductsRef();

    for (const auto& product : products) {
        const std::string& productName = product->getName();

        for (const auto& review : product->getReviews()) {
            if (filterRating != 0 && review.getRating() != filterRating)
                continue;

            QString entry = QString("Produkt: %1 | Użytkownik: %2 | Ocena: %3 | Komentarz: %4")
                                .arg(QString::fromStdString(productName))
                                .arg(QString::fromStdString(review.getUsername()))
                                .arg(review.getRating())
                                .arg(QString::fromStdString(review.getComment()));

            ui->listWidgetReviews->addItem(entry);
            currentReviews.emplace_back(product, review); // zapamiętaj do późniejszego usuwania
        }
    }

    if (ui->listWidgetReviews->count() == 0)
        ui->listWidgetReviews->addItem("Brak opinii.");
}
void AdminWindow::on_comboBoxRatingFilter_currentIndexChanged(int index)
{
    if (index == 0)
        loadReviews(0); // wszystkie
    else
        loadReviews(index); // tylko o wybranej ocenie
}


void AdminWindow::on_buttonDeleteReview_clicked()
{
    auto selected = ui->listWidgetReviews->currentRow();
    if (selected < 0 || selected >= static_cast<int>(currentReviews.size())) return;

    auto& [product, review] = currentReviews[selected];
    product->removeSpecificReview(review.getUsername(), review.getComment());

    // Odświeżenie
    int currentFilter = ui->comboBoxRatingFilter->currentIndex(); // 0 = wszystkie
    loadReviews(currentFilter);
}





void AdminWindow::on_logoutButton_clicked()
{
    emit logoutRequested();
    this->close(); // opcjonalnie zamykasz okno
}

