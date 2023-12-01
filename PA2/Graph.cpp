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
    demand = new int *[col];
    for (int i = 0; i < col; i++)
    {
        demand[i] = new int[row];
        for (int j = 0; j < row; j++)
        {
            demand[i][j] = 0;
        }
    }
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

void Graph::del()
{
    for (int i = 0; i < col; i++)
    {
        delete[] demand[i];
    }
    delete[] demand;
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
            float w = adj[u][i].second;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                parent[v] = u;
                Q.push(make_pair(d[v], v));
            }
        }
    }
}

void Graph::choose_path(int i, int s, int v)
{
    int pos = v;
    paths[i].push_back(pos);
    while (pos != s)
    {
        demand[pos / col][pos % col]++;
        pos = parent[pos];
        paths[i].push_back(pos);
    }
}

float Graph::get_distance(int demand)
{
    return pow(2, demand / capacity);
}

void Graph::load_demand()
{
    // reset adj
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            adj[i][j].second = get_distance(demand[adj[i][j].first / col][adj[i][j].first % col]);
        }
    }
}

void Graph::solve()
{
    for (int i = 0; i < num_nets; i++)
    {
        dijkstra(i);
        choose_path(i, nets[i].first.first * col + nets[i].first.second, nets[i].second.first * col + nets[i].second.second);
        load_demand();
    }
}

void Graph::save_path(string output_file)
{
    ofstream fout(output_file);
    Perror(fout, "Failed to open file %s", output_file.c_str());
    for (int i = 0; i < num_nets; i++)
    {
        fout << i << " " << paths[i].size() - 1 << endl;
        for (int j = 0; j < paths[i].size() - 1; j++)
        {
            int x1 = paths[i][j] / col;
            int y1 = paths[i][j] % col;
            int x2 = paths[i][j + 1] / col;
            int y2 = paths[i][j + 1] % col;
            fout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        }
    }
}
