#include "Category.h"

Category::Category(const std::string& n) : name(n) {}

std::string Category::getName() const {
    return name;
}