#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>

using namespace std;

const int max_length = 10;
unordered_map<int, int> price_table = {{0, 0}, {1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};
unordered_map<int, int> solved_table;
vector<int> first_cut(max_length + 1, 0);

int get_price(int length)
{
    for (int size = 1; size <= length; size++)
    {
        int max_price = 0;
        int first_cut_size = 0;
        for (int sub_size = 1; sub_size <= size; sub_size++)
        {
            int price = price_table[sub_size] + solved_table[size - sub_size];
            if (price > max_price)
            {
                max_price = price;
                first_cut_size = sub_size;
            }
        }
        solved_table[size] = max_price;
        first_cut[size] = first_cut_size;
    }
    return solved_table[length];
}

int main()
{
    // int length;
    // cout << "Input the length of the rod: ";
    // cin >> length;
    // cout << "The maximum price is: " << get_price(length) << endl;
    cout << setw(4) << "i " << " ";
    for (int i = 0; i <= max_length; i++)
    {
        cout << setw(2) << i << " ";
    }
    cout << endl;
    cout << setw(4) << "r[i]" << " ";
    for (int i = 0; i <= max_length; i++)
    {
        cout << setw(2) << get_price(i) << " ";
    }
    cout << endl;
    cout << setw(4) << "s[i]" << " ";
    for (int i = 0; i <= max_length; i++)
    {
        cout << setw(2) << first_cut[i] << " ";
    }
    return 0;
}