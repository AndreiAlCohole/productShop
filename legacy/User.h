#pragma once
#include <string>

class User {
protected:
    std::string username;
    std::string password;
public:
    User(const std::string& name, const std::string& pass);
    virtual ~User() = default;
    std::string getUsername() const;
    bool checkPassword(const std::string& pass) const;
    virtual std::string getType() const = 0;
};