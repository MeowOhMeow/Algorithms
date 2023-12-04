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

    // maintain 0.2 times of capacity to avoid bit overflow
    float reserved = 0.2;
    float ratio = 1.4;
    if (log(numeric_limits<float>::max() / log(ratio)) < capacity / (1 - reserved))
    {
        alpha = log(numeric_limits<float>::max() / log(capacity / (1 - reserved)));
    }
    else
    {
        alpha = ratio;
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

void Graph::init_single_source(int s)
{
    for (int i = 0; i < vertices; i++)
    {
        d[i] = INF;
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
        int pos = overflow_paths[i];
        dijkstra(pos);
        choose_path(pos, nets[pos].first.first * col + nets[pos].first.second, nets[pos].second.first * col + nets[pos].second.second);
    }
}

void Graph::solve()
{
    for (int i = 0; i < num_nets; i++)
    {
        dijkstra(i);
        choose_path(i, nets[i].first.first * col + nets[i].first.second, nets[i].second.first * col + nets[i].second.second);
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
