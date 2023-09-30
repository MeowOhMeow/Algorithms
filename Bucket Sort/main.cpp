#include "bucketSort.h"
#include <random>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> distribution(0.0, 1.0);
    
    int size = 100;
    vector<float> array(size);
    for (int i = 0; i < size; i++)
    {
        array[i] = distribution(gen);
    }

    BucketSort sorter;
    Result result = sorter.sort(array);
    result.print();

    return 0;
}