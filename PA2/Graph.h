#ifndef GRAPH_H

#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <fstream>

#include "debug.h"

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
    vector<float> d;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    // paths
    vector<vector<int>> paths;

    void choose_path(int i, int s, int v);
    void dijkstra(int s);
    void update_adj(int pos);

public:
    Graph() = default;
    Graph(int row, int col, int capacity);
    void del();

    void init_single_source(int s);

    void solve();
    void save_path(string output_file);
};

extern int num_nets;
extern vector<pair<pair<int, int>, pair<int, int>>> nets;

#endif // GRAPH_H
