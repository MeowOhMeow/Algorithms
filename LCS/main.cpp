#include <iostream>
#include <string>
#include <iomanip>

#define X_EQUALS_Y 1
#define X_LESS_THAN_Y 2
#define X_GREATER_THAN_Y 3

using namespace std;

string x = "10010101";
string y = "010110110";
int length_x = x.length() + 1;
int length_y = y.length() + 1;
int **matrix = new int *[length_x];
int **direction = new int *[length_x];

void init()
{
    for (int i = 0; i < length_x; i++)
    {
        matrix[i] = new int[length_y];
        direction[i] = new int[length_y];
    }
    for (int i = 0; i < length_x; i++)
    {
        matrix[i][0] = 0;
    }
    for (int j = 0; j < length_y; j++)
    {
        matrix[0][j] = 0;
    }
}

void LCS()
{
    for (int i = 1; i < length_x; i++)
    {
        for (int j = 1; j < length_y; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
                direction[i][j] = X_EQUALS_Y;
            }
            else if (matrix[i - 1][j] >= matrix[i][j - 1])
            {
                matrix[i][j] = matrix[i - 1][j];
                direction[i][j] = X_GREATER_THAN_Y;
            }
            else
            {
                matrix[i][j] = matrix[i][j - 1];
                direction[i][j] = X_LESS_THAN_Y;
            }
        }
    }
}

void print(int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (direction[i][j] == X_EQUALS_Y)
    {
        print(i - 1, j - 1);
        cout << x[i - 1];
    }
    else if (direction[i][j] == X_GREATER_THAN_Y)
    {
        print(i - 1, j);
    }
    else
    {
        print(i, j - 1);
    }
}

void LCS2()
{
    for (int i = 1; i < length_x; i++)
    {
        for (int j = 1; j < length_y; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }
            else if (matrix[i - 1][j] >= matrix[i][j - 1])
            {
                matrix[i][j] = matrix[i - 1][j];
            }
            else
            {
                matrix[i][j] = matrix[i][j - 1];
            }
        }
    }
}

void print2(int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (x[i - 1] == y[j - 1])
    {
        print2(i - 1, j - 1);
        cout << x[i - 1];
    }
    else if (matrix[i - 1][j] >= matrix[i][j - 1])
    {
        print2(i - 1, j);
    }
    else
    {
        print2(i, j - 1);
    }
}

int main()
{
    init();

    // LCS();
    // print(length_x - 1, length_y - 1);
    // cout << endl;

    LCS2();
    print2(length_x - 1, length_y - 1);
    cout << endl;

    cout << "Table: " << endl;
    cout << setw(6) << " ";
    for (int j = 0; j < length_x; j++)
        cout << setw(3) << y[j];
    cout << endl;
    for (int i = 0; i < length_x; i++)
    {
        if (i == 0)
            cout << setw(3) << " ";
        else
            cout << setw(3) << x[i - 1];
        for (int j = 0; j < length_y; j++)
        {
            cout << setw(3) << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
