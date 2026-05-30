#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../include/SocialNetwork.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

int main()
{
    SocialNetwork network;

    string line;

    cout<<"Start giving instructions"<<endl;

    while (getline(cin, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);

        string command1;
        string command2;

        ss >> command1;
        ss >> command2;

        // ------------------------
        // ADD USER
        // ------------------------
        if (command1 == "ADD" &&
            command2 == "USER")
        {
            string username;

            getline(ss >> std::ws, username);

            network.addUser(username);
        }

        // ------------------------
        // ADD FRIEND
        // ------------------------
        else if (command1 == "ADD" &&
                 command2 == "FRIEND")
        {
            string user1;
            string user2;

            ss >> user1;
            ss >> user2;

            network.addFriend(
                user1,
                user2
            );
        }

        // ------------------------
        // LIST FRIENDS
        // ------------------------
        else if (command1 == "LIST" &&
                 command2 == "FRIENDS")
        {
            string username;

            ss >> username;

            auto friends = network.listFriends(username);

            for(const auto& friendName : friends)
            {
                cout << friendName << endl;
            }
        }

        // ------------------------
        // SUGGEST FRIENDS
        // ------------------------
        else if (
            command1 == "SUGGEST" &&
            command2 == "FRIENDS"
        )
        {
            string username;
            int N;

            ss >> username;
            ss >> N;

            auto suggestions =
                network.suggestFriends(
                    username,
                    N
                );

            for(const auto& p
                : suggestions)
            {
                cout
                    << p.first
                    << " ("
                    << p.second
                    << " mutual)"
                    << endl;
            }
        }

        // ------------------------
        // DEGREES OF SEPARATION
        // ------------------------
        else if (
            command1 == "DEGREES"
        )
        {
            string temp;
            string user1;
            string user2;

            ss >> temp;   // OF
            ss >> temp;   // SEPARATION

            ss >> user1;
            ss >> user2;

            cout
                << network
                    .degreesOfSeparation(
                        user1,
                        user2
                    )
                << endl;
        }

        // ------------------------
        // ADD POST
        // ------------------------
        else if (
            command1 == "ADD" &&
            command2 == "POST"
        )
        {
            string username;

            ss >> username;

            size_t firstQuote =
                line.find('"');

            size_t lastQuote =
                line.rfind('"');

            if(firstQuote ==
                    string::npos ||
               lastQuote ==
                    string::npos ||
               firstQuote ==
                    lastQuote)
            {
                continue;
            }

            string content =
                line.substr(
                    firstQuote + 1,
                    lastQuote - firstQuote - 1
                );

            network.addPost(
                username,
                content
            );
        }

        // ------------------------
        // OUTPUT POSTS
        // ------------------------
        else if (
            command1 == "OUTPUT" &&
            command2 == "POSTS"
        )
        {
            string username;
            int N;

            ss >> username;
            ss >> N;

            auto posts =
                network.outputPosts(
                    username,
                    N
                );

            for(const auto& post
                : posts)
            {
                cout
                    << post
                    << endl;
            }
        }
    }

    return 0;
}