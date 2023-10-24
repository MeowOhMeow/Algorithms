#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <random>       // for rand(), i didn't set seed

using namespace std;    // for vector

template <typename T>
void qsort(vector<T> &array, bool reverse)
{
    // add reverse sort to make it look more robust
    // this addtional operation cost O(1) and twice the QuickSort class size
    if (reverse)
    {
        _reverse_quickSort(array, 0, array.size() - 1);
    }
    else
    {
        _quickSort(array, 0, array.size() - 1);
    }
}

// this is private. don't call it!!!
template <typename T>
void _quickSort(vector<T> &array, int p, int r) 
{
    if (p < r)
    {
        int q = _randomizedPartition(array, p, r);
        _quickSort(array, p, q - 1);
        _quickSort(array, q + 1, r);
    }
}

// private!!!
template <typename T>
void _reverse_quickSort(vector<T> &array, int p, int r) 
{
    if (p < r)
    {
        int q = _reverse_randomizedPartition(array, p, r);
        _reverse_quickSort(array, p, q - 1);
        _reverse_quickSort(array, q + 1, r);
    }
}

// don't!!!
template <typename T>
inline int _randomizedPartition(vector<T> &array, int p, int r) 
{
    int i = rand() % (r - p) + p;
    _swap(array[r], array[i]);

    return _partition(array, p, r);
}

// this function's name is too long, but i don't want to change it. and don't call it!!!
template <typename T>
inline int _reverse_randomizedPartition(vector<T> &array, int p, int r)
{
    int i = rand() % (r - p) + p;
    _swap(array[r], array[i]);

    return _reverse_partition(array, p, r);
}

// stop!!!
template <typename T>
inline int _partition(vector<T> &array, int p, int r) 
{
    T x = array[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (array[j] <= x)
        {
            i++;
            _swap(array[i], array[j]);
        }
    }
    _swap(array[i + 1], array[r]);

    return i + 1;
}

// just stop!!!
template <typename T>
inline int _reverse_partition(vector<T> &array, int p, int r) 
{
    T x = array[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (array[j] >= x)
        {
            i++;
            _swap(array[i], array[j]);
        }
    }
    _swap(array[i + 1], array[r]);

    return i + 1;
}

// this is ok
template <typename T>
inline void _swap(T &a, T &b) 
{
    T temp = a;
    a = b;
    b = temp;
}

#endif /* quickSort_h */
