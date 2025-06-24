#pragma once
#include "User.h"
#include <memory>
#include <string>
#include <iostream>

class Store;
class Product;

class Seller : public User {
    std::shared_ptr<Store> store;
public:
    Seller(const std::string& name, const std::string& pass);
    std::string getType() const override;
    void createStore(const std::string& storeName);
    std::shared_ptr<Store> getStore() const;
    void addProductToStore(std::shared_ptr<Product> p);
    void removeProductFromStore(const std::string& productName);
    void viewSalesHistory() const;
    void save(std::ostream& os) const;
};