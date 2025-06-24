#include "SellerWindow.h"
#include "ui_SellerWindow.h"
#include <QInputDialog>
#include <QMessageBox>

SellerWindow::SellerWindow(std::shared_ptr<User> user, AppController* ctrl, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SellerWindow), controller(ctrl)
{
    ui->setupUi(this);
    seller = std::dynamic_pointer_cast<Seller>(user);
    if (seller->getStore()) {
        // Ukryj przycisk jeśli sklep już istnieje
        ui->createStoreButton->setVisible(false);
         refreshProductList();
    }
    else{
        ui->createStoreButton->setVisible(true);
    }
}

SellerWindow::~SellerWindow()
{
    delete ui;
}

void SellerWindow::on_createStoreButton_clicked()
{
    bool ok;
    QString sname = QInputDialog::getText(this, "Create store", "Store name:", QLineEdit::Normal, "", &ok);
    if (ok && !sname.isEmpty()) {
        seller->createStore(sname.toStdString());
        QMessageBox::information(this, "Success", "Store created.");
        ui->createStoreButton->setVisible(false);
    }
}

void SellerWindow::on_addProductButton_clicked()
{
    if (!seller->getStore()) {
        QMessageBox::warning(this, "No store", "Create a store first.");
        return;
    }

    QString pname = QInputDialog::getText(this, "Add product", "Name:");
    double price = QInputDialog::getDouble(this, "Add product", "Price:");
    int qty = QInputDialog::getInt(this, "Add product", "Quantity:");
    QString desc = QInputDialog::getText(this, "Add product", "Description:");

    // Categories from controller
    QStringList catNames;
    auto cats = controller->getCategories();
    for (auto& c : cats)
        catNames << QString::fromStdString(c->getName());

    bool ok;
    QString selectedCat = QInputDialog::getItem(this, "Category", "Select category:", catNames, 0, false, &ok);
    if (!ok || selectedCat.isEmpty()) return;

    int catIdx = catNames.indexOf(selectedCat);
    auto category = cats[catIdx];

    auto prod = std::make_shared<Product>(
        pname.toStdString(), price, qty, category,
        seller->getStore()->getName(), seller->getUsername(), desc.toStdString()
        );

    controller->getAllProducts().push_back(prod);
    seller->addProductToStore(prod);
    controller->saveData();
    QMessageBox::information(this, "Success", "Product added.");
    refreshProductList();
}

void SellerWindow::on_removeProductButton_clicked()
{
    if (!seller->getStore()) {
        QMessageBox::warning(this, "No store", "Create a store first.");
        return;
    }

    QString pname = QInputDialog::getText(this, "Remove product", "Product name:");
    if (!pname.isEmpty()) {
        std::string prodName = pname.toStdString();

        seller->removeProductFromStore(prodName);

        auto& products = controller->getAllProducts();
        products.erase(std::remove_if(products.begin(), products.end(),
                                      [&](const std::shared_ptr<Product>& p) {
                                          return p->getName() == prodName && p->getStoreName() == seller->getStore()->getName();
                                      }), products.end());

        QMessageBox::information(this, "Removed", "Product removed.");
        refreshProductList();
    }
}


void SellerWindow::on_viewProductsButton_clicked()
{
    refreshProductList();
}

void SellerWindow::on_viewStatisticsButton_clicked()
{
    QString stats;
    // Zakładamy, że Seller::viewSalesHistory() może zwracać np. string lub podobny
    //stats = QString::fromStdString(seller->viewSalesHistory());
    //QMessageBox::information(this, "Historia sprzedaży", stats);
}

void SellerWindow::on_logoutButton_clicked()
{
    emit logoutRequested();
    this->close();
}

void SellerWindow::refreshProductList()
{
    ui->listWidgetProducts->clear();

    if (!seller->getStore()) {
        ui->listWidgetProducts->addItem("No store.");
        return;
    }
    std::cout<<"klik2";
    for (auto& p : seller->getStore()->getProducts()) {
        QString item = QString("%1 | Price: %2 zł | Quantity: %3 | Rating: %4\nDescription: %5")
                           .arg(QString::fromStdString(p->getName()))
                           .arg(p->getPrice())
                           .arg(p->getQuantity())
                           .arg(p->averageRating())
                           .arg(QString::fromStdString(p->getDescription()));
        ui->listWidgetProducts->addItem(item);
        std::cout<<"klik3";
    }
}
void SellerWindow::on_editProductButton_clicked()
{
    if (!seller->getStore()) {
        QMessageBox::warning(this, "No store", "Create a store first.");
        return;
    }

    int selectedIndex = ui->listWidgetProducts->currentRow();
    if (selectedIndex < 0 || selectedIndex >= static_cast<int>(seller->getStore()->getProducts().size())) {
        QMessageBox::warning(this, "Error", "Select a product to edit.");
        return;
    }

    auto& products = seller->getStore()->getProducts();
    auto product = products[selectedIndex];

    // Edit name
    bool ok;
    QString newName = QInputDialog::getText(this, "Edit product", "Name:", QLineEdit::Normal,
                                            QString::fromStdString(product->getName()), &ok);
    if (!ok || newName.isEmpty())
        return;

    // Edit price
    double newPrice = QInputDialog::getDouble(this, "Edit product", "Price:",
                                              product->getPrice(), 0, 1000000, 2, &ok);
    if (!ok)
        return;

    // Edit quantity
    int newQty = QInputDialog::getInt(this, "Edit product", "Quantity:",
                                      product->getQuantity(), 0, 1000000, 1, &ok);
    if (!ok)
        return;

    // Edit description
    QString newDesc = QInputDialog::getText(this, "Edit product", "Description:",
                                            QLineEdit::Normal,
                                            QString::fromStdString(product->getDescription()), &ok);
    if (!ok)
        return;

    product->setName(newName.toStdString());
    product->setPrice(newPrice);
    product->setQuantity(newQty);
    product->setDescription(newDesc.toStdString());

    controller->saveData();

    QMessageBox::information(this, "Success", "Product updated.");
    refreshProductList();
}


