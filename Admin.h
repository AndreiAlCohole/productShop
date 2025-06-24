#pragma once
#include "User.h"
#include "Store.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>

class Category;
class Product;

class Admin : public User {
public:
    Admin(const std::string& name, const std::string& pass);
    std::string getType() const override;

    void addCategory(std::vector<std::shared_ptr<Category>>& categories, const std::string& name);
    void viewUsers(const std::vector<std::shared_ptr<User>>& users) const;
    void deleteUser(std::vector<std::shared_ptr<User>>& users, const std::string& uname, std::vector<std::shared_ptr<Product>>& allProducts);
    void deleteProduct(std::vector<std::shared_ptr<Product>>& products, int id);
    void removeReviewFromProduct(std::shared_ptr<Product> p, const std::string& user, const std::string& comment);

};
