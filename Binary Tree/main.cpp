#include "binaryTree.h"
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int size = 10;
    BinaryTree tree;
    vector<Node *> array(size);
    for (int i = 0; i < array.size(); i++)
    {
        Node *node = new Node(rand() % size);
        tree.insert(node);
        array[i] = node;
    }
    tree.printIn(tree.root);
    cout << endl;
    // tree.printPre(tree.root);
    // cout << endl;
    // tree.printPost(tree.root);
    // cout << endl;

    Node *deletedNode = tree.del(array[2]);
    auto it = find(array.begin(), array.end(), deletedNode);
    if (it != array.end()) {
        array.erase(it);
    }
    tree.printIn(tree.root);
    cout << endl;
    // tree.printPre(tree.root);
    // cout << endl;
    // tree.printPost(tree.root);
    // cout << endl;
}