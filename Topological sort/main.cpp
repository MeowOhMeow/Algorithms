#include "Graph.h"
#include <string>

using namespace std;

int main()
{
    string names[9] = {"undershorts", "pants", "belt", "shirt", "tie", "jacket", "socks", "shoes", "watch"};
    Graph G(9, 9);
    G.add_directed_Edge(0, 1);
    G.add_directed_Edge(0, 7);
    G.add_directed_Edge(1, 2);
    G.add_directed_Edge(1, 7);
    G.add_directed_Edge(2, 5);
    G.add_directed_Edge(3, 2);
    G.add_directed_Edge(3, 4);
    G.add_directed_Edge(4, 5);
    G.add_directed_Edge(6, 7);

    vector<int> topological_order = G.topological_sort();

    for (int i = topological_order.size() - 1; i >= 0; i--)
    {
        cout << names[topological_order[i]] << " ";
    }

    return 0;
}
