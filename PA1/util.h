#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "debug.h"
#include "pair.h"

using namespace std;

string get_program_name(char *argv[]);
vector<Pair> init(int argc, char *argv[]);
vector<Pair> load(char *filename);
void save(char *filename, vector<Pair> &arr, int the_best_score, int the_best_index);

#endif // UTIL_H