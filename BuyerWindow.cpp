#include "BuyerWindow.h"
#include "ui_BuyerWindow.h"

#include <QMessageBox>
#include <QStringListModel>
using namespace std;
BuyerWindow::BuyerWindow(std::shared_ptr<User> user, AppController* ctrl, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::BuyerWindow), controller(ctrl)
{
    ui->setupUi(this);

    buyer = std::dynamic_pointer_cast<Buyer>(user);
    connect(ui->comboBoxSort, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &BuyerWindow::onSortChanged);

    ui->listViewProducts->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listViewProducts, &QListWidget::customContextMenuRequested,
            this, &BuyerWindow::showProductContextMenu);
    loadProducts();
}

BuyerWindow::~BuyerWindow()
{
    delete ui;
}



    void BuyerWindow::loadProducts()
    {
        auto products = controller->getAllProducts();

        int sortIndex = ui->comboBoxSort->currentIndex();

        // sortowanie w zależności od wyboru
        switch (sortIndex) {
        case 1: // Cena rosnąco
            std::sort(products.begin(), products.end(),
                      [](auto& a, auto& b) { return a->getPrice() < b->getPrice(); });
            break;
        case 2: // Cena malejąco
            std::sort(products.begin(), products.end(),
                      [](auto& a, auto& b) { return a->getPrice() > b->getPrice(); });
            break;
        case 3: // Ilość rosnąco
            std::sort(products.begin(), products.end(),
                      [](auto& a, auto& b) { return a->getQuantity() < b->getQuantity(); });
            break;
        case 4: // Ilość malejąco
            std::sort(products.begin(), products.end(),
                      [](auto& a, auto& b) { return a->getQuantity() > b->getQuantity(); });
            break;
        default:
            break; // domyślne - bez sortowania
        }

        ui->listViewProducts->clear();

        for (auto& p : products) {
            QString itemText = QString("%1 | Price: %2 zł | Quantity: %3")
                                   .arg(QString::fromStdString(p->getName()))
                                   .arg(p->getPrice())
                                   .arg(p->getQuantity());
            ui->listViewProducts->addItem(itemText);
        }
    }



void BuyerWindow::on_addToCartButton_clicked()
{
     cout << "Kliklo: " <<endl;
    QModelIndexList selectedIndexes = ui->listViewProducts->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Error", "Select a product to add.");
        return;
    }

    int selectedIndex = selectedIndexes.first().row();
    auto products = controller->getAllProducts();
    if (selectedIndex < 0 || selectedIndex >= static_cast<int>(products.size())) {
        QMessageBox::warning(this, "Error", "Invalid product selection.");
        return;
    }

    bool ok;
    int qty = ui->spinBoxQuantity->value();
    if (qty <= 0) {
        QMessageBox::warning(this, "Error", "Enter a quantity greater than 0.");
        return;
    }

    auto product = products[selectedIndex];
    if (product->getQuantity() < qty) {
        QMessageBox::warning(this, "Error", "Insufficient product quantity in stock.");
        return;
    }

    buyer->addToCart(product, qty);

    QMessageBox::information(this, "Success", "Added to cart.");
}

void BuyerWindow::on_viewCartButton_clicked()
{
    QString cartDetails;
    std::map<std::string, int> counter;

    for (auto& p : buyer->getCart()) {  
        counter[p->getName()]++;
    }

    double total = 0;
    for (auto& [name, qty] : counter) {
        cartDetails += QString::fromStdString(name) + " x" + QString::number(qty) + "\n";

        // Do wyliczenia sumy trzeba znaleźć cenę produktu
        for (auto& p : buyer->getCart()) {
            if (p->getName() == name) {
                total += p->getPrice() * qty;
                break;
            }
        }
    }
    cartDetails += "Total: " + QString::number(total) + " zł";
    QMessageBox::information(this, "Your cart", cartDetails);
}

void BuyerWindow::on_checkoutButton_clicked()
{
    if (buyer->getCart().empty()) {
        QMessageBox::information(this, "Cart empty", "Your cart is empty.");
        return;
    }
    buyer->checkout();
    controller->saveData();

    QMessageBox::information(this, "Purchase complete", "Thank you for your purchase!");

    loadProducts();  // odświeżenie listy produktów po zakupie
}

