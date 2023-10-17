#include "RBTree.h"
#include <iostream>

using namespace std;

void RBTree::printStructure(Node *node, int indent)
{
    if (node == NIL)
        return;

    // Print right subtree with increased indentation
    printStructure(node->right, indent + 4);

    cout << string(indent, ' ');
    printNode(node);

    // Print left subtree with increased indentation
    printStructure(node->left, indent + 4);
}

void RBTree::printNode(Node *node)
{
    if (node == NIL)
        return;

    if (node->color == RED)
        cout << BRIGHT_RED;
    else
        cout << BRIGHT_BLACK;
    cout << node->key << RESET << endl;
}

void RBTree::transplant(Node *oldNode, Node *newNode)
{
    if (oldNode->parent == NIL)
        root = newNode;
    else if (oldNode == oldNode->parent->left)
        oldNode->parent->left = newNode;
    else
        oldNode->parent->right = newNode;

    newNode->parent = oldNode->parent;
}

void RBTree::leftRotate(Node *node)
{
    Node *right = node->right;

    // move right's left subtree to node's right subtree
    node->right = right->left;
    // update right's left subtree's parent
    if (right->left != NIL)
        right->left->parent = node;
    right->parent = node->parent;

    if (node->parent == NIL)
        root = right;
    else if (node == node->parent->left)
        node->parent->left = right;
    else
        node->parent->right = right;

    // link node and right
    right->left = node;
    node->parent = right;
}

void RBTree::rightRotate(Node *node)
{
    Node *left = node->left;

    // move left's right subtree to node's left subtree
    node->left = left->right;
    // update left's right subtree's parent
    if (left->right != NIL)
        left->right->parent = node;
    left->parent = node->parent;

    if (node->parent == NIL)
        root = left;
    else if (node == node->parent->left)
        node->parent->left = left;
    else
        node->parent->right = left;

    // link node and left
    left->right = node;
    node->parent = left;
}

void RBTree::insert(Node *node)
{
    BinaryTree::insert(node);
    node->color = RED;
    insertFixup(node);
}

void RBTree::insertFixup(Node *node)
{
    while (node->parent->color == RED)
    {
        // node's parent is left child of node's grandparent
        if (node->parent == node->parent->parent->left)
        {
            Node *uncle = node->parent->parent->right;
            // red uncle
            if (uncle->color == RED)
            {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            // black uncle
            else
            {
                if (node == node->parent->right)
                {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rightRotate(node->parent->parent);
            }
        }
        // node's parent is right child of node's grandparent
        else
        {
            Node *uncle = node->parent->parent->left;
            // red uncle
            if (uncle->color == RED)
            {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            // black uncle
            else
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                leftRotate(node->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void RBTree::del(Node *node)
{
}
