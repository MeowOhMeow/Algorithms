#ifndef UTIL_H
#define UTIL_H

#include <fstream>
#include <string>

#include "debug.h"
#include "solution.h"   // for global variables
#include "quickSort.h"

using namespace std;

string get_program_name(char *argv[]);
void init(int argc, char *argv[]);
void init_max_subsets();
void load(char *filename);
void save(char *filename);
void clean();

#endif // UTIL_H