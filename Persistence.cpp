#include "Persistence.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include "Buyer.h"
#include "Seller.h"
#include "Admin.h"
#include "Review.h"

using namespace std;

void saveCategories(const vector<shared_ptr<Category>>& categories) {
    ofstream catFile("categories.txt");
    for (const auto& c : categories) {
        catFile << c->getName() << '\n';
    }
    catFile.close();
}

void saveAll(const vector<shared_ptr<User>>& users, const vector<shared_ptr<Product>>& products, const vector<shared_ptr<Category>>& categories) {
    // Save users
    ofstream userFile("users.txt");
    for (const auto& u : users) {
        if (u->getType() == "Buyer")
            dynamic_pointer_cast<Buyer>(u)->save(userFile);
        else if (u->getType() == "Seller")
            dynamic_pointer_cast<Seller>(u)->save(userFile);
        // Add Admin if needed
    }
    userFile.close();

    // Save products
    ofstream prodFile("products.txt");
    for (const auto& p : products) {
        p->save(prodFile);
    }
    prodFile.close();

    // Save categories
    saveCategories(categories);

    // Save reviews
    ofstream reviewFile("reviews.txt");
    for (const auto& p : products) {
        p->saveReviews(reviewFile);
    }
    reviewFile.close();

    // Save purchase history
    ofstream phFile("purchase_history.txt");
    for (const auto& u : users) {
        if (u->getType() == "Buyer")
            dynamic_pointer_cast<Buyer>(u)->savePurchaseHistory(phFile);
    }
    phFile.close();
}

vector<shared_ptr<Category>> loadCategories() {
    vector<shared_ptr<Category>> categories;
    ifstream catFile("categories.txt");
    string name;
    while (getline(catFile, name)) {
        if (!name.empty())
            categories.push_back(make_shared<Category>(name));
    }
    return categories;
}

vector<shared_ptr<User>> loadUsers() {
    vector<shared_ptr<User>> users;
    ifstream userFile("users.txt");
    if (!userFile.is_open()) {
        cerr << "Cannot open users.txt file" << endl;
        return {};
    }

    string line;
    while (getline(userFile, line)) {
        istringstream iss(line);
        string type, username, password;
        getline(iss, type, ';');
        getline(iss, username, ';');
        getline(iss, password, ';');
        if (type == "Buyer")
            users.push_back(make_shared<Buyer>(username, password));
        else if (type == "Seller")
            users.push_back(make_shared<Seller>(username, password));
        else if (type == "Admin")
            users.push_back(make_shared<Admin>(username, password));
        else
            cerr << "Unknown type: " << type << endl;
    }
    return users;
}

vector<shared_ptr<Product>> loadProducts(const vector<shared_ptr<Category>>& categories) {
    vector<shared_ptr<Product>> products;
    ifstream prodFile("products.txt");
    string line;
    while (getline(prodFile, line)) {
        istringstream iss(line);
        string idStr, name, priceStr, qtyStr, desc, catName, storeName, sellerName, soldStr;
        getline(iss, idStr, ';');
        getline(iss, name, ';');
        getline(iss, priceStr, ';');
        getline(iss, qtyStr, ';');
        getline(iss, desc, ';');
        getline(iss, catName, ';');
        getline(iss, storeName, ';');
        getline(iss, sellerName, ';');
        getline(iss, soldStr, ';');
        double price = stod(priceStr);
        int qty = stoi(qtyStr);
        int sold = stoi(soldStr);
        auto catIt = find_if(categories.begin(), categories.end(), [&](shared_ptr<Category> c) {
            return c->getName() == catName;
        });
        if (catIt != categories.end()) {
            auto prod = make_shared<Product>(name, price, qty, *catIt, storeName, sellerName, desc);
            prod->increaseSoldCount(sold);
            products.push_back(prod);
        }
    }
    return products;
}

void loadReviews(vector<shared_ptr<Product>>& products) {
    ifstream reviewFile("reviews.txt");
    string line;
    while (getline(reviewFile, line)) {
        istringstream iss(line);
        string idStr, username, ratingStr, comment;
        getline(iss, idStr, ';');
        getline(iss, username, ';');
        getline(iss, ratingStr, ';');
        getline(iss, comment, ';');
        int id = stoi(idStr);
        int rating = stoi(ratingStr);
        auto it = find_if(products.begin(), products.end(), [&](shared_ptr<Product> p) {
            return p->getId() == id;
        });
        if (it != products.end()) {
            (*it)->addReview(username, rating, comment);
        }
    }
}

void loadPurchaseHistory(vector<shared_ptr<User>>& users, const vector<shared_ptr<Product>>& products) {
    ifstream phFile("purchase_history.txt");
    string line;
    map<string, vector<shared_ptr<Product>>> buyerPurchases;
    while (getline(phFile, line)) {
        istringstream iss(line);
        string username, idStr;
        getline(iss, username, ';');
        getline(iss, idStr, ';');
        int id = stoi(idStr);
        auto prodIt = find_if(products.begin(), products.end(), [&](shared_ptr<Product> p) {
            return p->getId() == id;
        });
        if (prodIt != products.end()) {
            buyerPurchases[username].push_back(*prodIt);
        }
    }
    // Restore purchase history and product stats WITHOUT calling checkout()
    for (auto& [username, prods] : buyerPurchases) {
        auto userIt = find_if(users.begin(), users.end(), [&](shared_ptr<User> u) {
            return u->getUsername() == username && u->getType() == "Buyer";
        });
        if (userIt != users.end()) {
            auto buyer = dynamic_pointer_cast<Buyer>(*userIt);
            buyer->setPurchaseHistory(prods);
            for (auto& p : prods) {
                p->addBuyer(username);
            }
        }
    }
}
