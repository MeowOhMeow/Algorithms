#include "RBTree.h"
#include <random>
#include <vector>

using namespace std;

void del(RBTree &tree, vector<Node *> &array, int value)
{
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i]->key == value)
        {
            tree.del(array[i]);
            delete array[i];
            array.erase(array.begin() + i);
            break;
        }
    }

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
    del(tree, array, 8);
    del(tree, array, 12);
    del(tree, array, 19);
    del(tree, array, 31);
    del(tree, array, 38);
    del(tree, array, 41);
}