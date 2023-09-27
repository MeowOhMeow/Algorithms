#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "result.h"

class QuickSort
{
private:
    chrono::high_resolution_clock::time_point start;
    void quickSort(vector<int> &array);
    int partition(vector<int> &array, int p, int r);
public:
    Result sort(vector<int> &array);
};

#endif /* quickSort_h */
