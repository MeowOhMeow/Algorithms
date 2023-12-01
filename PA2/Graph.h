#ifndef GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

#define NIL -1

using namespace std;

class Graph
{
private:
    int row, col;
    float capacity;
    int vertices;
    int **demand;
    // (adjacent, weight)
    vector<vector<pair<int, float>>> adj;
    vector<int> parent;
    vector<int> d;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    // paths
    vector<vector<int>> paths;

    float get_distance(int demand);
    void load_demand();
    void choose_path(int i, int s, int v);
    void print_path(int s, int v);
    void dijkstra(int s);

public:
    Graph() = default;
    Graph(int row, int col, int capacity);
    void reset();

    void init_single_source(int s);

    void solve();
    void print_path();
};

extern int num_nets;
extern vector<pair<pair<int, int>, pair<int, int>>> nets;

#endif // GRAPH_H
