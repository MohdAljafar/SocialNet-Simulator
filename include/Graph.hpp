#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include "User.hpp"

class Graph {
private:
    std::unordered_map<std::string, User*> users;

public:
    Graph();
    ~Graph();

    bool addUser(const std::string& username);

    bool addFriend(
        const std::string& user1,
        const std::string& user2
    );

    User* getUser(
        const std::string& username
    );

    std::vector<std::string>
    listFriends(
        const std::string& username
    );

    std::vector<std::pair<std::string,int>>
    suggestFriends(
        const std::string& username,
        int N
    );

    int degreesOfSeparation(
        const std::string& source,
        const std::string& destination
    );

    static std::string normalize(
        const std::string& str
    );
};

#endif