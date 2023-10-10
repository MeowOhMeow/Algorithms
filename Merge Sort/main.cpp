#include "mergeSort.h"
#include "result.h"
#include <random>

int main()
{
    vector<int> array = {3, 5, 6, 4, 5, 1, 2, 4, 5};

    MergeSort sorter;
    Result result = sorter.sort(array);
    result.print();

    return 0;
}
