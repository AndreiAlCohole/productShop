#include "Buyer.h"
#include "Product.h"

Buyer::Buyer(const std::string& name, const std::string& pass)
    : User(name, pass) {}

std::string Buyer::getType() const {
    return "Buyer";
}

void Buyer::addToCart(std::shared_ptr<Product> product, int qty) {
    if (product->getQuantity() >= qty) {
        for (int i = 0; i < qty; ++i) cart.push_back(product);
        std::cout << "Added " << qty << "x " << product->getName() << " to cart.\n";
    } else {
        std::cout << "Only " << product->getQuantity() << " in stock.\n";
    }
}

void Buyer::viewCart() {
    std::cout << "Your cart:\n";
    double total = 0;
    std::map<std::string, int> counter;
    for (auto& p : cart) {
        counter[p->getName()]++;
        total += p->getPrice();
    }
    for (auto& pair : counter) {
        std::cout << "- " << pair.first << " x" << pair.second << std::endl;
    }
    std::cout << "Total: $" << total << std::endl;
}

void Buyer::checkout() {
    if (cart.empty()) {
        std::cout << "Cart is empty.\n";
        return;
    }
    std::cout << "Purchasing...\n";
    std::map<std::shared_ptr<Product>, int> countMap;
    for (auto& p : cart) countMap[p]++;
    for (auto& [p, count] : countMap) {
        for (int i = 0; i < count; ++i) {
            p->decreaseQuantity();
            purchaseHistory.push_back(p);
        }
        p->addBuyer(username);
        p->increaseSoldCount(count);
    }
    cart.clear();
}

void Buyer::rateProduct(std::shared_ptr<Product> product, int rating, const std::string& comment) {
    if (rating >= 1 && rating <= 5) {
        if (product->wasBoughtBy(username)) {
            product->addReview(username, rating, comment);
            std::cout << "Review added.\n";
        } else {
            std::cout << "You can only review products you purchased.\n";
        }
    } else {
        std::cout << "Rating must be from 1 to 5.\n";
    }
}

void Buyer::viewPurchaseHistory() const {
    if (purchaseHistory.empty()) {
        std::cout << "No purchases yet.\n";
        return;
    }
    std::cout << "Purchase History:\n";
    std::map<std::string, int> counter;
    for (auto& p : purchaseHistory) {
        counter[p->getName()]++;
    }
    for (auto& [name, qty] : counter) {
        std::cout << "- " << name << " x" << qty << std::endl;
    }
}

void Buyer::save(std::ostream& os) const {
    os << "Buyer;" << username << ';' << password << '\n';
}

void Buyer::savePurchaseHistory(std::ostream& os) const {
    for (const auto& p : purchaseHistory) {
        os << username << ';' << p->getId() << '\n';
    }
}

void Buyer::setPurchaseHistory(const std::vector<std::shared_ptr<Product>>& history) {
    purchaseHistory = history;
}