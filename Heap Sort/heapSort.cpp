#include "heapSort.h"

Result HeapSort::sort(vector<int> &array)
{
    start = chrono::high_resolution_clock::now();

    buildMaxHeap(array);
    int heapSize = array.size();
    for (int i = array.size() - 1; i >= 1; i--)
    {
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;

        heapSize--;

        maxHeapify(array, heapSize, 0);
    }

    return Result(chrono::high_resolution_clock::now() - start);
}

void HeapSort::buildMaxHeap(vector<int> &array)
{
    int heapSize = array.size();
    for (int i = heapSize / 2; i >= 0; i--)
    {
        maxHeapify(array, heapSize, i);
    }
}

void HeapSort::maxHeapify(vector<int> &array, int size, int index)
{
    int left = 2 * index + 1;
    int right = left + 1;
    int largestIndex = index;

    if (left < size and array[left] > array[largestIndex])
    {
        largestIndex = left;
    }
    if (right < size and array[right] > array[largestIndex])
    {
        largestIndex = right;
    }

    if (largestIndex != index)
    {
        int temp = array[index];
        array[index] = array[largestIndex];
        array[largestIndex] = temp;

        maxHeapify(array, size, largestIndex);
    }
}
