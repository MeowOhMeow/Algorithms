#include "quickSort.h"

Result QuickSort::sort(vector<int> &array)
{
    start = chrono::high_resolution_clock::now();

    quickSort(array, 0, array.size() - 1);

    return Result(chrono::high_resolution_clock::now() - start);
}

void QuickSort::quickSort(vector<int> &array, int p, int r)
{
    if (p < r)
    {
        int q = partition(array, p, r);
        quickSort(array, p, q - 1);
        quickSort(array, q + 1, r);
    }
}

int QuickSort::randomizedPartition(vector<int> &array, int p, int r)
{
    int i = rand() % (r - p) + p;
    int temp = array[i];
    array[i] = array[r];
    array[r] = temp;

    return partition(array, p, r);
}

int QuickSort::partition(vector<int> &array, int p, int r)
{
    int x = array[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (array[j] <= x)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = x;
    array[r] = temp;

    return i + 1;
}
