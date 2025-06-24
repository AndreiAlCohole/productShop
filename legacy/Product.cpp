#include "Product.h"
#include "Category.h"
#include "Review.h"
#include <algorithm>

static int productIdCounter = 1;

Product::Product(const std::string& n, double p, int q, std::shared_ptr<Category> c, const std::string& sName, const std::string& seller, const std::string& desc)
    : id(productIdCounter++), name(n), price(p), quantity(q), category(c), storeName(sName), sellerName(seller), description(desc) {}

int Product::getId() const { return id; }
std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }
void Product::decreaseQuantity() { if (quantity > 0) quantity--; }
std::shared_ptr<Category> Product::getCategory() const { return category; }
std::string Product::getStoreName() const { return storeName; }
std::string Product::getSellerName() const { return sellerName; }
std::string Product::getDescription() const { return description; }

void Product::addBuyer(const std::string& username) { buyers.insert(username); }
bool Product::wasBoughtBy(const std::string& username) const { return buyers.count(username) > 0; }
int Product::uniqueBuyersCount() const { return buyers.size(); }

void Product::addReview(const std::string& username, int rating, const std::string& comment) {
    reviews.emplace_back(username, rating, comment);
}

void Product::removeReviewByUser(const std::string& username) {
    auto it = std::remove_if(reviews.begin(), reviews.end(), [&](const Review& r) {
        return r.getUsername() == username;
    });
    if (it != reviews.end()) {
        reviews.erase(it, reviews.end());
        std::cout << "Review removed.\n";
    } else {
        std::cout << "No review found for user.\n";
    }
}

double Product::averageRating() const {
    if (reviews.empty()) return 0.0;
    int total = 0;
    for (const auto& r : reviews) total += r.getRating();
    return static_cast<double>(total) / reviews.size();
}

void Product::showReviews() const {
    std::cout << "Reviews for " << name << ":\n";
    for (const auto& r : reviews) {
        std::cout << r.getUsername() << " rated " << r.getRating() << " - " << r.getComment() << std::endl;
    }
}

void Product::increaseSoldCount(int qty) { soldCount += qty; }
int Product::getSoldCount() const { return soldCount; }

void Product::save(std::ostream& os) const {
    os << id << ';' << name << ';' << price << ';' << quantity << ';'
       << description << ';' << category->getName() << ';'
       << storeName << ';' << sellerName << ';' << soldCount << '\n';
}

void Product::saveReviews(std::ostream& os) const {
    for (const auto& r : reviews) {
        os << id << ';' << r.getUsername() << ';' << r.getRating() << ';' << r.getComment() << '\n';
    }
}