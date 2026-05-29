#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <vector>
#include <string>

class AVLNode {
public:
    long long timestamp;
    std::string content;

    AVLNode* left;
    AVLNode* right;

    int height;

    AVLNode(long long ts, const std::string& text);
};

class AVLTree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node);
    int getBalance(AVLNode* node);

    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* rotateRight(AVLNode* y);

    AVLNode* insertNode(
        AVLNode* node,
        long long timestamp,
        const std::string& content
    );

    void reverseInorder(
        AVLNode* node,
        std::vector<std::string>& result,
        int& remaining
    );

    void destroyTree(AVLNode* node);

public:
    AVLTree();
    ~AVLTree();

    void insert(long long timestamp,
                const std::string& content);

    std::vector<std::string> getRecentPosts(int N);
};

#endif