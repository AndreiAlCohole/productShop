#pragma once
#include <string>

class Category {
    std::string name;
public:
    Category(const std::string& n);
    std::string getName() const;
};