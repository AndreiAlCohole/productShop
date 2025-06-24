#include "Review.h"

Review::Review(const std::string& user, int rate, const std::string& comm)
    : username(user), rating(rate), comment(comm) {}

std::string Review::getUsername() const { return username; }
int Review::getRating() const { return rating; }
std::string Review::getComment() const { return comment; }