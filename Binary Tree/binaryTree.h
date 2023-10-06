#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "node.h"
#include <iostream>

class BinaryTree
{
private:
    void transplant(Node *oldNode, Node *newNode);
public:
    Node *root = nullptr;

    void printIn(Node *node);
    void printPre(Node *node);
    void printPost(Node *node);
    Node *search(Node *node, int key);
    Node *findSuccessor(Node *node);
    Node *findMin(Node *node);
    Node *findMax(Node *node);
    void insert(Node *node);
    Node *del(Node *node);
};

#endif /* binaryTree_h*/