#include "insertionSort.h"

void InsertionSort::sort(vector<float> &array)
{
    start = std::chrono::high_resolution_clock::now();

    int j = 0;

    for (int i = 1; i < array.size(); i++)
    {
        float key = array[i];

        j = i - 1;
        while (j >= 0 and array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}
