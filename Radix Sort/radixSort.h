#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <vector>
#include <chrono>
#include "result.h"
#include "countingSort.h"

class RadixSort
{
private:
    chrono::high_resolution_clock::time_point start;
public:
    Result sort(vector<int> &array, int digit);
};

#endif /* radixSort_h */
