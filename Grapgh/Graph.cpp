#include "Graph.h"

void Graph::add_undirected_Edge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::add_directed_Edge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::BFS(int s)
{
    for (int i = 0; i < vertices; i++)
    {
        color[i] = WHITE;
        d[i] = INT32_MAX;
        parent[i] = NIL;
    }

    color[s] = GRAY;
    d[s] = 0;
    parent[s] = NIL;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];

            if (color[v] == WHITE)
            {
                color[v] = GRAY;
                d[v] = d[u] + 1;
                parent[v] = u;
                Q.push(v);
            }
        }

        color[u] = BLACK;
    }
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
}

void Graph::printBFS()
{
    for (int i = 0; i < vertices; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}

void Graph::printDFS()
{
    for (int i = 0; i < vertices; i++)
    {
        cout << d[i] << "/" << f[i] << " ";
    }
    cout << endl;
}