void BuyerWindow::on_viewPurchaseHistoryButton_clicked()
{/*
    QString historyDetails;
    std::map<std::string, int> counter;

    for (auto& p : buyer->getPurchaseHistory()) { // tu trzeba dodać getPurchaseHistory() w Buyer
        counter[p->getName()]++;
    }

    if (counter.empty()) {
        QMessageBox::information(this, "Historia zakupów", "Brak zakupów.");
        return;
    }

    for (auto& [name, qty] : counter) {
        historyDetails += QString::fromStdString(name) + " x" + QString::number(qty) + "\n";
    }

    QMessageBox::information(this, "Historia zakupów", historyDetails);*/

        ui->listWidgetPurchaseHistory->clear(); // wyczyść listę historii

        auto history = buyer->getPurchaseHistory();
        if (history.empty()) {
            ui->listWidgetPurchaseHistory->addItem("No purchases.");
            return;
        }

        std::map<std::string, std::pair<double, int>> grouped; // name -> {price, qty}

        for (auto& p : history) {
            grouped[p->getName()].first = p->getPrice();
            grouped[p->getName()].second++;
        }

        for (const auto& [name, pair] : grouped) {
            QString itemText = QString("%1 | Price: %2 zł | Quantity: %3")
                                   .arg(QString::fromStdString(name))
                                   .arg(pair.first)
                                   .arg(pair.second);
            ui->listWidgetPurchaseHistory->addItem(itemText);
        }
    }


void BuyerWindow::onSortChanged(int index)
{
    loadProducts();
}


void BuyerWindow::on_logoutButton_clicked()
{
    emit logoutRequested();
    this->close();
}

void BuyerWindow::on_comboBoxSort_currentIndexChanged(int index)
{

}

void BuyerWindow::on_buttonRemoveFromCart_clicked()
{
    QModelIndexList selectedIndexes = ui->listViewProducts->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Error", "Select a product to remove.");
        return;
    }

    int selectedIndex = selectedIndexes.first().row();
    auto products = controller->getAllProducts();
    if (selectedIndex < 0 || selectedIndex >= static_cast<int>(products.size())) {
        QMessageBox::warning(this, "Error", "Invalid product selection.");
        return;
    }

    int qty = ui->spinBoxQuantity->value();
    if (qty <= 0) {
        QMessageBox::warning(this, "Error", "Enter a quantity greater than 0.");
        return;
    }

    auto product = products[selectedIndex];
    buyer->removeFromCart(product, qty);

    QMessageBox::information(this, "Success", "Removed from cart.");
}

void BuyerWindow::on_buttonAddReview_clicked()
{
    QModelIndexList selectedIndexes = ui->listViewProducts->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Error", "Select a product to review.");
        return;
    }

    int selectedIndex = selectedIndexes.first().row();
    auto products = controller->getAllProducts();
    if (selectedIndex < 0 || selectedIndex >= static_cast<int>(products.size())) {
        QMessageBox::warning(this, "Error", "Invalid product selection.");
        return;
    }

    QString reviewText = ui->textEditReview->toPlainText();
    if (reviewText.isEmpty()) {
        QMessageBox::warning(this, "Error", "Review cannot be empty.");
        return;
    }

    int rating = ui->spinBoxRating->value();  // QSpinBox do oceny
    if (rating < 1 || rating > 5) {
        QMessageBox::warning(this, "Error", "Rating must be between 1 and 5.");
        return;
    }

    auto product = products[selectedIndex];

    product->addReview(buyer->getUsername(), rating, reviewText.toStdString());

    QMessageBox::information(this, "Success", "Review added.");

    ui->textEditReview->clear(); // czyścimy pole opinii po dodaniu
    ui->spinBoxRating->setValue(5); 

    controller->saveData();  // zapisujemy dane po dodaniu opinii
}

void BuyerWindow::showProductContextMenu(const QPoint& pos)
{
    QListWidgetItem* item = ui->listViewProducts->itemAt(pos);
    if (!item) return;

    QMenu contextMenu;
    QAction* viewReviewsAction = contextMenu.addAction("Show reviews");
    QAction* addToCartAction = contextMenu.addAction("Add to cart");

    QAction* selectedAction = contextMenu.exec(ui->listViewProducts->viewport()->mapToGlobal(pos));
    if (!selectedAction) return;

    int index = ui->listViewProducts->row(item);
    auto products = controller->getAllProducts();

    if (index < 0 || index >= static_cast<int>(products.size())) return;

    auto product = products[index];

    if (selectedAction == viewReviewsAction) {
        QString reviewsText;
        for (const auto& review : product->getReviews()) {
            reviewsText += QString("User: %1\nRating: %2/5\nComment: %3\n\n")
            .arg(QString::fromStdString(review.getUsername()))
                .arg(review.getRating())
                .arg(QString::fromStdString(review.getComment()));
        }
        if (reviewsText.isEmpty())
            reviewsText = "No reviews for this product.";

        QMessageBox::information(this, "Reviews", reviewsText);
    }
    else if (selectedAction == addToCartAction) {
        int quantity = 1;

        if (product->getQuantity() < quantity) {
            QMessageBox::warning(this, "Error", "Insufficient quantity in stock.");
            return;
        }

        buyer->addToCart(product, quantity);
        QMessageBox::information(this, "Added", "Product added to cart.");
    }
}




