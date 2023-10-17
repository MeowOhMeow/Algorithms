#include "RBTree.h"
#include <random>
#include <vector>

using namespace std;

int main()
{
    int size = 10;
    RBTree tree;
    vector<Node *> array(size);
    for (int i = 0; i < array.size(); i++)
    {
        Node *node = new Node(rand() % size);
        tree.insert(node);
        array[i] = node;
    }
    cout << "Max: " << tree.findMax()->key << endl;
    cout << "Structure:\n";
    tree.printStructure();
    cout << endl;

    int toBeDeleted = 2;
    vector<Node *>::iterator it = array.begin() + toBeDeleted;
    tree.del(*it);
    delete *it;
    array.erase(it);
}