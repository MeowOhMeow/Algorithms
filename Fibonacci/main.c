#include <stdlib.h>
#include <stdio.h>

int *solved;
int size = 20;
int solved_size = 2;

int fibo(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n < solved_size)
    {
        return solved[n];
    }
    else
    {
        int result = fibo(n - 1) + fibo(n - 2);
        solved = (int *)realloc(solved, sizeof(int) * (solved_size + 1));
        solved[solved_size] = result;
        solved_size++;
        return result;
    }
}

int main(int argc, char *argv[])
{
    solved = (int *)malloc(sizeof(int) * size);
    solved[0] = 0;
    solved[1] = 1;

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", fibo(i));
    }

    return 0;
}
