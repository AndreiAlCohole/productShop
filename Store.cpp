#include "Store.h"
#include "Product.h"
#include <algorithm>

Store::Store(const std::string& name, const std::string& seller)
    : storeName(name), sellerName(seller) {}

std::string Store::getName() const { return storeName; }
std::string Store::getSellerName() const { return sellerName; }

void Store::addProduct(std::shared_ptr<Product> p) {
    products.push_back(p);
}

void Store::removeProduct(const std::string& productName) {
    auto it = std::remove_if(products.begin(), products.end(), [&](std::shared_ptr<Product> p) {
        return p->getName() == productName;
    });
    if (it != products.end()) {
        products.erase(it, products.end());
        std::cout << "Product removed: " << productName << std::endl;
    } else {
        std::cout << "Product not found: " << productName << std::endl;
    }
}

double Store::averageStoreRating() const {
    if (products.empty()) return 0.0;
    double total = 0;
    for (auto& p : products) {
        total += p->averageRating();
    }
    return total / products.size();
}

const std::vector<std::shared_ptr<Product>>& Store::getProducts() const {
    return products;
}
