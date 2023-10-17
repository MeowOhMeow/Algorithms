#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node() {}
    Node(int key);
    Node *parent, *left, *right;
    int key;
};

extern Node *NIL;

#endif /* node_h */