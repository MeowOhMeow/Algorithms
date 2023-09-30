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

    vector<float>::iterator it = array.begin();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            *it = buckets[i][j];
            it++;
        }
    }

    return Result(chrono::high_resolution_clock::now() - start);
}