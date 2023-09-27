#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <chrono>
#include "result.h"

using namespace std;

class HeapSort
{
private:
    chrono::high_resolution_clock::time_point start;
    void buildMaxHeap(vector<int> &array);
    void maxHeapify(vector<int> &array, int size, int index);
public:
    Result sort(vector<int> &array);
};

#endif /* heapsort_h */