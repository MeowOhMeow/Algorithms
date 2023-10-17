#include "countingSort.h"
#include "result.h"
#include "data.h"

#include <random>

using namespace std;

int main()
{
    int range = 10;
    int size = 100;
    vector<Data> input(size);
    vector<Data> output(size);
    for (int i = 0; i < size; i++)
    {
        input[i] = Data(rand() % range);
    }

    CountingSort sorter;
    Result result = sorter.sort(input, output, range);
    result.print();

    return 0;
}
