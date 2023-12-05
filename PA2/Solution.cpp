#include "Solution.h"

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

    // maintain 0.2 times of capacity to avoid bit overflow
    alpha = log(100) / log(capacity);
    if (alpha < 1.1)
    {
        alpha = 1.1;
        if (log(numeric_limits<float>::max() / 2) / log(capacity) < 1.1)
        {
            cout << "capacity is too large!!!!!!!!!!!!" << endl;
            exit(1);
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

void Graph::update_adj(int pos)
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

void Graph::choose_path(int i, int s, int v)
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

int Graph::find_overflow_lines()
{
    overflow_lines.clear();
    float MAX_WEIGHT = pow(alpha, capacity + 1);
    for (int i = 0; i < vertices; i++)
    {
        int x1 = i / col;
        int y1 = i % col;
        for (int j = 0; j < adj[i].size(); j++)
        {
            int x2 = adj[i][j].first / col;
            int y2 = adj[i][j].first % col;
            if (adj[i][j].second > MAX_WEIGHT)
            {
                overflow_lines.push_back(make_pair(i, adj[i][j].first));
                cout << "overflow line: (" << x1 << ", " << y1 << ") -> (" << x2 << ", " << y2 << ")" << endl;
            }
        }
    }
    cout << "overflow lines: " << overflow_lines.size() << endl;
    return overflow_lines.size();
}

void Graph::find_overflow_paths()
{
    overflow_paths.clear();
    for (int i = 0; i < num_nets; i++)
    {
        for (int j = 0; j < paths[i].size() - 1; j++)
        {
            for (int k = 0; k < overflow_lines.size(); k++)
            {
                if ((paths[i][j] == overflow_lines[k].first && paths[i][j + 1] == overflow_lines[k].second) ||
                    (paths[i][j] == overflow_lines[k].second && paths[i][j + 1] == overflow_lines[k].first))
                {
                    overflow_paths.push_back(i);
                    break;
                }
            }
        }
    }
    sort(overflow_paths.begin(), overflow_paths.end());
    overflow_paths.erase(unique(overflow_paths.begin(), overflow_paths.end()), overflow_paths.end());
}

void Graph::update_paths()
{
    // divide edges by alpha to get the weight without overflow lines
    for (int i = 0; i < overflow_paths.size(); i++)
    {
        int pos = overflow_paths[i];
        for (int j = 0; j < paths[pos].size() - 1; j++)
        {
            for (int k = 0; k < adj[paths[pos][j]].size(); k++)
            {
                if (adj[paths[pos][j]][k].first == paths[pos][j + 1])
                {
                    adj[paths[pos][j]][k].second /= alpha;
                    break;
                }
            }
            for (int k = 0; k < adj[paths[pos][j + 1]].size(); k++)
            {
                if (adj[paths[pos][j + 1]][k].first == paths[pos][j])
                {
                    adj[paths[pos][j + 1]][k].second /= alpha;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < overflow_paths.size(); i++)
    {
        int idx = overflow_paths[i];
        int start_pos = nets[idx].first.first * col + nets[idx].first.second;
        int end_pos = nets[idx].second.first * col + nets[idx].second.second;
        dijkstra(start_pos);
        choose_path(idx, start_pos, end_pos);
    }
}

void Graph::solve()
{
    for (int i = 0; i < num_nets; i++)
    {
        int start_pos = nets[i].first.first * col + nets[i].first.second;
        int end_pos = nets[i].second.first * col + nets[i].second.second;
        dijkstra(start_pos);
        choose_path(i, start_pos, end_pos);
    }

    // int count = 0;
    // while (find_overflow_lines() != 0)
    // {
    //     find_overflow_paths();
    //     update_paths();
    //     count++;
    //     if (count > MAX_ITER)
    //     {
    //         break;
    //     }
    // }
}

void Graph::save_path(string output_file)
{
    ofstream fout(output_file);
    for (int i = 0; i < num_nets; i++)
    {
        fout << i << " " << paths[i].size() - 1 << endl;
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
