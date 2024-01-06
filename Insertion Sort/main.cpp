#include <iostream>
#include <vector>
#include <random>

#include "InsertionSort.h"

using namespace std;

int main()
{
    int array[] = { 5, 2, 4, 6, 1, 3 };
    sort(array);
    for (int val : array)
    {
        cout << val << " ";
    }
    cout << endl;

    vector<int> vec = { 5, 2, 4, 6, 1, 3 };
    sort(vec);
    for (int val : vec)
    {
        cout << val << " ";
    }
    cout << endl;

    int size = 10;
    int* dynamicArray = new int[size];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    for (int i = 0; i < size; ++i)
    {
        dynamicArray[i] = dis(gen);
    }
    sort(dynamicArray, size);
    for (int i = 0; i < size; ++i)
    {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

    return 0;
}