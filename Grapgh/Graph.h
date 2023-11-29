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

    void add_undirected_Edge(int u, int v);
    void add_directed_Edge(int u, int v);
    void BFS(int s);
    void DFS();
    void DFS_visit(int u);
    void printBFS();
    void printDFS();
};
