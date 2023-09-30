#include "bucketSort.h"

Result BucketSort::sort(vector<float> &array)
{
    start = chrono::high_resolution_clock::now();

    int n = array.size();
    vector<vector<float>> buckets(n);
    for (int i = 0; i < n; i++)
    {
        buckets[int(n * array[i])].emplace_back(array[i]);
    }

    InsertionSort sorter;
    for (int i = 0; i < n; i++)
    {
        sorter.sort(buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            array[index++] = buckets[i][j];
        }
    }

    return Result(chrono::high_resolution_clock::now() - start);
}