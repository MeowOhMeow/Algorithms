#include "radixSort.h"

Result RadixSort::sort(vector<int> &array, int digit)
{
    start = chrono::high_resolution_clock::now();

    CountingSort sorter;

    int upperBound = pow(10, digit);
    for (int exp = 1; exp < upperBound; exp*=10)
    {
        vector<int> temp(array.size());
        sorter.sort(array, temp, exp);
        array = temp;
    }

    return Result(chrono::high_resolution_clock::now() - start);
}