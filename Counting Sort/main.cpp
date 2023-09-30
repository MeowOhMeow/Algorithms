#include "countingSort.h"
#include "result.h"
#include <random>

using namespace std;

int main()
{
    int range = 10;
    int size = 10;
    vector<int> input(size);
    vector<int> output(size);
    for (int i = 0; i < size; i++)
    {
        input[i] = rand() % range;
    }

    CountingSort sorter;
    Result result = sorter.sort(input, output, range);
    result.print();

    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}
