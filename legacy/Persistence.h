#pragma once
#include <vector>
#include <memory>
#include "Category.h"
#include "User.h"
#include "Product.h"

// Save functions
void saveCategories(const std::vector<std::shared_ptr<Category>>& categories);
void saveAll(const std::vector<std::shared_ptr<User>>& users,
             const std::vector<std::shared_ptr<Product>>& products,
             const std::vector<std::shared_ptr<Category>>& categories);

// Load functions
std::vector<std::shared_ptr<Category>> loadCategories();
std::vector<std::shared_ptr<User>> loadUsers();
std::vector<std::shared_ptr<Product>> loadProducts(const std::vector<std::shared_ptr<Category>>& categories);
void loadReviews(std::vector<std::shared_ptr<Product>>& products);
void loadPurchaseHistory(std::vector<std::shared_ptr<User>>& users, const std::vector<std::shared_ptr<Product>>& products);