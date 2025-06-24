#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>

class Product;

class Store {
    std::string storeName;
    std::string sellerName;
    std::vector<std::shared_ptr<Product>> products;
public:
    Store(const std::string& name, const std::string& seller);
    std::string getName() const;
    std::string getSellerName() const;
    void addProduct(std::shared_ptr<Product> p);
    void removeProduct(const std::string& productName);
    double averageStoreRating() const;
    const std::vector<std::shared_ptr<Product>>& getProducts() const;
};
