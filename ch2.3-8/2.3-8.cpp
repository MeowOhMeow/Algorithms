#include <random>
#include <algorithm>
#include <iostream>

using namespace std;

int binarySearch(vector<int>::iterator begin, vector<int>::iterator end, int x)
{
    if (begin >= end)
    {
        return -1;
    }
    
    vector<int>::iterator mid = begin + (end - begin) / 2;
    if (*mid == x)
    {
        return mid - begin;
    }
    else if (*mid > x)
    {
        return binarySearch(begin, mid, x);
    }
    else
    {
        return binarySearch(mid + 1, end, x);
    }
}

int main()
{
    int x = 5;
    int size = 10;
    vector<int> array(size);
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % size;
    }

    sort(array.begin(), array.end());

    vector<int>::iterator it = unique(array.begin(), array.end());
    array.resize(distance(array.begin(), it));
    
    for (int i =  0; i < array.size(); i++)
    {
        int pos = binarySearch(array.begin(), array.begin() + i, x - array[i]);
        if (pos != -1)
        {
            cout << "Found " << x << " = " << array[i] << " + " << x - array[i] << endl;
        }
    }

    return 0;
}
