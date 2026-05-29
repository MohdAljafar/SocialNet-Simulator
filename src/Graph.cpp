#include "../include/Graph.hpp"

#include <algorithm>
#include <queue>
#include <unordered_set>
#include <cctype>

Graph::Graph() {}

Graph::~Graph()
{
    for(auto& entry : users)
    {
        delete entry.second;
    }
}

std::string Graph::normalize(
    const std::string& str
)
{
    std::string result = str;

    for(char& c : result)
    {
        c = std::tolower(c);
    }

    return result;
}

bool Graph::addUser(
    const std::string& username
)
{
    std::string key =
        normalize(username);

    if(users.count(key))
    {
        return false;
    }

    users[key] =
        new User(username);

    return true;
}

User* Graph::getUser(
    const std::string& username
)
{
    std::string key =
        normalize(username);

    auto it = users.find(key);

    if(it == users.end())
    {
        return nullptr;
    }

    return it->second;
}

bool Graph::addFriend(
    const std::string& user1,
    const std::string& user2
)
{
    User* u1 = getUser(user1);
    User* u2 = getUser(user2);

    if(!u1 || !u2)
    {
        return false;
    }

    if(u1 == u2)
    {
        return false;
    }

    u1->friends.insert(u2);
    u2->friends.insert(u1);

    return true;
}

std::vector<std::string>
Graph::listFriends(
    const std::string& username
)
{
    std::vector<std::string> result;

    User* user =
        getUser(username);

    if(!user)
    {
        return result;
    }

    for(User* f : user->friends)
    {
        result.push_back(
            f->username
        );
    }

    std::sort(
        result.begin(),
        result.end()
    );

    return result;
}

std::vector<std::pair<std::string,int>>
Graph::suggestFriends(
    const std::string& username,
    int N
)
{
    std::vector<
        std::pair<std::string,int>
    > result;

    if(N <= 0)
    {
        return result;
    }

    User* user =
        getUser(username);

    if(!user)
    {
        return result;
    }

    std::unordered_map<
        User*,
        int
    > mutualCount;

    for(User* friendNode :
        user->friends)
    {
        for(User* candidate :
            friendNode->friends)
        {
            if(candidate == user)
            {
                continue;
            }

            if(user->friends.count(
                candidate))
            {
                continue;
            }

            mutualCount[
                candidate
            ]++;
        }
    }

    for(auto& entry :
        mutualCount)
    {
        result.push_back({
            entry.first->username,
            entry.second
        });
    }

    std::sort(
        result.begin(),
        result.end(),
        [](
            const auto& a,
            const auto& b
        )
        {
            if(a.second != b.second)
            {
                return
                a.second > b.second;
            }

            return
            a.first < b.first;
        }
    );

    if(
        result.size() >
        static_cast<size_t>(N)
    )
    {
        result.resize(N);
    }

    return result;
}

int Graph::degreesOfSeparation(
    const std::string& source,
    const std::string& destination
)
{
    User* src =
        getUser(source);

    User* dest =
        getUser(destination);

    if(!src || !dest)
    {
        return -1;
    }

    if(src == dest)
    {
        return 0;
    }

    std::queue<User*> q;

    std::unordered_map<
        User*,
        int
    > distance;

    q.push(src);

    distance[src] = 0;

    while(!q.empty())
    {
        User* current =
            q.front();

        q.pop();

        for(User* neighbor :
            current->friends)
        {
            if(
                distance.count(
                    neighbor
                )
            )
            {
                continue;
            }

            distance[neighbor] =
                distance[current]
                + 1;

            if(neighbor == dest)
            {
                return
                distance[
                    neighbor
                ];
            }

            q.push(neighbor);
        }
    }

    return -1;
}