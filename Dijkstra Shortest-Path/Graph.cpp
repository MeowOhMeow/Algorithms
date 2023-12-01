#include "Graph.h"

void Graph::add_directed_Edge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}

void Graph::init_single_source(int s)
{
    for (int i = 0; i < vertices; i++)
    {
        d[i] = INT_MAX;
        parent[i] = NIL;
    }
    d[s] = 0;
}

void Graph::relax(int u, int v, int w)
{
    if (d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        parent[v] = u;
        Q.push(make_pair(d[v], v));
    }
}

void Graph::dijkstra(int s)
{
    init_single_source(s);
    Q.push(make_pair(d[s], s));

    while (!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            relax(u, v, w);
        }
    }
}

void Graph::print_path(int s, int v)
{
    if (v == s)
        cout << s << " ";
    else if (parent[v] == NIL)
        cout << "No path from " << s << " to " << v << " exists";
    else
    {
        print_path(s, parent[v]);
        cout << v << " ";
    }
}