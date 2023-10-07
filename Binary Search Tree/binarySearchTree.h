#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "node.h"
#include <iostream>

class BinaryTree
{
private:
    Node *root = nullptr;

    void transplant(Node *oldNode, Node *newNode);
    void printIn(Node *node);
    void printPre(Node *node);
    void printPost(Node *node);
    Node *findMin(Node *node);
    Node *findMax(Node *node);

public:
    void printIn() { printIn(root); }
    void printPre() { printPre(root); }
    void printPost() { printPost(root); }
    Node *search(Node *node, int key);
    Node *findSuccessor(Node *node);
    Node *findMin() { return findMin(root); }
    Node *findMax() { return findMax(root); }
    void insert(Node *node);
    void del(Node *node);
};

#endif /* binarySearchTree_h */