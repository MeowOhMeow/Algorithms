#ifndef RB_TREE_H
#define RB_TREE_H

#include "binaryTree.h"

#define RESET "\x1B[0m"
#define BRIGHT_RED "\x1B[91m"
#define BRIGHT_BLACK "\x1B[90m"

class RBTree : public BinaryTree
{
private:
    void insertFixup(Node *node);
    void deleteFixup(Node *node);
    void transplant(Node *oldNode, Node *newNode);

    void leftRotate(Node *node);
    void rightRotate(Node *node);
    void printIn(Node *node);
    void printPre(Node *node);
    void printPost(Node *node);
    void printStructure(Node *node, int indent);

public:
    void printIn() { printIn(root); }
    void printPre() { printPre(root); }
    void printPost() { printPost(root); }
    void printStructure() { printStructure(root, 0); }

    void insert(Node *node);
    void del(Node *node);
};

#endif /* rb_tree_h */