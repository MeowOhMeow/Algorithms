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

void approach1(vector<int> &array, int x)
{
    cout << "Approach 1" << endl;

    for (int i = 0; i < array.size(); i++)
    {
        int pos = binarySearch(array.begin(), array.begin() + i, x - array[i]);
        if (pos != -1)
        {
            cout << "Found " << x << " = " << array[i] << " + " << x - array[i] << endl;
        }
    }

    cout << endl;
}

void approach2(vector<int> &array, int x)
{
    cout << "Approach 2" << endl;

    int a = 0;
    int b = array.size() - 1;
    while (a < b)
    {
        if (array[a] + array[b] < x)
            a++;
        else if (array[a] + array[b] > x)
            b--;
        else
        {
            cout << "Found " << x << " = " << array[a] << " + " << array[b] << endl;
            break;
        }
    }

    cout << endl;
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

    approach1(array, x);
    approach2(array, x);

    return 0;
}
