#include "Seller.h"
#include "Store.h"
#include "Product.h"

Seller::Seller(const std::string& name, const std::string& pass)
    : User(name, pass) {}

std::string Seller::getType() const {
    return "Seller";
}

void Seller::createStore(const std::string& storeName) {
    store = std::make_shared<Store>(storeName, username);
}

std::shared_ptr<Store> Seller::getStore() const {
    return store;
}
void Seller::setStore(std::shared_ptr<Store> s) {
    store = s;
}
void Seller::addProductToStore(std::shared_ptr<Product> p) {
    if (store) store->addProduct(p);
    else std::cout << "Store not created yet.\n";
}

void Seller::removeProductFromStore(const std::string& productName) {
    if (store) store->removeProduct(productName);
    else std::cout << "Store not created yet.\n";
}

void Seller::viewSalesHistory() const {
    if (!store) {
        std::cout << "No store.\n";
        return;
    }
    std::cout << "Sales Stats for store: " << store->getName() << "\n";
    for (auto& product : store->getProducts()) {
        std::cout << "- " << product->getName() << ": "
                  << product->getSoldCount() << " sold, "
                  << product->uniqueBuyersCount() << " unique buyers.\n";
    }
}

void Seller::save(std::ostream& os) const {
    os << "Seller;" << username << ';' << password << '\n';
}
