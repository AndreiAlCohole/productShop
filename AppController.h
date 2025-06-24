#pragma once

#include <vector>
#include <memory>
#include <string>

#include "User.h"
#include "Product.h"
#include "Category.h"
#include "Admin.h"
#include "Buyer.h"
#include "Seller.h"
#include "Store.h"
class AppController {
public:
    AppController();

    void loadData();
    void saveData();

    std::shared_ptr<User> login(const std::string& username, const std::string& password);
    void addUser(std::shared_ptr<User> user);

    std::vector<std::shared_ptr<Product>>& getAllProducts();                      // nie-const
    const std::vector<std::shared_ptr<Product>>& getAllProducts() const;

    std::shared_ptr<Product> findProductById(int id) const;
    // AppController.h (dodaj w public:)
    std::vector<std::shared_ptr<Category>> getCategories() const;

    std::vector<std::shared_ptr<User>>& getUsers(); // umożliwia modyfikację
    std::vector<std::shared_ptr<Category>>& getCategoriesRef();
    std::vector<std::shared_ptr<Product>>& getAllProductsRef();

    std::vector<std::shared_ptr<User>>& getUsersRef();


private:
    std::vector<std::shared_ptr<User>> users;
    std::vector<std::shared_ptr<Category>> categories;
    std::vector<std::shared_ptr<Product>> allProducts;
};
