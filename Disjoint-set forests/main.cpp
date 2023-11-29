#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    int rank;
    Node *representative;
};

Node *make_set(int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->rank = 0;
    new_node->representative = new_node;
    return new_node;
}

Node *find_set(Node *node, bool print_path = false)
{
    vector<Node *> path;
    while (node != node->representative)
    {
        if (print_path)
        {
            cout << node->data << " ";
        }
        path.push_back(node);
        node = node->representative;
    }
    // path compression
    while (!path.empty())
    {
        path.back()->representative = node;
        path.pop_back();
    }
    return node->representative;
}

Node *link(Node *head1, Node *head2)
{
    if (head1->rank > head2->rank)
    {
        head2->representative = head1;
        return head1;
    }
    else
    {
        head1->representative = head2;
        if (head1->rank == head2->rank)
        {
            head2->rank++;
        }
        return head2;
    }
}

void union_set(Node *node1, Node *node2)
{
    link(find_set(node1), find_set(node2));
}

void print_set(Node *node)
{
    Node *head = find_set(node, true);
    cout << head->data;
    cout << endl;
}

int main()
{
    Node *node1 = make_set(1);
    Node *node2 = make_set(2);
    Node *node3 = make_set(3);
    Node *node4 = make_set(4);
    Node *node5 = make_set(5);
    Node *node6 = make_set(6);
    Node *node7 = make_set(7);

    union_set(node1, node2);
    union_set(node2, node3);
    union_set(node4, node5);
    union_set(node5, node6);
    union_set(node6, node7);
    union_set(node3, node7);

    cout << "first time" << endl;
    print_set(node1);
    print_set(node2);
    print_set(node3);
    print_set(node4);
    print_set(node5);
    print_set(node6);
    print_set(node7);

    cout << "second time" << endl;
    print_set(node1);
    print_set(node2);
    print_set(node3);
    print_set(node4);
    print_set(node5);
    print_set(node6);
    print_set(node7);

    return 0;
}