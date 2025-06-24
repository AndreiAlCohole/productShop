#include "AppController.h"
#include "Persistence.h"  // twoje funkcje load/save
using namespace std;
AppController::AppController()
{
    // Konstruktor - można tu coś inicjalizować
}

void AppController::loadData()
{
    categories = loadCategories();
    users = loadUsers();
    allProducts = loadProducts(categories);
    loadReviews(allProducts);
    loadPurchaseHistory(users, allProducts);

    // Dodaj admina jeśli trzeba
    bool hasAdmin = false;
    for (auto& u : users) {
        if (u->getType() == "Admin") {
            hasAdmin = true;
            break;
        }
    }
    if (!hasAdmin) {
        users.push_back(std::make_shared<Admin>("admin", "admin"));
    }

    // Mapa sklepów sprzedawców (unikamy wielokrotnego tworzenia)
    std::map<std::string, std::shared_ptr<Store>> sellerStores;

    for (const auto& product : allProducts) {
        std::string sellerName = product->getSellerName();
        std::string storeName = product->getStoreName();

        std::shared_ptr<Store> store;

        // Szukaj lub twórz sklep
        if (sellerStores.count(sellerName)) {
            store = sellerStores[sellerName];
        } else {
            store = std::make_shared<Store>(storeName, sellerName);
            sellerStores[sellerName] = store;

            // Przypisz do sprzedawcy
            for (auto& user : users) {
                if (user->getType() == "Seller" && user->getUsername() == sellerName) {
                    std::dynamic_pointer_cast<Seller>(user)->setStore(store);
                    break;
                }
            }
        }

        // Dodaj produkt do sklepu
        store->addProduct(product);
    }
}


void AppController::saveData()
{
    saveAll(users, allProducts, categories);
}

shared_ptr<User> AppController::login(const string& username, const string& password)
{
    for (auto& u : users) {
        if (u->getUsername() == username && u->checkPassword(password)) {
            return u;
        }
    }
    return nullptr;
}
void AppController::addUser(std::shared_ptr<User> user) {
    users.push_back(user);
    // opcjonalnie:
     saveAll(users, allProducts, categories);
}
std::vector<std::shared_ptr<Product>>& AppController::getAllProducts() {
    return allProducts;
}

const std::vector<std::shared_ptr<Product>>& AppController::getAllProducts() const {
    return allProducts;
}
// AppController.cpp
std::vector<std::shared_ptr<Category>> AppController::getCategories() const {
    return categories;
}

std::vector<std::shared_ptr<User>>& AppController::getUsers() {
    return users;
}
std::vector<std::shared_ptr<Category>>& AppController::getCategoriesRef() {
    return categories;
}
std::vector<std::shared_ptr<Product>>& AppController::getAllProductsRef() {
    return allProducts;
}


std::vector<std::shared_ptr<User>>& AppController::getUsersRef() {
    return users;
}


