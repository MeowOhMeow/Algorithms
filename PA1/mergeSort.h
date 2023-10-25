#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

using namespace std;

// by inspection, the array is almost sorted in ascending order, so I use merge sort
template <typename T>
void msort(vector<T> &array)
{
    mergeSort(array, 0, array.size() - 1);
}

template <typename T>
void copyArrays(vector<T> &array, vector<T> &arrayL, vector<T> &arrayR, int nl, int nr, int p, int q)
{
    for (int i = 0; i < nl; i++)
    {
        arrayL[i] = array[p + i];
    }
    for (int i = 0; i < nr; i++)
    {
        arrayR[i] = array[q + i + 1];
    }
}

template <typename T>
void combine(vector<T> &array, vector<T> &arrayL, vector<T> &arrayR, int from, int to)
{
    int i = 0, j = 0;
    int k = from; // Start index for the merged array

    // Merge elements from arrayL and arrayR back into array
    while (i < arrayL.size() && j < arrayR.size())
    {
        if (arrayL[i] <= arrayR[j])
        {
            array[k] = arrayL[i];
            i++;
        }
        else
        {
            array[k] = arrayR[j];
            j++;
        }
        k++;
    }

    // below 2 while loops will execute only one of them
    // Copy the remaining elements of arrayL, if any
    while (i < arrayL.size())
    {
        array[k] = arrayL[i];
        i++;
        k++;
    }

    // Copy the remaining elements of arrayR, if any
    while (j < arrayR.size())
    {
        array[k] = arrayR[j];
        j++;
        k++;
    }
}

template <typename T>
void merge(vector<T> &array, int p, int q, int r)
{
    int nl = q - p + 1;
    int nr = r - q;
    vector<T> arrayL(nl);
    vector<T> arrayR(nr);

    copyArrays(array, arrayL, arrayR, nl, nr, p, q);

    combine(array, arrayL, arrayR, p, r);
}

template <typename T>
void mergeSort(vector<T> &array, int p, int r)
{
    if (p >= r)
        return;

    int q = (p + r) / 2;

    mergeSort(array, p, q);
    mergeSort(array, q + 1, r);

    merge(array, p, q, r);
}

#endif /* mergeSort_h */
