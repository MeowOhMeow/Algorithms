#ifndef NODE_H
#define NODE_H

#define RED 0
#define BLACK 1

class Node
{
public:
    Node() {}
    Node(int key);
    Node *parent, *left, *right;
    int color;
    int key;
};

extern Node *NIL;

#endif /* node_h */