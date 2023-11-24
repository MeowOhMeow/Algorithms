#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

void randomize(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = rand() % 100;
    }
    sort(v.begin(), v.end());
    vector<int>::iterator it = unique(v.begin(), v.end());
    v.erase(it, v.end());
    cout << "Randomized vector: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

bool compare(Node *a, Node *b)
{
    return a->data < b->data;
}

void printNode(Node *node)
{
    if (node == NULL)
        return;

    cout << node->data << endl;
}

void printStructure(Node *node, int indent)
{
    if (node == NULL)
        return;

    // Print right subtree with increased indentation
    printStructure(node->right, indent + 4);

    cout << string(indent, ' ');
    printNode(node);

    // Print left subtree with increased indentation
    printStructure(node->left, indent + 4);
}

int main()
{
    int length = 6;
    vector<int> char_vec(length);
    randomize(char_vec);

    vector<Node *> node_vec;

    for (int i = 0; i < char_vec.size(); i++)
    {
        Node *node = new Node();
        node->data = char_vec[i];
        node->left = NULL;
        node->right = NULL;
        node_vec.push_back(node);
    }

    for (int i = 0; i < length - 1; i++)
    {
        Node *node = new Node();

        // Sort the node_vec based on frequencies
        sort(node_vec.begin(), node_vec.end(), compare);

        node->data = node_vec[0]->data + node_vec[1]->data;
        node->left = node_vec[0];
        node->right = node_vec[1];

        // Erase the first two nodes
        node_vec.erase(node_vec.begin(), node_vec.begin() + 2);

        // Add the new node to the vector
        node_vec.push_back(node);
    }

    // output structure
    cout << "Structure:" << endl;
    printStructure(node_vec[0], 0);
}