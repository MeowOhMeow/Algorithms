#include "insertionSort.h"
#include "result.h"
#include <random>

int main()
{
    int size = 10;
    vector<int> array(size);
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % size;
    }

    InsertionSort sorter;
    Result result = sorter.sort(array);
    result.print();

    return 0;
}
