#include "binaryTree.h"
#include <random>
#include <vector>

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
    cout << "Max: " << tree.findMax()->key << endl;
    cout << "Inorder:\t";
    tree.printIn();
    cout << endl;

    int toBeDeleted = 2;
    vector<Node *>::iterator it = array.begin() + toBeDeleted;
    tree.del(*it);
    delete *it;
    array.erase(it);

    cout << "After deletion:\t";
    tree.printIn();
    cout << endl;
}