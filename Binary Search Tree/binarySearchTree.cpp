#include "binarySearchTree.h"

using namespace std;

void BinaryTree::transplant(Node *oldNode, Node *newNode)
{
    if (oldNode->parent == nullptr)
        root = newNode;
    else if (oldNode == oldNode->parent->left)
        oldNode->parent->left = newNode;
    else
        oldNode->parent->right = newNode;
    if (newNode != nullptr)
        newNode->parent = oldNode->parent;
}

void BinaryTree::printIn(Node *node)
{
    if (node != nullptr)
    {
        printIn(node->left);
        cout << node->key << ", ";
        printIn(node->right);
    }
}

void BinaryTree::printPre(Node *node)
{
    if (node != nullptr)
    {
        cout << node->key << ", ";
        printIn(node->left);
        printIn(node->right);
    }
}

void BinaryTree::printPost(Node *node)
{
    if (node != nullptr)
    {
        printIn(node->left);
        printIn(node->right);
        cout << node->key << ", ";
    }
}

Node *BinaryTree::search(Node *node, int key)
{
    if (node == nullptr or key == node->key)
        return node;
    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

Node *BinaryTree::findSuccessor(Node *node)
{
    if (node->right != nullptr)
        return findMin(node->right);

    Node *parent;
    while (parent != nullptr and node == parent->right)
    {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

Node *BinaryTree::findMin(Node *node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

Node *BinaryTree::findMax(Node *node)
{
    while (node->right != nullptr)
        node = node->right;
    return node;
}

void BinaryTree::insert(Node *node)
{
    Node *parent = nullptr;
    Node *child = root;

    while (child != nullptr)
    {
        parent = child;
        if (node->key < child->key)
            child = child->left;
        else
            child = child->right;
    }
    node->parent = parent;

    if (parent == nullptr)
        root = node;

    else if (node->key < parent->key)
        parent->left = node;
    else
        parent->right = node;
}

void BinaryTree::del(Node *toBeDeleted)
{
    if (toBeDeleted->left == nullptr)
        transplant(toBeDeleted, toBeDeleted->right);
    else if (toBeDeleted->right == nullptr)
        transplant(toBeDeleted, toBeDeleted->left);
    else
    {
        Node *successor = findMin(toBeDeleted->right);
        if (successor->parent != toBeDeleted)
        {
            transplant(successor, successor->right);
            successor->right = toBeDeleted->right;
            successor->right->parent = successor;
        }
        transplant(toBeDeleted, successor);
        successor->left = toBeDeleted->left;
        successor->left->parent = successor;
    }
}
