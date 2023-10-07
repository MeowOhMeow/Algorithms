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

public:
    void printIn();
    void printPre();
    void printPost();
    Node *search(Node *node, int key);
    Node *findSuccessor(Node *node);
    Node *findMin(Node *node);
    Node *findMax(Node *node);
    void insert(Node *node);
    void del(Node *node);
};

#endif /* binarySearchTree_h */