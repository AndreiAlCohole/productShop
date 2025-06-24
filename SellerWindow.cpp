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
    QString sname = QInputDialog::getText(this, "Utwórz sklep", "Nazwa sklepu:", QLineEdit::Normal, "", &ok);
    if (ok && !sname.isEmpty()) {
        seller->createStore(sname.toStdString());
        QMessageBox::information(this, "Sukces", "Sklep utworzony.");
        ui->createStoreButton->setVisible(false);
    }
}

void SellerWindow::on_addProductButton_clicked()
{
    if (!seller->getStore()) {
        QMessageBox::warning(this, "Błąd", "Najpierw utwórz sklep.");
        return;
    }

    QString pname = QInputDialog::getText(this, "Dodaj produkt", "Nazwa:");
    double price = QInputDialog::getDouble(this, "Dodaj produkt", "Cena:");
    int qty = QInputDialog::getInt(this, "Dodaj produkt", "Ilość:");
    QString desc = QInputDialog::getText(this, "Dodaj produkt", "Opis:");

    // Zakładamy, że kategorie są pobierane z kontrolera
    QStringList catNames;
    auto cats = controller->getCategories();
    for (auto& c : cats)
        catNames << QString::fromStdString(c->getName());

    bool ok;
    QString selectedCat = QInputDialog::getItem(this, "Kategoria", "Wybierz kategorię:", catNames, 0, false, &ok);
    if (!ok || selectedCat.isEmpty()) return;

    int catIdx = catNames.indexOf(selectedCat);
    auto category = cats[catIdx];

    auto prod = std::make_shared<Product>(
        pname.toStdString(), price, qty, category,
        seller->getStore()->getName(), seller->getUsername(), desc.toStdString()
        );

    controller->getAllProducts().push_back(prod); // dodanie globalne
    seller->addProductToStore(prod);
    controller->saveData();
    QMessageBox::information(this, "Sukces", "Produkt dodany.");
    refreshProductList();
}

void SellerWindow::on_removeProductButton_clicked()
{
    if (!seller->getStore()) {
        QMessageBox::warning(this, "Brak sklepu", "Najpierw utwórz sklep.");
        return;
    }

    QString pname = QInputDialog::getText(this, "Usuń produkt", "Nazwa produktu:");
    if (!pname.isEmpty()) {
        std::string prodName = pname.toStdString();

        // Usuwamy z magazynu sprzedawcy
        seller->removeProductFromStore(prodName);

        // Usuwamy z globalnej listy allProducts w kontrolerze
        auto& products = controller->getAllProducts(); // musisz mieć funkcję zwracającą referencję do allProducts
        products.erase(std::remove_if(products.begin(), products.end(),
                                      [&](const std::shared_ptr<Product>& p) {
                                          return p->getName() == prodName && p->getStoreName() == seller->getStore()->getName();
                                      }), products.end());

        QMessageBox::information(this, "Usunięto", "Produkt usunięty.");
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
        ui->listWidgetProducts->addItem("Brak sklepu.");
        return;
    }
    std::cout<<"klik2";
    for (auto& p : seller->getStore()->getProducts()) {
        QString item = QString("%1 | Cena: %2 zł | Ilość: %3 | Ocena: %4\nOpis: %5")
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
        QMessageBox::warning(this, "Brak sklepu", "Najpierw utwórz sklep.");
        return;
    }

    int selectedIndex = ui->listWidgetProducts->currentRow();
    if (selectedIndex < 0 || selectedIndex >= static_cast<int>(seller->getStore()->getProducts().size())) {
        QMessageBox::warning(this, "Błąd", "Wybierz produkt do edycji.");
        return;
    }

    auto& products = seller->getStore()->getProducts();
    auto product = products[selectedIndex];

    // Edytuj nazwę
    bool ok;
    QString newName = QInputDialog::getText(this, "Edytuj produkt", "Nazwa:", QLineEdit::Normal,
                                            QString::fromStdString(product->getName()), &ok);
    if (!ok || newName.isEmpty())
        return;

    // Edytuj cenę
    double newPrice = QInputDialog::getDouble(this, "Edytuj produkt", "Cena:",
                                              product->getPrice(), 0, 1000000, 2, &ok);
    if (!ok)
        return;

    // Edytuj ilość
    int newQty = QInputDialog::getInt(this, "Edytuj produkt", "Ilość:",
                                      product->getQuantity(), 0, 1000000, 1, &ok);
    if (!ok)
        return;

    // Edytuj opis
    QString newDesc = QInputDialog::getText(this, "Edytuj produkt", "Opis:",
                                            QLineEdit::Normal,
                                            QString::fromStdString(product->getDescription()), &ok);
    if (!ok)
        return;

    // Ustaw nowe wartości w produkcie
    product->setName(newName.toStdString());
    product->setPrice(newPrice);
    product->setQuantity(newQty);
    product->setDescription(newDesc.toStdString());

    controller->saveData();

    QMessageBox::information(this, "Sukces", "Produkt zaktualizowany.");
    refreshProductList();
}


