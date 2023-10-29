#include <stdio.h>
#include <stdlib.h>

int size = 10;
int *solved;

void fibo(int n)
{
    for (int i = 0; i < n; i++)
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
}

int main(int argc, char *argv[])
{
    solved = (int *)malloc(sizeof(int) * size);
    fibo(size);
    printf("%d\n", solved[size - 1]);

    return EXIT_SUCCESS;
}
