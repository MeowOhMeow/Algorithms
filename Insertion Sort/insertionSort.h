#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>
#include <cstddef>

// for dynamic arrays
template <typename T>
void sort(T* array, size_t size)
{
    for (size_t i = 1; i < size; ++i)
    {
        T key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

// for static arrays
template <typename T, size_t N>
void sort(T (&array)[N])
{
    for (size_t i = 1; i < N; ++i)
    {
        T key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

// for vectors
template <typename T>
void sort(std::vector<T>& vec)
{
    for (size_t i = 1; i < vec.size(); ++i)
    {
        T key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

#endif // INSERTIONSORT_H