#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <unordered_map>

#include "pair.h"

void solve();

extern unordered_map<int, int> pair_map;
extern vector<Pair> best_route;
extern int **max_subsets;
extern int num_of_points;
extern int best_score;

#endif // SOLUTION_H