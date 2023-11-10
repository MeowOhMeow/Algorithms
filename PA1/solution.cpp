#include "solution.h"

// global variables
int *pair_map;
vector<Pair> best_route;
int **max_subsets;
int num_of_points;
int best_score;

// global variables for solution.cpp only
int idx = 0;

// solving!!!!!!!
void _solve_max_subsets()
{
    for (int del = 1; del < num_of_points; ++del)
    {
        int lower = 0;
        int upper = del;
        while (upper < num_of_points)
        {
            int cord_point = pair_map[upper];

            // case 1: overlapping
            if (lower == cord_point) // is overlapping
            {
                max_subsets[lower][upper] = max_subsets[lower][upper - 1] + 1;
            }
            // case 2: inside. if the max subset including the cord is larger than the max subset excluding the cord
            // if the first condition is not satisfied, the second condition will not be checked
            else if ((cord_point < upper && lower < cord_point)                                                                          // is inside. cord_point < upper is false more often than lower < cord_point, considering the smaller delta
                     && max_subsets[lower][cord_point - 1] + max_subsets[cord_point + 1][upper - 1] + 1 > max_subsets[lower][upper - 1]) // is including cord larger
            {
                max_subsets[lower][upper] = max_subsets[lower][cord_point - 1] + max_subsets[cord_point + 1][upper - 1] + 1;
            }
            // case 3: otherwise(outside and inside but failing the second condition)
            else
            {
                max_subsets[lower][upper] = max_subsets[lower][upper - 1];
            }

            ++lower;
            ++upper;
        }
    }

    best_score = max_subsets[0][num_of_points - 1];
    best_route.resize(best_score);
}

/*
    this function is called recursively to extract the best subsets

    in the worst case this function will be called n times, where n is the number of points
    from the given domain, the worst case is 10000
    the worst case: [(20000, 0), (19999, 1), (19998, 2), ... , (10001, 9999)]
*/
void _extract_best_subsets(int lower, int upper)
{
    if (lower >= upper)
    {
        return;
    }

    int cord_point = pair_map[upper];
    // case 1: overlapping.
    if (lower == cord_point) // is overlapping
    {
        best_route[idx++] = Pair(cord_point, upper);
        _extract_best_subsets(lower, upper - 1);
    }
    // case 2: if the max subset including the cord is larger than the max subset excluding the cord
    else if ((cord_point < upper && lower < cord_point)                                                                          // is inside. cord_point < upper is false more often than lower < cord_point, considering the smaller delta
             && max_subsets[lower][cord_point - 1] + max_subsets[cord_point + 1][upper - 1] + 1 > max_subsets[lower][upper - 1]) // is including cord larger
    {
        // is_including_cord_larger() is the only function that uses the max_subsets array...
        best_route[idx++] = Pair(cord_point, upper);
        // we need to extract the best subsets from both sides of the cord
        _extract_best_subsets(lower, cord_point - 1);
        _extract_best_subsets(cord_point + 1, upper - 1);
    }
    // case 3: otherwise
    else
    {
        _extract_best_subsets(lower, upper - 1);
    }
}

// this is the function that will be called in main
void solve()
{
    _solve_max_subsets();
    _extract_best_subsets(0, num_of_points - 1);
}
