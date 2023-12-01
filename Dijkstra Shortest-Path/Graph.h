#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

#define NIL -1

using namespace std;

class Graph
{
private:
    int edges;
    // (adjacent, weight)
    vector<vector<pair<int, int>>> adj;
    vector<int> parent;
    vector<int> d;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

public:
    int vertices;
    Graph(int v, int e)
    {
        vertices = v;
        edges = e;
        adj.resize(v);
        parent.resize(v);
        d.resize(v);
    }

    void add_directed_Edge(int u, int v, int w);

    void init_single_source(int s);
    void relax(int u, int v, int w);
    void dijkstra(int s);

    void print_path(int s, int v);
};
