#ifndef GRAPH_H

#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <fstream>
#include <algorithm>

#include "debug.h"
#include "Dijkstra.h"

#define MAX_ITER 1

using namespace std;

class Graph : public Dijkstra
{
private:
    int row, col;
    int capacity;
    float alpha;

    void choose_path(int i, int s, int v);
    void update_adj(int pos);
    int find_overflow_lines();
    void find_overflow_paths();
    void update_paths();

public:
    Graph() = default;
    Graph(int row, int col, int capacity);

    void solve();
    void save_path(string output_file);
};

extern int num_nets;
extern vector<pair<pair<int, int>, pair<int, int>>> nets;

#endif // GRAPH_H