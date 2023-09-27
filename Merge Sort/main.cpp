#include "mergeSort.h"
#include "result.h"
#include <random>

int main()
{
    int size = 100000;
    vector<int> array(size);
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % size;
    }

    MergeSort sorter;
    Result result = sorter.sort(array);
    result.print();

    return 0;
}
