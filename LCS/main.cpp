#include <iostream>
#include <string>

#define X_EQUALS_Y 1
#define X_LESS_THAN_Y 2
#define X_GREATER_THAN_Y 3

using namespace std;

string x = "ABCBDAB";
string y = "BDCABA";
int matrix[8][7];
int direction[8][7];

void LCS()
{
    for (int i = 0; i < 8; i++)
    {
        matrix[i][0] = 0;
    }
    for (int j = 0; j < 7; j++)
    {
        matrix[0][j] = 0;
    }
    for (int i = 1; i < 8; i++)
    {
        for (int j = 1; j < 7; j++)
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
    cout << "i: " << i << " j: " << j << endl;
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

int main()
{
    LCS();
    print(7, 6);
    return 0;
}
