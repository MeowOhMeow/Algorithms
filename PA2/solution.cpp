#include "solution.h"

int num_nets;
vector<pair<pair<int, int>, pair<int, int>>> nets;

Solution::Solution(int rows, int cols, int capacity)
{
    this->rows = rows;
    this->cols = cols;
    this->capacity = capacity;
    vertices = rows * cols;
    adj.resize(vertices);
    parent.resize(vertices);
    d.resize(vertices);
    paths.resize(num_nets);

    alpha = pow(100, 1.0 / capacity);

    // build graph
    // horizontal
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            adj[i * cols + j].push_back(make_pair(i * cols + j + 1, 1));
            adj[i * cols + j + 1].push_back(make_pair(i * cols + j, 1));
        }
    }
    // vertical
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            adj[i * cols + j].push_back(make_pair((i + 1) * cols + j, 1));
            adj[(i + 1) * cols + j].push_back(make_pair(i * cols + j, 1));
        }
    }
}

void Solution::update_adj(int pos)
{
    for (int i = 0; i < adj[pos].size(); i++)
    {
        if (adj[pos][i].first == parent[pos])
        {
            adj[pos][i].second *= alpha;
            break;
        }
    }
    for (int i = 0; i < adj[parent[pos]].size(); i++)
    {
        if (adj[parent[pos]][i].first == pos)
        {
            adj[parent[pos]][i].second *= alpha;
            break;
        }
    }
}

void Solution::choose_path(int i, int s, int v)
{
    paths[i].clear();
    int pos = v;
    paths[i].push_back(pos);
    while (pos != s)
    {
        update_adj(pos);
        pos = parent[pos];
        paths[i].push_back(pos);
    }
}

void Solution::solve()
{
    for (int i = 0; i < num_nets; i++)
    {
        int start_pos = nets[i].first.first + nets[i].first.second * cols;
        int end_pos = nets[i].second.first + nets[i].second.second * cols;
        dijkstra(start_pos);
        choose_path(i, start_pos, end_pos);
    }
}

void Solution::save_path(string output_file)
{
    ofstream fout(output_file);
    for (int i = 0; i < num_nets; i++)
    {
        fout << i << " " << paths[i].size() - 1 << endl;
        for (int j = paths[i].size() - 1; j > 0; j--)
        {
            int x1 = paths[i][j] % cols;
            int y1 = paths[i][j] / cols;
            int x2 = paths[i][j - 1] % cols;
            int y2 = paths[i][j - 1] / cols;
            fout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        }
    }
}
