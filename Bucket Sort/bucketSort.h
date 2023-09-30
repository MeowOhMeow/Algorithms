#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include "result.h"
#include "insertionSort.h"
#include <vector>
#include <chrono>

class BucketSort
{
private:
    chrono::high_resolution_clock::time_point start;
public:
    Result sort(vector<float> &array);
};

#endif /* bucketSort_h */
