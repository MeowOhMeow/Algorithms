#include "Graph.h"

void Graph::add_directed_Edge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::DFS()
{
    for (int i = 0; i < vertices; i++)
    {
        color[i] = WHITE;
        parent[i] = NIL;
    }
    time = 0;
    for (int i = 0; i < vertices; i++)
    {
        if (color[i] == WHITE)
        {
            DFS_visit(i);
        }
    }
}

void Graph::DFS_visit(int u)
{
    time++;
    d[u] = time;
    color[u] = GRAY;

    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];

        if (color[v] == WHITE)
        {
            parent[v] = u;
            DFS_visit(v);
        }
    }

    color[u] = BLACK;
    time++;
    f[u] = time;
    topological_order.push_back(u);
}

vector<int> Graph::topological_sort()
{
    DFS();
    return topological_order;
}
