#ifndef MERGESORT_H
#define MERGESORT_H

#include "result.h"
#include <chrono>
#include <limits.h>

using namespace std;

class MergeSort
{
private:
    chrono::high_resolution_clock::time_point start;
    void copyArrays(vector<int> &array, vector<int> &arrayL, vector<int> &arrayR, int nl, int nr, int p, int q);
    void combine(vector<int> &array, vector<int> &arrayL, vector<int> &arrayR, int from, int to);
    void mergeSort(vector<int> &array, int p, int r);
    void merge(vector<int> &array, int p, int q, int r);

public:
    Result sort(vector<int> &array);
};

#endif /* mergeSort_h */
