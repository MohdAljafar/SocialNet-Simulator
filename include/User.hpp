#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>

#include "AVLTree.hpp"

class User {
public:
    std::string username;

    std::vector<User*> friends;

    AVLTree posts;

    explicit User(const std::string& name)
        : username(name) {}
};

#endif