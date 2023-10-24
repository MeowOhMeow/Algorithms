#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include "pair.h"
#include "quickSort.h"

using namespace std;

void sort(vector<Pair> &arr);
void build_best_paths(vector<Pair> &arr);

extern int the_best_score;
extern int the_best_index;

#endif // SOLUTION_H