#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <random>       // for rand(), i didn't set seed

using namespace std;    // for vector

/*
    this class is used to sort the vector of data
    using quick sort
*/
template <typename T>
class QuickSort
{
private:
    void quickSort(vector<T> &array, int p, int r);
    void reverse_quickSort(vector<T> &array, int p, int r);
    int randomizedPartition(vector<T> &array, int p, int r);
    int reverse_randomizedPartition(vector<T> &array, int p, int r);
    int partition(vector<T> &array, int p, int r);
    int reverse_partition(vector<T> &array, int p, int r);
    void swap(T &a, T &b);
    bool reverse;

public:
    void sort(vector<T> &array, bool reverse = false);
};

// I tried to put the implementation in a separate file, but it didn't work
template <typename T>
void QuickSort<T>::sort(vector<T> &array, bool reverse)
{
    // add reverse sort to make it look more robust
    // this addtional operation cost O(1) and twice the QuickSort class size
    if (reverse)
    {
        reverse_quickSort(array, 0, array.size() - 1);
    }
    else
    {
        quickSort(array, 0, array.size() - 1);
    }
}

template <typename T>
void QuickSort<T>::quickSort(vector<T> &array, int p, int r)
{
    if (p < r)
    {
        int q = randomizedPartition(array, p, r);
        quickSort(array, p, q - 1);
        quickSort(array, q + 1, r);
    }
}

template <typename T>
void QuickSort<T>::reverse_quickSort(vector<T> &array, int p, int r)
{
    if (p < r)
    {
        int q = reverse_randomizedPartition(array, p, r);
        reverse_quickSort(array, p, q - 1);
        reverse_quickSort(array, q + 1, r);
    }
}

template <typename T>
inline int QuickSort<T>::randomizedPartition(vector<T> &array, int p, int r)
{
    int i = rand() % (r - p) + p;
    swap(array[r], array[i]);

    return partition(array, p, r);
}

// this function's name is too long, but i don't want to change it
template <typename T>
inline int QuickSort<T>::reverse_randomizedPartition(vector<T> &array, int p, int r)
{
    int i = rand() % (r - p) + p;
    swap(array[r], array[i]);

    return reverse_partition(array, p, r);
}

template <typename T>
inline int QuickSort<T>::partition(vector<T> &array, int p, int r)
{
    T x = array[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (array[j] <= x)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[r]);

    return i + 1;
}

template <typename T>
inline int QuickSort<T>::reverse_partition(vector<T> &array, int p, int r)
{
    T x = array[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (array[j] >= x)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[r]);

    return i + 1;
}

template <typename T>
inline void QuickSort<T>::swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

#endif /* quickSort_h */
