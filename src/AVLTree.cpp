#include "../include/AVLTree.hpp"

#include <algorithm>

AVLNode::AVLNode(
    long long ts,
    const std::string& text
)
{
    timestamp = ts;
    content = text;

    left = nullptr;
    right = nullptr;

    height = 1;
}

AVLTree::AVLTree()
{
    root = nullptr;
}

AVLTree::~AVLTree()
{
    destroyTree(root);
}

void AVLTree::destroyTree(AVLNode* node)
{
    if (!node)
        return;

    destroyTree(node->left);
    destroyTree(node->right);

    delete node;
}

int AVLTree::getHeight(AVLNode* node)
{
    return node ? node->height : 0;
}

int AVLTree::getBalance(AVLNode* node)
{
    if (!node)
        return 0;

    return getHeight(node->left)
         - getHeight(node->right);
}

AVLNode* AVLTree::rotateRight(AVLNode* y)
{
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height =
        1 + std::max(
                getHeight(y->left),
                getHeight(y->right));

    x->height =
        1 + std::max(
                getHeight(x->left),
                getHeight(x->right));

    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x)
{
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height =
        1 + std::max(
                getHeight(x->left),
                getHeight(x->right));

    y->height =
        1 + std::max(
                getHeight(y->left),
                getHeight(y->right));

    return y;
}

AVLNode* AVLTree::insertNode(
    AVLNode* node,
    long long timestamp,
    const std::string& content
)
{
    if (!node)
        return new AVLNode(timestamp, content);

    if (timestamp < node->timestamp)
    {
        node->left =
            insertNode(node->left,
                       timestamp,
                       content);
    }
    else
    {
        node->right =
            insertNode(node->right,
                       timestamp,
                       content);
    }

    node->height =
        1 + std::max(
                getHeight(node->left),
                getHeight(node->right));

    int balance = getBalance(node);

    // LL
    if (balance > 1 &&
        timestamp < node->left->timestamp)
    {
        return rotateRight(node);
    }

    // RR
    if (balance < -1 &&
        timestamp > node->right->timestamp)
    {
        return rotateLeft(node);
    }

    // LR
    if (balance > 1 &&
        timestamp > node->left->timestamp)
    {
        node->left =
            rotateLeft(node->left);

        return rotateRight(node);
    }

    // RL
    if (balance < -1 &&
        timestamp < node->right->timestamp)
    {
        node->right =
            rotateRight(node->right);

        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(
    long long timestamp,
    const std::string& content
)
{
    root =
        insertNode(root,
                   timestamp,
                   content);
}

void AVLTree::reverseInorder(
    AVLNode* node,
    std::vector<std::string>& result,
    int& remaining
)
{
    if (!node)
        return;

    if (remaining == 0)
        return;

    reverseInorder(
        node->right,
        result,
        remaining
    );

    if (remaining == 0)
        return;

    result.push_back(node->content);

    if (remaining > 0)
        remaining--;

    reverseInorder(
        node->left,
        result,
        remaining
    );
}

std::vector<std::string>
AVLTree::getRecentPosts(int N)
{
    std::vector<std::string> posts;

    if (N == -1)
    {
        int unlimited = 1000000000;

        reverseInorder(
            root,
            posts,
            unlimited
        );
    }
    else
    {
        reverseInorder(
            root,
            posts,
            N
        );
    }

    return posts;
}