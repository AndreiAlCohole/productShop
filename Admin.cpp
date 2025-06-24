#include "Admin.h"
#include "Category.h"
#include "Product.h"
#include "Seller.h"
#include "Store.h"
#include <algorithm>

Admin::Admin(const std::string& name, const std::string& pass)
    : User(name, pass) {}

std::string Admin::getType() const {
    return "Admin";
}

void Admin::addCategory(std::vector<std::shared_ptr<Category>>& categories, const std::string& name) {
    categories.push_back(std::make_shared<Category>(name));
}

void Admin::viewUsers(const std::vector<std::shared_ptr<User>>& users) const {
    for (auto& user : users) {
        std::cout << "User: " << user->getUsername() << " (" << user->getType() << ")\n";
    }
}

void Admin::deleteUser(std::vector<std::shared_ptr<User>>& users, const std::string& uname, std::vector<std::shared_ptr<Product>>& allProducts) {
    auto it = std::find_if(users.begin(), users.end(), [&](std::shared_ptr<User> u) {
        return u->getUsername() == uname;
    });

    if (it != users.end()) {
        auto seller = std::dynamic_pointer_cast<Seller>(*it);
        if (seller && seller->getStore()) {
            auto sellerProducts = seller->getStore()->getProducts();
            for (auto& sp : sellerProducts) {
                allProducts.erase(std::remove_if(allProducts.begin(), allProducts.end(),
                    [&](std::shared_ptr<Product> p) {
                        return p->getId() == sp->getId();
                    }), allProducts.end());
            }
        }
        users.erase(it);
        std::cout << "User removed.\n";
    } else {
        std::cout << "User not found.\n";
    }
}

void Admin::deleteProduct(std::vector<std::shared_ptr<Product>>& products, int id) {
    auto it = std::remove_if(products.begin(), products.end(), [&](std::shared_ptr<Product> p) {
        return p->getId() == id;
    });
    if (it != products.end()) {
        products.erase(it, products.end());
        std::cout << "Product removed.\n";
    } else {
        std::cout << "Product not found.\n";
    }
}
void Admin::removeReviewFromProduct(std::shared_ptr<Product> p, const std::string& user, const std::string& comment) {
    p->removeSpecificReview(user, comment);
}
