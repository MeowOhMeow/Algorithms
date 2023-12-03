#include "Graph.h"

int num_nets;
vector<pair<pair<int, int>, pair<int, int>>> nets;

Graph::Graph(int col, int row, int capacity)
{
    this->row = col;
    this->col = row;
    this->capacity = capacity;
    vertices = col * row;
    adj.resize(vertices);
    parent.resize(vertices);
    d.resize(vertices);
    paths.resize(num_nets);

    // build graph
    // horizontal
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col - 1; j++)
        {
            adj[i * col + j].push_back(make_pair(i * col + j + 1, 1));
            adj[i * col + j + 1].push_back(make_pair(i * col + j, 1));
        }
    }
    // vertical
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < col; j++)
        {
            adj[i * col + j].push_back(make_pair((i + 1) * col + j, 1));
            adj[(i + 1) * col + j].push_back(make_pair(i * col + j, 1));
        }
    }
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

void Graph::dijkstra(int s)
{
    int pos = nets[s].first.first * col + nets[s].first.second;
    init_single_source(pos);
    Q.push(make_pair(d[pos], pos));

    while (!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                parent[v] = u;
                Q.push(make_pair(d[v], v));
            }
        }
    }
}

void Graph::update_adj(int pos)
{
    for (int i = 0; i < adj[pos].size(); i++)
    {
        if (adj[pos][i].first == parent[pos])
        {
            adj[pos][i].second += 1;
            break;
        }
    }
    for (int i = 0; i < adj[parent[pos]].size(); i++)
    {
        if (adj[parent[pos]][i].first == pos)
        {
            adj[parent[pos]][i].second += 1;
            break;
        }
    }
}

void Graph::choose_path(int i, int s, int v)
{
    int pos = v;
    paths[i].push_back(pos);
    update_adj(pos);
    while (pos != s)
    {
        update_adj(pos);
        pos = parent[pos];
        paths[i].push_back(pos);
    }
}

void Graph::solve()
{
    for (int i = 0; i < num_nets; i++)
    {
        dijkstra(i);
        choose_path(i, nets[i].first.first * col + nets[i].first.second, nets[i].second.first * col + nets[i].second.second);
    }
}

void Graph::save_path(string output_file)
{
    ofstream fout(output_file);
    for (int i = 0; i < num_nets; i++)
    {
        fout << i << " " << paths[i].size() - 1 << endl;
        // for (int j = 0; j < paths[i].size() - 1; j++)
        // {
        //     int x1 = paths[i][j] / col;
        //     int y1 = paths[i][j] % col;
        //     int x2 = paths[i][j + 1] / col;
        //     int y2 = paths[i][j + 1] % col;
        //     fout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        // }
        for (int j = paths[i].size() - 1; j > 0; j--)
        {
            int x1 = paths[i][j] / col;
            int y1 = paths[i][j] % col;
            int x2 = paths[i][j - 1] / col;
            int y2 = paths[i][j - 1] % col;
            fout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        }
    }
}
