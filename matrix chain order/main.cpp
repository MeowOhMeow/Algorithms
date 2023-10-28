#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>

using namespace std;

const int length = 6;
vector<std::pair<int, int>> matrix_dim = {{5, 10}, {10, 3}, {3, 12}, {12, 5}, {5, 50}, {50, 6}} ;
vector<vector<int>> cost_table(length, vector<int>(length, 0));
vector<vector<int>> first_cut(length, vector<int>(length, 0));

void cal_matix_chain_order()
{
    for (int l = 2; l <= length; l++)
    {
        for (int i = 0; i <= length - l; i++)
        {
            int j = i + l - 1;
            cost_table[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = cost_table[i][k] + cost_table[k + 1][j] + matrix_dim[i].first * matrix_dim[k].second * matrix_dim[j].second;
                if (cost < cost_table[i][j])
                {
                    cost_table[i][j] = cost;
                    first_cut[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    cal_matix_chain_order();
    for (int i = 0; i < length; i++)
    {
        if (i != 0)
            cout << setw(6 * i) << " ";
        for (int j = i + 1; j < length; j++)
        {
            cout << setw(5) << cost_table[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < length; i++)
    {
        if (i != 0)
            cout << setw(6 * i) << " ";
        for (int j = i + 1; j < length; j++)
        {
            cout << setw(5) << first_cut[i][j] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}