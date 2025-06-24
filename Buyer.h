#pragma once
#include "User.h"
#include <vector>
#include <memory>
#include <string>
#include <map>
#include <iostream>

class Product;

class Buyer : public User {
    std::vector<std::shared_ptr<Product>> cart;
    std::vector<std::shared_ptr<Product>> purchaseHistory;
public:
    Buyer(const std::string& name, const std::string& pass);
    std::string getType() const override;

    void addToCart(std::shared_ptr<Product> product, int qty);
    void removeFromCart(std::shared_ptr<Product> product, int qty);
    void viewCart();
    void checkout();
    void rateProduct(std::shared_ptr<Product> product, int rating, const std::string& comment);
    void viewPurchaseHistory() const;
    void save(std::ostream& os) const;
    void savePurchaseHistory(std::ostream& os) const;
    void setPurchaseHistory(const std::vector<std::shared_ptr<Product>>& history);
    std::vector<std::shared_ptr<Product>> getCart() const { return cart; }
    std::vector<std::shared_ptr<Product>> getPurchaseHistory() ;

};
