#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node(int key) { this->key = key; }
    Node *parent = nullptr, *left = nullptr, *right = nullptr;
    int key;
};

#endif /* node_h */