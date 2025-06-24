#pragma once
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <iostream>

class Category;
class Review;

class Product {
    int id;
    std::string name;
    double price;
    int quantity;
    std::string description;
    std::vector<Review> reviews;
    std::shared_ptr<Category> category;
    std::string storeName;
    std::string sellerName;
    std::set<std::string> buyers;
    int soldCount = 0;
public:
    Product(const std::string& n, double p, int q, std::shared_ptr<Category> c, const std::string& sName, const std::string& seller, const std::string& desc);

    int getId() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;
    void decreaseQuantity();
    std::shared_ptr<Category> getCategory() const;
    std::string getStoreName() const;
    std::string getSellerName() const;
    std::string getDescription() const;

    void addBuyer(const std::string& username);
    bool wasBoughtBy(const std::string& username) const;
    int uniqueBuyersCount() const;

    void addReview(const std::string& username, int rating, const std::string& comment);
    void removeReviewByUser(const std::string& username);
    double averageRating() const;
    void showReviews() const;
    void increaseSoldCount(int qty);
    int getSoldCount() const;

    void save(std::ostream& os) const;
    void saveReviews(std::ostream& os) const;
};