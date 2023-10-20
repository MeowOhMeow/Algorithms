#include "RBTree.h"
#include <algorithm>

using namespace std;

int main()
{
    int size = 6;
    int arr[] = {41, 38, 31, 12, 19, 8};
    RBTree tree;
    for (int i = 0; i < size; i++)
    {
        Node *node = new Node(arr[i]);
        tree.insert(node);

        cout << "Structure:\n";
        tree.printStructure();
        cout << endl;
    }
    cout << endl;

    sort(arr, arr + size);
    for (int i = 0; i < size; i++)
    {
        cout << "Removing " << arr[i] << endl;
        tree.remove(arr[i]);
        cout << "Structure:\n";
        tree.printStructure();
        cout << endl;
    }
}