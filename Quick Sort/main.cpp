#include "quickSort.h"
#include "result.h"
#include <iostream>
#include <random>

using namespace std;

int main()
{
    vector<int> array = {2, 4, 5, 3, 4, 0, 1, 3, 4};

    QuickSort sorter;
    Result result = sorter.sort(array);

    result.print();
}
