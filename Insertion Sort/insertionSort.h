#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "result.h"
#include <vector>
#include <chrono>

using namespace std;

class InsertionSort
{
private:
    chrono::high_resolution_clock::time_point start;

public:
    Result sort(vector<int> &array);
};

#endif /* insertionSort_h */
