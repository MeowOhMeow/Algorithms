#include "countingSort.h"

void CountingSort::sort(vector<int> &input, vector<int> &output, int exp)
{
    vector<int> working(10, 0);

    for (int i = 0; i < input.size(); i++)
    {
        int index = input[i] / exp % 10;
        working[index]++;
    }

    working[0]--;   // Adjust for 0 indexing
    for (int i = 1; i < working.size(); i++)
    {
        working[i] += working[i-1];
    }

    for (int i = input.size()-1; i >= 0; i--)
    {
        int index = input[i] / exp % 10;
        output[working[index]] = input[i];
        working[index]--;
    }
}
