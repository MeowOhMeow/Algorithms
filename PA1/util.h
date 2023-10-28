#ifndef UTIL_H
#define UTIL_H

#include <fstream>
#include <string>

#include "debug.h"
#include "solution.h"   // for global variables
#include "mergeSort.h"

using namespace std;

void init(int argc, char *argv[]);
void save(char *filename);
void clean();

#endif // UTIL_H