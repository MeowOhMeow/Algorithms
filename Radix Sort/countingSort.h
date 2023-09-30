#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <chrono>
#include <vector>
#include <math.h>

using namespace std;

class CountingSort
{
private:
    chrono::high_resolution_clock::time_point start;
public:
    void sort(vector<int> &input, vector<int> &output, int digit);
};

#endif /* countginSort_h */
