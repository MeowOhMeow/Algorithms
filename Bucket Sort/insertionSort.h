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
    void sort(vector<float> &array);
};

#endif /* insertionSort_h */
