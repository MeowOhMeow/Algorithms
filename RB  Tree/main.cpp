#include "RBTree.h"
#include <algorithm>

using namespace std;

int main()
{
    int size = 7;
    int arr[] = {8, 6, 9, 3, 2, 5, 7};
    RBTree tree;
    for (int i = 0; i < size; i++)
    {
        Node *node = new Node(arr[i]);
        tree.insert(node);

        // cout << "Structure:\n";
        // tree.printStructure();
        // cout << endl;
    }
    // cout << endl;
    cout << "Structure:\n";
    tree.printStructure();
    cout << endl;
    tree.insert(new Node(4));
    cout << "Structure:\n";
    tree.printStructure();
}