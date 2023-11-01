#include "solution.h"

using namespace std;

// global variables
unordered_map<int, int> pair_map;
vector<Pair> best_route;
int **max_subsets;
int num_of_points;
int best_score;

// global variables for solution.cpp only
int idx = 0;

// this function is the most frequently called function in solve_max_subset()
inline bool _is_overlapping(int lower, int cord_point)
{
    // this is very simple logic, but is_overlapping() is more readable
    return lower == cord_point;
}

// this function is called only when is_overlapping() is false
inline bool _is_inside(int lower, int cord_point, int upper)
{
    // implenting the logic: lower < cord_point < upper
    // cord_point < upper is false more often than lower < cord_point, considering the smaller delta
    return cord_point < upper && lower < cord_point;
}

// this function is called only when is_inside() is true
inline bool _is_including_cord_larger(int lower, int cord_point, int upper)
{
    return max_subsets[lower][cord_point - 1] + max_subsets[cord_point + 1][upper - 1] + 1 > max_subsets[lower][upper - 1];
}

// i can't think of a better name for this function
inline void _solve_max_subset(int lower, int upper)
{
    int cord_point = pair_map[upper];
    // case 1: overlapping
    if (_is_overlapping(lower, cord_point))
    {
        max_subsets[lower][upper] = max_subsets[lower][upper - 1] + 1;
    }
    // case 2: inside. if the max subset including the cord is larger than the max subset excluding the cord
    // if the first condition is not satisfied, the second condition will not be checked
    else if (_is_inside(lower, cord_point, upper) && _is_including_cord_larger(lower, cord_point, upper))
    {
        max_subsets[lower][upper] = max_subsets[lower][cord_point - 1] + max_subsets[cord_point + 1][upper - 1] + 1;
    }
    // case 3: otherwise(outside and inside but failing the second condition)
    else
    {
        max_subsets[lower][upper] = max_subsets[lower][upper - 1];
    }
}

// solving!!!!!!!
void _solve_max_subsets()
{
    for (int del = 1; del < num_of_points; del++)
    {
        int lower = 0;
        int upper = del;
        while (upper < num_of_points)
        {
            _solve_max_subset(lower, upper);
            lower++;
            upper++;
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
    if (_is_overlapping(lower, cord_point))
    {
        best_route[idx++] = Pair(cord_point, upper);
        _extract_best_subsets(lower, upper - 1);
    }
    // case 2: if the max subset including the cord is larger than the max subset excluding the cord
    else if (_is_inside(lower, cord_point, upper) && _is_including_cord_larger(lower, cord_point, upper))
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
