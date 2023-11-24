#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void randomize(vector<float> &spaces, vector<float> &values)
{
    for (int i = 0; i < spaces.size(); i++)
    {
        spaces[i] = rand() % 100;
        values[i] = rand() % 100;
    }
}

void sort_by_weight(vector<float> &spaces, vector<float> &values)
{
    vector<float> weights(10);
    for (int i = 0; i < spaces.size(); i++)
    {
        weights[i] = values[i] / spaces[i];
    }
    // Bubble sort for convenience
    for (int i = 0; i < spaces.size(); i++)
    {
        for (int j = 0; j < spaces.size() - 1; j++)
        {
            if (weights[j] < weights[j + 1])
            {
                swap(weights[j], weights[j + 1]);
                swap(spaces[j], spaces[j + 1]);
                swap(values[j], values[j + 1]);
            }
        }
    }
    for (int i = 0; i < spaces.size(); i++)
    {
        cout << spaces[i] << " " << values[i] << " " << weights[i] << endl;
    }
}

void fill_knapsack(vector<float> &spaces, vector<float> &values)
{
    float knapsack_space = 100;
    float knapsack_value = 0;
    for (int i = 0; i < spaces.size(); i++)
    {
        if (spaces[i] <= knapsack_space)
        {
            knapsack_space -= spaces[i];
            knapsack_value += values[i];
            cout << "Taken: " << setw(4) << spaces[i] << " unit space with value: " << setw(4) << values[i] << endl;
        }
        else
        {
            knapsack_value += knapsack_space * (values[i] / spaces[i]);
            cout << "Taken: " << setw(4) << knapsack_space << " unit space with value: " << setw(4) << knapsack_space * (values[i] / spaces[i]) << endl;
            break;
        }
    }
    cout << "Knapsack value: " << knapsack_value << endl;
}

int main()
{
    vector<float> spaces(10);
    vector<float> values(10);
    randomize(spaces, values);
    sort_by_weight(spaces, values);
    fill_knapsack(spaces, values);
}