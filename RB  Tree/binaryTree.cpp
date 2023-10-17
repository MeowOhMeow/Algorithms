#include "binaryTree.h"

using namespace std;

void BinaryTree::transplant(Node *oldNode, Node *newNode)
{
    if (oldNode->parent == NIL)
        root = newNode;
    else if (oldNode == oldNode->parent->left)
        oldNode->parent->left = newNode;
    else
        oldNode->parent->right = newNode;
    if (newNode != NIL)
        newNode->parent = oldNode->parent;
}

void BinaryTree::printIn(Node *node)
{
    if (node != NIL)
    {
        printIn(node->left);
        cout << node->key << ", ";
        printIn(node->right);
    }
}

void BinaryTree::printPre(Node *node)
{
    if (node != NIL)
    {
        cout << node->key << ", ";
        printIn(node->left);
        printIn(node->right);
    }
}

void BinaryTree::printPost(Node *node)
{
    if (node != NIL)
    {
        printIn(node->left);
        printIn(node->right);
        cout << node->key << ", ";
    }
}

void BinaryTree::printStructure(Node* root, int indent) {
    if (root == NIL) {
        return;
    }

    // Print right subtree with increased indentation
    printStructure(root->right, indent + 4);

    // Print current node with indentation
    std::cout << std::string(indent, ' ') << root->key << std::endl;

    // Print left subtree with increased indentation
    printStructure(root->left, indent + 4);
}

Node *BinaryTree::search(Node *node, int key)
{
    if (node == NIL or key == node->key)
        return node;
    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

Node *BinaryTree::findSuccessor(Node *node)
{
    if (node->right != NIL)
        return findMin(node->right);

    Node *parent;
    while (parent != NIL and node == parent->right)
    {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

Node *BinaryTree::findMin(Node *node)
{
    while (node->left != NIL)
        node = node->left;
    return node;
}

Node *BinaryTree::findMax(Node *node)
{
    while (node->right != NIL)
        node = node->right;
    return node;
}

void BinaryTree::insert(Node *node)
{
    Node *parent = NIL;
    Node *child = root;

    while (child != NIL)
    {
        parent = child;
        if (node->key < child->key)
            child = child->left;
        else
            child = child->right;
    }
    node->parent = parent;

    if (parent == NIL)
        root = node;

    else if (node->key < parent->key)
        parent->left = node;
    else
        parent->right = node;
}

void BinaryTree::del(Node *toBeDeleted)
{
    if (toBeDeleted->left == NIL)
        transplant(toBeDeleted, toBeDeleted->right);
    else if (toBeDeleted->right == NIL)
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
