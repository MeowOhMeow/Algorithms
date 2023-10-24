#include "solution.h"

// i build the paths from the buttom to the peak(?), so I need to sort the array first
void sort(vector<Pair> &arr)
{
    qsort(arr, false);
}

// this is the core function, it takes O(n^2) time
void build_best_paths(vector<Pair> &arr)
{
    for (int i = 0; i < arr.size(); i++) // iterate through the array from the beginning
    {
        int best_score = 0;  // the best score of the previous pairs
        int best_index = -1; // set to -1 to indicate that there is no previous pair
        for (int j = 0; j < i; j++)
        {
            if (arr[i].get_lower() > arr[j].get_upper()) // whether the 2 pairs are compatible
            {
                if (arr[j].get_my_best_score() > best_score) // whether the previous pair has a better score
                {
                    best_score = arr[j].get_my_best_score();
                    best_index = j;
                }
            }
        }
        arr[i].set_my_best_score(best_score + 1);
        if (best_index != -1)
        {
            vector<Pair> best_route = arr[best_index].get_my_best_route();
            best_route.push_back(arr[i]);
            arr[i].set_my_best_route(best_route);
        }
        else // there is no previous pair, the best route is itself
        {
            vector<Pair> best_route;
            best_route.push_back(arr[i]);
            arr[i].set_my_best_route(best_route);
        }

        // update the best score and index
        if (arr[i].get_my_best_score() > the_best_score)
        {
            the_best_score = arr[i].get_my_best_score();
            the_best_index = i;
        }
    }
}