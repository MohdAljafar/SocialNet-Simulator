# SocialNet Simulator

A command-line social network simulator built in C++.

## Features

- User Management
- Friendship Graph
- Friend Recommendations
- Degrees of Separation
- AVL Tree Based Post Storage
- Reverse Chronological Post Retrieval

## Data Structures Used

### Graph

Each user is represented as a vertex.

Friendships are represented as undirected edges.

### AVL Tree

Each user's posts are stored in a self-balancing AVL Tree.

Posts are indexed using timestamps.


## Run

```
g++ src/*.cpp -o socialnet
.\socialnet.exe
```


## Example

```text
ADD USER Rahul
ADD USER Neha

ADD FRIEND Rahul Neha

LIST FRIENDS Rahul
```

## Complexity

| Operation | Complexity |
|------------|------------|
| Add User | O(1) |
| Add Friend | O(1) |
| List Friends | O(F log F) |
| Suggest Friends | O(F²) |
| Degrees Of Separation | O(V + E) |
| Add Post | O(log P) |
| Output Posts | O(N) |

## Author

Mohd Aljafar