#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include "result.h"
#include <chrono>
#include <vector>

class CountingSort
{
private:
    chrono::high_resolution_clock::time_point start;
public:
    Result sort(vector<int> &input, vector<int> &output, int range);
};

#endif /* countginSort_h */
