#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "node.h"
#include <iostream>

class BinaryTree
{
protected:
    Node *root = NIL;

    void transplant(Node *oldNode, Node *newNode);
    void printIn(Node *node);
    void printPre(Node *node);
    void printPost(Node *node);
    void printStructure(Node *node, int indent);
    Node *findMin(Node *node);
    Node *findMax(Node *node);

public:
    void printIn() { printIn(root); }
    void printPre() { printPre(root); }
    void printPost() { printPost(root); }
    void printStructure() { printStructure(root, 0); }
    Node *search(Node *node, int key);
    Node *findSuccessor(Node *node);
    Node *findMin() { return findMin(root); }
    Node *findMax() { return findMax(root); }
    void insert(Node *node);
    void del(Node *node);
};

#endif /* binarySearchTree_h */