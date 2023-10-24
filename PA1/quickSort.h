#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <random> // for rand(), i didn't set seed

using namespace std; // for vector

template <typename T>
void qsort(vector<T> &array, bool reverse=false)
{
    // add reverse sort to make it look more robust
    // this addtional operation cost O(1) and twice the QuickSort class size
    if (reverse)
    {
        reversequickSort(array, 0, array.size() - 1);
    }
    else
    {
        quickSort(array, 0, array.size() - 1);
    }
}

// use quick sort to sort the array
template <typename T>
void quickSort(vector<T> &array, int p, int r)
{
    if (p < r)
    {
        int q = randomizedPartition(array, p, r);
        quickSort(array, p, q - 1);
        quickSort(array, q + 1, r);
    }
}

// reversed one
template <typename T>
void reversequickSort(vector<T> &array, int p, int r)
{
    if (p < r)
    {
        int q = reverserandomizedPartition(array, p, r);
        reversequickSort(array, p, q - 1);
        reversequickSort(array, q + 1, r);
    }
}

// use random to choose pivot, this will make the worst case less possible
template <typename T>
inline int randomizedPartition(vector<T> &array, int p, int r)
{
    int i = rand() % (r - p) + p;
    _swap(array[r], array[i]);

    return partition(array, p, r);
}

// this function's name is too long, but i don't want to change it. and don't call it!!!
template <typename T>
inline int reverserandomizedPartition(vector<T> &array, int p, int r)
{
    int i = rand() % (r - p) + p;
    _swap(array[r], array[i]);

    return reversepartition(array, p, r);
}

// core function
template <typename T>
inline int partition(vector<T> &array, int p, int r)
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

// core function
template <typename T>
inline int reversepartition(vector<T> &array, int p, int r)
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

// just swap
template <typename T>
inline void _swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

#endif /* quickSort_h */
