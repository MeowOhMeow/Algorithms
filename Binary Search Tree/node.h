#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node() {
        this->parent = this;
        this->left = this;
        this->right = this;
    }
    Node(int key);
    Node *parent, *left, *right;
    int key;
};

extern Node *NIL;

#endif /* node_h */