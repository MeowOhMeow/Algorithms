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
    int originalColor = node->color;
    Node *child = NIL;
    // node has none or only right child
    if (node->left == NIL)
    {
        child = node->right;
        transplant(node, node->right);
    }
    // node has only left child
    else if (node->right == NIL)
    {
        child = node->left;
        transplant(node, node->left);
    }
    // node has both children
    else
    {
        Node *successor = findMin(node->right);
        child = successor->right;
        originalColor = successor->color;
        // successor is node's right child
        if (successor->parent == node)
            child->parent = successor;
        // successor is not node's right child
        else
        {
            transplant(successor, successor->right);
            successor->right = node->right;
            successor->right->parent = successor;
        }
        transplant(node, successor);
        successor->left = node->left;
        successor->left->parent = successor;
        successor->color = node->color;
    }
    if (originalColor == BLACK)
        deleteFixup(child);
}

void RBTree::deleteFixup(Node *node)
{
    while (node != root and node->color == BLACK)
    {
        // node is left child
        if (node == node->parent->left)
        {
            Node *sibling = node->parent->right;
            // case 1: sibling is red
            if (sibling->color == RED)
            {
                // these operations will convert into case 2, 3, or 4
                sibling->color = BLACK;
                node->parent->color = RED;
                leftRotate(node->parent);
                sibling = node->parent->right;
            }
            // case 2: sibling is black and both of sibling's children are black
            if (sibling->left->color == BLACK and sibling->right->color == BLACK)
            {
                sibling->color = RED;
                node = node->parent;
            }
            // case 3: left nephew is red
            else if (sibling->right->color == BLACK)
            {
                // these operations will convert into case 4
                sibling->left->color = BLACK;
                sibling->color = RED;
                rightRotate(sibling);
                sibling = node->parent->right;
            }
            // case 4: right nephew is red
            else
            {
                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->right->color = BLACK;
                leftRotate(node->parent);
                node = root;
            }
        }
        // node is right child
        else
        {
            Node *sibling = node->parent->left;
            // case 1: sibling is red
            if (sibling->color == RED)
            {
                // these operations will convert into case 2, 3, or 4
                sibling->color = BLACK;
                node->parent->color = RED;
                rightRotate(node->parent);
                sibling = node->parent->left;
            }
            // case 2: sibling is black and both of sibling's children are black
            if (sibling->left->color == BLACK and sibling->right->color == BLACK)
            {
                sibling->color = RED;
                node = node->parent;
            }
            // case 3: right nephew is red
            else if (sibling->left->color == BLACK)
            {
                // these operations will convert into case 4
                sibling->right->color = BLACK;
                sibling->color = RED;
                leftRotate(sibling);
                sibling = node->parent->left;
            }
            // case 4: left nephew is red
            else
            {
                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->left->color = BLACK;
                rightRotate(node->parent);
                node = root;
            }
        }
    }
    node->color = BLACK;
}
