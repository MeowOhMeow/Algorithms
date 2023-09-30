#include "countingSort.h"

Result CountingSort::sort(vector<int> &input, vector<int> &output, int range)
{
    start = chrono::high_resolution_clock::now();

    vector<int> working(range, 0);

    for (int i = 0; i < input.size(); i++)
    {
        working[input[i]]++;
    }

    working[0]--;   // Adjust for 0 indexing
    for (int i = 1; i < working.size(); i++)
    {
        working[i] += working[i-1];
    }

    for (int i = input.size()-1; i >= 0; i--)
    {
        output[working[input[i]]] = input[i];
        working[input[i]]--;
    }

    return Result(chrono::high_resolution_clock::now() - start);
}
