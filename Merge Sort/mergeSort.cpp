#include "mergeSort.h"

Result MergeSort::sort(vector<int> &array)
{
    start = std::chrono::high_resolution_clock::now();
    mergeSort(array, 0, array.size() - 1);

    return Result(std::chrono::high_resolution_clock::now() - start);
}

void MergeSort::copyArrays(vector<int> &array, vector<int> &arrayL, vector<int> &arrayR, int nl, int nr, int p, int q)
{
    for (int i = 0; i < nl; i++)
    {
        arrayL[i] = array[p + i];
    }
    for (int i = 0; i < nr; i++)
    {
        arrayR[i] = array[q + i + 1];
    }
    arrayL[nl] = INT_MAX;
    arrayR[nr] = INT_MAX;
}

void MergeSort::combine(vector<int> &array, vector<int> &arrayL, vector<int> &arrayR, int from, int to)
{
    int i = 0, j = 0;
    for (int k = from; k <= to; k++)
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
    }
}

void MergeSort::merge(vector<int> &array, int p, int q, int r)
{
    int nl = q - p + 1;
    int nr = r - q;
    vector<int> arrayL(nl + 1);
    vector<int> arrayR(nr + 1);

    copyArrays(array, arrayL, arrayR, nl, nr, p, q);

    combine(array, arrayL, arrayR, p, r);
    cout << "Step " << ++step << ": ";
    for (int i = p; i <= r; i++)
    {
        cout << dict[array[i]] << " ";
    }
    cout << " merge" << endl;
}

void MergeSort::mergeSort(vector<int> &array, int p, int r)
{
    cout << "Step " << ++step << ": ";
    for (int i = p; i <= r; i++)
    {
        cout << dict[array[i]] << " ";
    }
    cout << " divide" << endl;
    if (p >= r)
        return;

    int q = (p + r) / 2;

    mergeSort(array, p, q);
    mergeSort(array, q + 1, r);

    merge(array, p, q, r);
}
