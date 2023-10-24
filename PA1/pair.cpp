#include "pair.h"

/*
    arguments: var1, var2
    return: none
    description: constructor for Pair class
*/
Pair::Pair(int var1, int var2)
{
    // the data is not guaranteed to be in order
    // although it is in order from the solution function
    if (var1 < var2)
    {
        lower = var1;
        upper = var2;
    }
    else
    {
        lower = var2;
        upper = var1;
    }
}

/*
    arguments: none
    return: the higher value
    description: getter for higher
*/
int Pair::get_upper()
{
    return upper;
}

/*
    arguments: none
    return: the lower value
    description: getter for lower
*/
int Pair::get_lower()
{
    return lower;
}
