#ifndef SOCIAL_NETWORK_HPP
#define SOCIAL_NETWORK_HPP

#include <string>
#include <vector>

#include "Graph.hpp"

class SocialNetwork
{
private:
    Graph graph;
    long long currentTimestamp;

public:
    SocialNetwork();

    bool addUser(const std::string& username);

    bool addFriend(
        const std::string& user1,
        const std::string& user2
    );

    std::vector<std::string>
    listFriends(
        const std::string& username
    );

    std::vector<
        std::pair<std::string,int>
    >
    suggestFriends(
        const std::string& username,
        int N
    );

    int degreesOfSeparation(
        const std::string& source,
        const std::string& destination
    );

    bool addPost(
        const std::string& username,
        const std::string& content
    );

    std::vector<std::string>
    outputPosts(
        const std::string& username,
        int N
    );
};

#endif