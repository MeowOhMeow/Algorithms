#include "Graph.h"

using namespace std;

int main()
{
    Graph G1(8, 10);

    G1.add_undirected_Edge(0, 1);
    G1.add_undirected_Edge(0, 4);
    G1.add_undirected_Edge(1, 5);
    G1.add_undirected_Edge(2, 3);
    G1.add_undirected_Edge(2, 5);
    G1.add_undirected_Edge(2, 6);
    G1.add_undirected_Edge(3, 6);
    G1.add_undirected_Edge(3, 7);
    G1.add_undirected_Edge(5, 6);
    G1.add_undirected_Edge(6, 7);

    G1.BFS(1);

    G1.printBFS();

    Graph G2(6, 8);

    G2.add_directed_Edge(0, 1);
    G2.add_directed_Edge(0, 3);
    G2.add_directed_Edge(1, 4);
    G2.add_directed_Edge(2, 4);
    G2.add_directed_Edge(2, 5);
    G2.add_directed_Edge(3, 1);
    G2.add_directed_Edge(4, 3);
    G2.add_directed_Edge(5, 5);

    G2.DFS();

    G2.printDFS();

    return 0;
}
