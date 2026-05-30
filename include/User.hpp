#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

#include "AVLTree.hpp"

class User {
public:
    string username;

    unordered_set<User*> friends;

    AVLTree posts;

    User(const string& name) : username(name) {}
};

#endif