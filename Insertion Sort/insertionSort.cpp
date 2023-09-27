#include "insertionSort.h"

Result InsertionSort::sort(vector<int> &array)
{
    start = std::chrono::high_resolution_clock::now();

    int j = 0;

    for (int i = 1; i < array.size(); i++)
    {
        int key = array[i];

        j = i - 1;
        while (j >= 0 and array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }

    return Result(std::chrono::high_resolution_clock::now() - start);
}
