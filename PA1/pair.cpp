#include "pair.h"

/*
    arguments: var1, var2
    return: none
    description: constructor for Pair class
*/
Pair::Pair(int var1, int var2)
{
    // the data is not guaranteed to be in order
    if (var1 > var2)
    {
        upper = var1;
        lower = var2;
    }
    else
    {
        upper = var2;
        lower = var1;
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

/*
    arguments: none
    return: the best score
    description: getter for my_best_score
*/
int Pair::get_my_best_score()
{
    return my_best_score;
}

/*
    arguments: none
    return: the best route
    description: getter for my_best_route
*/
vector<Pair> Pair::get_my_best_route()
{
    return my_best_route;
}

/*
    arguments: score
    return: none
    description: setter for my_best_score
*/
void Pair::set_my_best_score(int score)
{
    my_best_score = score;
}

/*
    arguments: route
    return: none
    description: setter for my_best_route
*/
void Pair::set_my_best_route(vector<Pair> route)
{
    my_best_route = route;
}