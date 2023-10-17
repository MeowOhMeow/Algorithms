#include "RBTree.h"
#include <random>
#include <vector>

using namespace std;

void del(RBTree &tree, vector<Node *> &array, int toBeDeleted)
{
    vector<Node *>::iterator it = array.begin() + toBeDeleted;
    tree.del(*it);
    delete *it;
    array.erase(it);

    cout << "Structure:\n";
    tree.printStructure();
    cout << endl;
}

int main()
{
    int size = 6;
    int arr[] = {41, 38, 31, 12, 19, 8};
    RBTree tree;
    vector<Node *> array(size);
    for (int i = 0; i < array.size(); i++)
    {
        Node *node = new Node(arr[i]);
        tree.insert(node);
        array[i] = node;

        cout << "Structure:\n";
        tree.printStructure();
        cout << endl;
    }
    cout << endl;

    cout << "Deleting:\n";
    del(tree, array, 5);
    del(tree, array, 3);
    del(tree, array, 3);
    del(tree, array, 2);
    del(tree, array, 1);
    del(tree, array, 0);
}