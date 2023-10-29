#include <stdlib.h>

int main(int argc, char *argv[])
{
    int size = 10;
    int *solved = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            solved[i] = 0;
        }
        else if (i == 1)
        {
            solved[i] = 1;
        }
        else
        {
            solved[i] = solved[i - 1] + solved[i - 2];
        }
    }

    return 0;
}
