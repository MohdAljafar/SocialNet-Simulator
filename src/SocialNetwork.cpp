#include "../include/SocialNetwork.hpp"

SocialNetwork::SocialNetwork()
{
    currentTimestamp = 1;
}

bool SocialNetwork::addUser(
    const std::string& username
)
{
    return graph.addUser(username);
}

bool SocialNetwork::addFriend(
    const std::string& user1,
    const std::string& user2
)
{
    return graph.addFriend(
        user1,
        user2
    );
}

std::vector<std::string>
SocialNetwork::listFriends(
    const std::string& username
)
{
    return graph.listFriends(
        username
    );
}

std::vector<
    std::pair<std::string,int>
>
SocialNetwork::suggestFriends(
    const std::string& username,
    int N
)
{
    return graph.suggestFriends(
        username,
        N
    );
}

int SocialNetwork::degreesOfSeparation(
    const std::string& source,
    const std::string& destination
)
{
    return graph.degreesOfSeparation(
        source,
        destination
    );
}

bool SocialNetwork::addPost(
    const std::string& username,
    const std::string& content
)
{
    User* user =
        graph.getUser(username);

    if(!user)
    {
        return false;
    }

    user->posts.insert(
        currentTimestamp++,
        content
    );

    return true;
}

std::vector<std::string>
SocialNetwork::outputPosts(
    const std::string& username,
    int N
)
{
    User* user =
        graph.getUser(username);

    if(!user)
    {
        return {};
    }

    return user->posts.getRecentPosts(
        N
    );
}