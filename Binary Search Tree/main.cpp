#include "binaryTree.h"

using namespace std;

int main()
{
    int size = 10;
    int values[] = {41, 38, 31, 12, 19, 8, 1, 4, 9, 20};
    BinaryTree tree;
    for (int i = 0; i < size; i++)
    {
        Node *node = new Node(values[i]);
        tree.insert(node);
    }
    cout << "Max: " << tree.findMax()->key << endl;
    cout << "Inorder:\t";
    tree.printIn();
    cout << endl;

    tree.remove(values[1]);
    cout << "After deletion:\t";
    tree.printIn();
    cout << endl;
}