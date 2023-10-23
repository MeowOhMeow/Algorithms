#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "result.h"
#include <random>

class QuickSort
{
private:
    chrono::high_resolution_clock::time_point start;
    void quickSort(vector<int> &array, int p, int r);
    int randomizedPartition(vector<int> &array, int p, int r);
    int partition(vector<int> &array, int p, int r);
public:
    Result sort(vector<int> &array);
};

#endif /* quickSort_h */
