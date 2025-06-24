#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <numeric>
#include <algorithm>
#include <set>
#include <fstream>
#include <sstream>
#include "User.h"
#include "Buyer.h"
#include "Seller.h"
#include "Admin.h"
#include "Product.h"
#include "Store.h"
#include "Category.h"
#include "Review.h"
#include "Persistence.h"

using namespace std;



int main() {
    vector<shared_ptr<User>> users;
    vector<shared_ptr<Category>> categories;
    vector<shared_ptr<Product>> allProducts;

    cout << "1. Lo1ad saved data\n2. Start with pre-created data\nChoose option: ";
    int startOption;
    cin >> startOption;

    if (startOption == 1) {
       
        categories = loadCategories();
        users = loadUsers();
        allProducts = loadProducts(categories);
        loadReviews(allProducts);
        loadPurchaseHistory(users, allProducts);

        // Restore sellers' stores and products
        for (auto& user : users) {
            if (user->getType() == "Seller") {
                auto seller = dynamic_pointer_cast<Seller>(user);
                // Find all products for this seller
                vector<shared_ptr<Product>> sellerProducts;
                string storeName;
                for (const auto& p : allProducts) {
                    if (p->getSellerName() == seller->getUsername()) {
                        sellerProducts.push_back(p);
                        storeName = p->getStoreName();
                    }
                }
                if (!storeName.empty()) {
                    seller->createStore(storeName);
                    for (const auto& p : sellerProducts) {
                        seller->addProductToStore(p);
                    }
                }
            }
        }
         auto admin = make_shared<Admin>("admin", "admin");
        users.push_back(admin);
    } else {
        // --- PRE-CREATED BUYER, SELLER, STORE, PRODUCTS ---
        auto admin = make_shared<Admin>("admin", "admin");
        users.push_back(admin);
        admin->addCategory(categories, "Elektronika");
admin->addCategory(categories, "Moda");
admin->addCategory(categories, "Obuwie");
admin->addCategory(categories, "Zdrowie i Uroda");
admin->addCategory(categories, "Dom i Ogród");
admin->addCategory(categories, "Sport i Turystyka");
admin->addCategory(categories, "Zabawki i Gry");
admin->addCategory(categories, "Motoryzacja");
admin->addCategory(categories, "Książki i Komiksy");
admin->addCategory(categories, "Artykuły biurowe i szkolne");
admin->addCategory(categories, "AGD i RTV");
admin->addCategory(categories, "Artykuły spożywcze");
admin->addCategory(categories, "Narzędzia i Majsterkowanie");
admin->addCategory(categories, "Zwierzęta i akcesoria");
admin->addCategory(categories, "Dziecko i Mama");
admin->addCategory(categories, "Gry komputerowe i konsole");
admin->addCategory(categories, "Rękodzieło i artykuły handmade");
admin->addCategory(categories, "Sztuka i Dekoracje");
admin->addCategory(categories, "Muzyka i Filmy");
admin->addCategory(categories, "E-booki i Produkty cyfrowe");

        // Create buyer
        auto preBuyer = make_shared<Buyer>("testbuyer", "buyer123");
        users.push_back(preBuyer);

        // Create seller and store
        auto preSeller = make_shared<Seller>("testseller", "seller123");
        preSeller->createStore("TestShop");
        users.push_back(preSeller);

        // Create 5 products and add to store and allProducts
        vector<shared_ptr<Product>> preProducts;
        preProducts.push_back(make_shared<Product>("Laptop", 2999.99, 10, categories[0], preSeller->getStore()->getName(), preSeller->getUsername(), "Gaming laptop"));
        preProducts.push_back(make_shared<Product>("Smartphone", 1999.99, 15, categories[0], preSeller->getStore()->getName(), preSeller->getUsername(), "Latest model"));
        preProducts.push_back(make_shared<Product>("Headphones", 299.99, 20, categories[0], preSeller->getStore()->getName(), preSeller->getUsername(), "Noise cancelling"));
        preProducts.push_back(make_shared<Product>("T-shirt", 49.99, 50, categories[1], preSeller->getStore()->getName(), preSeller->getUsername(), "Cotton, size M"));
        preProducts.push_back(make_shared<Product>("Sneakers", 299.99, 30, categories[1], preSeller->getStore()->getName(), preSeller->getUsername(), "Comfortable running shoes"));

        for (auto& prod : preProducts) {
            preSeller->addProductToStore(prod);
            allProducts.push_back(prod);
        }
        // --- END PRE-CREATED DATA ---
    }

    shared_ptr<User> currentUser = nullptr;
    bool running = true;

    while (running) {
        if (!currentUser) {
            cout << "\n1. Log in\n2. Register\n3. Exit\nChoose option: ";
            int option;
            cin >> option;
            if (option == 1) {
                string login, pass;
                cout << "Login: "; cin >> login;
                cout << "Password: "; cin >> pass;
                for (auto& u : users) {
                    if (u->getUsername() == login && u->checkPassword(pass)) {
                        currentUser = u;
                        cout << "Logged in as " << u->getType() << endl;
                        break;
                    }
                }
                if (!currentUser) cout << "Invalid credentials.\n";
            } else if (option == 2) {
                string type, login, pass;
                cout << "Register as (buyer/seller): "; cin >> type;
                cout << "Username: "; cin >> login;
                cout << "Password: "; cin >> pass;
                if (type == "buyer") {
                    users.push_back(make_shared<Buyer>(login, pass));
                    cout << "Buyer registered.\n";
                } else if (type == "seller") {
                    users.push_back(make_shared<Seller>(login, pass));
                    cout << "Seller registered.\n";
                } else {
                    cout << "Invalid type.\n";
                }
            } else if (option == 3) {
                running = false;
            }
        } else if (currentUser->getType() == "Admin") {
            auto adm = dynamic_pointer_cast<Admin>(currentUser);
            cout << "\nAdmin Menu:\n1. View users\n2. Add category\n3. Delete user\n4. Delete product\n5. Remove review\n6. Logout\nChoose: ";
            int opt; cin >> opt;
            if (opt == 1) adm->viewUsers(users);
            else if (opt == 2) {
                string cname; cout << "Category name: "; cin >> cname;
                adm->addCategory(categories, cname);
            } else if (opt == 3) {
                string uname; cout << "Username to delete: "; cin >> uname;
                adm->deleteUser(users, uname, allProducts);
            } else if (opt == 4) {
                int id; cout << "Product ID to delete: "; cin >> id;
                adm->deleteProduct(allProducts, id);
            } else if (opt == 5) {
                int id; string uname;
                cout << "Product ID: "; cin >> id;
                cout << "Username to remove review from: "; cin >> uname;
                auto it = find_if(allProducts.begin(), allProducts.end(), [&](shared_ptr<Product> p) {
                    return p->getId() == id;
                });
                if (it != allProducts.end()) adm->removeReviewFromProduct(*it, uname);
                else cout << "Product not found.\n";
            } else if (opt == 6) currentUser = nullptr;
        } else if (currentUser->getType() == "Seller") {
            auto seller = dynamic_pointer_cast<Seller>(currentUser);
            cout << "\nSeller Menu:\n1. Create store\n2. Add product\n3. Remove product\n4. View products\n5. View Statistic\n6. Logout\nChoose: ";
 int opt; cin >> opt;
            if (opt == 1) {
                string sname; cout << "Store name: "; cin >> sname;
                seller->createStore(sname);
            } else if (opt == 2) {
                if (!seller->getStore()) { cout << "Store not created.\n"; continue; }
                string pname, desc; double price; int qty, catIdx;
                cout << "Product name: "; cin >> pname;
                cout << "Price: "; cin >> price;
                cout << "Quantity: "; cin >> qty;
                cout << "Description: "; cin.ignore(); getline(cin, desc);
                cout << "Choose category:\n";
                for (int i = 0; i < categories.size(); ++i)
                    cout << i << ". " << categories[i]->getName() << "\n";
                cin >> catIdx;
                auto prod = make_shared<Product>(pname, price, qty, categories[catIdx], seller->getStore()->getName(), seller->getUsername(), desc);
                allProducts.push_back(prod);
                seller->addProductToStore(prod);
            } else if (opt == 3) {
                string pname; cout << "Product name to remove: "; cin >> pname;
                seller->removeProductFromStore(pname);
            } else if (opt == 4) {
                if (!seller->getStore()) { cout << "No store.\n"; continue; }
                for (auto& p : seller->getStore()->getProducts()) {
                    cout << p->getId() << ". " << p->getName()
                         << " ($" << p->getPrice() << ") Qty: " << p->getQuantity()
                         << " Rating: " << p->averageRating()
                         << "\nDesc: " << p->getDescription() << "\n";
                    p->showReviews();
                }
            } else if (opt == 5) seller->viewSalesHistory();
else if (opt == 6) currentUser = nullptr;

        } else if (currentUser->getType() == "Buyer") {
            auto buyer = dynamic_pointer_cast<Buyer>(currentUser);
            cout << "\nBuyer Menu:\n1. View products\n2. Add to cart\n3. View cart\n4. Checkout\n5. Rate product\n6. View history\n7. Logout\nChoose: ";
        int opt; cin >> opt;
            if (opt == 1) {
                cout << "Sort by:\n1. Name\n2. Price\n3. Average rating\nChoose: ";
    int sortOpt; cin >> sortOpt;
    cout << "Order:\n1. Ascending\n2. Descending\nChoose: ";
    int orderOpt; cin >> orderOpt;
    vector<shared_ptr<Product>> sortedProducts = allProducts; // kopia do sortowania

    if (sortOpt == 1) {
        if (orderOpt == 1) {
            sort(sortedProducts.begin(), sortedProducts.end(), [](const auto& a, const auto& b) {
                return a->getName() < b->getName();
            });
        } else {
            sort(sortedProducts.begin(), sortedProducts.end(), [](const auto& a, const auto& b) {
                return a->getName() > b->getName();
            });
        }
    } else if (sortOpt == 2) {
        if (orderOpt == 1) {
            sort(sortedProducts.begin(), sortedProducts.end(), [](const auto& a, const auto& b) {
                return a->getPrice() < b->getPrice();
            });
        } else {
            sort(sortedProducts.begin(), sortedProducts.end(), [](const auto& a, const auto& b) {
                return a->getPrice() > b->getPrice();
            });
        }
    } else if (sortOpt == 3) {
        if (orderOpt == 1) {
            sort(sortedProducts.begin(), sortedProducts.end(), [](const auto& a, const auto& b) {
                return a->averageRating() < b->averageRating();
            });
        } else {
            sort(sortedProducts.begin(), sortedProducts.end(), [](const auto& a, const auto& b) {
                return a->averageRating() > b->averageRating();
            });
        }
    }

    for (auto& p : sortedProducts) {
        cout << p->getId() << ". " << p->getName()
             << " ($" << p->getPrice() << ") Qty: " << p->getQuantity()
             << " Rating: " << p->averageRating()
             << "\nDesc: " << p->getDescription() << "\n";
        p->showReviews();
    }
            } else if (opt == 2) {
                int id, qty;
                cout << "Product ID: "; cin >> id;
                cout << "Quantity: "; cin >> qty;
                auto it = find_if(allProducts.begin(), allProducts.end(), [&](shared_ptr<Product> p) {
                    return p->getId() == id;
                });
                if (it != allProducts.end()) buyer->addToCart(*it, qty);
                else cout << "Product not found.\n";
            } else if (opt == 3) buyer->viewCart();
            else if (opt == 4) buyer->checkout();
            else if (opt == 5) {
                int id, rating;
                string comment;
                cout << "Product ID: "; cin >> id;
                cout << "Rating (1–5): "; cin >> rating;
                cout << "Comment: "; cin.ignore(); getline(cin, comment);
                auto it = find_if(allProducts.begin(), allProducts.end(), [&](shared_ptr<Product> p) {
                    return p->getId() == id;
                });
                if (it != allProducts.end()) buyer->rateProduct(*it, rating, comment);
                else cout << "Product not found.\n";
            } else if (opt == 6) buyer->viewPurchaseHistory();
else if (opt == 7) currentUser = nullptr;

        }
    }

    cout << "Exiting program...\n";
saveAll(users, allProducts, categories);
    return 0;
}