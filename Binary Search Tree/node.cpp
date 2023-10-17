#include "node.h"

Node *NIL = new Node();

Node::Node(int key)
{
    this->key = key;
    this->parent = NIL;
    this->left = NIL;
    this->right = NIL;
}