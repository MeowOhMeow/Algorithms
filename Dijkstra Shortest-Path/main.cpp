#include "Graph.h"

int main()
{
    Graph G(5, 10);
    G.add_directed_Edge(0, 1, 10);
    G.add_directed_Edge(0, 3, 5);
    G.add_directed_Edge(1, 2, 1);
    G.add_directed_Edge(1, 3, 2);
    G.add_directed_Edge(2, 4, 4);
    G.add_directed_Edge(3, 1, 3);
    G.add_directed_Edge(3, 2, 9);
    G.add_directed_Edge(3, 4, 2);
    G.add_directed_Edge(4, 0, 7);
    G.add_directed_Edge(4, 2, 6);

    G.dijkstra(0);

    for (int i = 0; i < G.vertices; i++)
    {
        cout << "Path from 0 to " << i << ": ";
        G.print_path(0, i);
        cout << endl;
    }
}