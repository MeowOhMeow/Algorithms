#include "quickSort.h"
#include "result.h"
#include <iostream>
#include <random>

using namespace std;

int main()
{
    int size = 10000;
    vector<int> array(size);
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % size;
    }

    QuickSort sorter;
    Result result = sorter.sort(array);

    result.print();
}
