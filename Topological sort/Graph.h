#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

class Graph
{
private:
    int vertices;
    int edges;
    vector<vector<int>> adj;
    vector<int> color;
    vector<int> parent;
    vector<int> d;
    vector<int> f;
    vector<int> topological_order;
    int time;

public:
    Graph(int v, int e)
    {
        vertices = v;
        edges = e;
        adj.resize(v);
        color.resize(v);
        parent.resize(v);
        d.resize(v);
        f.resize(v);
    }

    void add_directed_Edge(int u, int v);

    void DFS();
    void DFS_visit(int u);
    vector<int> topological_sort();
};
