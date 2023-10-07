#include "binarySearchTree.h"
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
    tree.printIn();
    cout << endl;

    int toBeDeleted = 2;
    vector<Node *>::iterator it = array.begin() + toBeDeleted;
    tree.del(*it);
    array.erase(it);
    tree.printIn();
    cout << endl;
}