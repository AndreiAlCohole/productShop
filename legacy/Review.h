#pragma once
#include <string>

class Review {
    std::string username;
    int rating;
    std::string comment;
public:
    Review(const std::string& user, int rate, const std::string& comm);
    std::string getUsername() const;
    int getRating() const;
    std::string getComment() const;
};