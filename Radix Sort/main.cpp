#include "radixSort.h"
#include <random>
#include <math.h>

int main()
{
    int size = 100;
    int digit = 3;
    int range = pow(10, digit);
    vector<int> array(size);
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % range;
    }

    RadixSort sorter;
    Result result = sorter.sort(array, digit);
    result.print();

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}