#include "radixSort.h"

Result RadixSort::sort(vector<int> &array, int digit)
{
    start = chrono::high_resolution_clock::now();

    CountingSort sorter;

    for (int i = 0; i < digit; i++)
    {
        vector<int> temp(array.size());
        sorter.sort(array, temp, i);
        array = temp;
    }

    return Result(chrono::high_resolution_clock::now() - start);
}