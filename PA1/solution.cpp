#include "solution.h"

unordered_map<int, int> pair_map;
vector<Pair> best_route;
int **max_subsets;
int num_of_points;
int best_score;
int idx = 0;

// this function is the most frequently called function in solve_max_subset()
inline bool is_overlapping(int lower, int cord_point)
{
    // this is very simple logic, but is_overlapping() is more readable
    return lower == cord_point;
}

// this function is called only when is_overlapping() is false
inline bool is_inside(int lower, int cord_point, int upper)
{
    // implenting the logic: lower < cord_point < upper
    // cord_point < upper is false more often than lower < cord_point, considering the smaller delta
    return cord_point < upper && lower < cord_point;
}

// this function is called only when is_inside() is true
inline bool is_including_cord_larger(int lower, int cord_point, int upper)
{
    return max_subsets[lower][cord_point - 1] + max_subsets[cord_point + 1][upper - 1] + 1 > max_subsets[lower][upper - 1];
}

// initializing the max_subsets array
void init_max_subsets()
{
    max_subsets = new int *[num_of_points];
    for (int i = 0; i < num_of_points; i++)
    {
        max_subsets[i] = new int[num_of_points];
        for (int j = 0; j < num_of_points; j++)
        {
            max_subsets[i][j] = 0;
        }
    }
}

// i can't think of a better name for this function
inline void solve_max_subset(int lower, int upper)
{
    int cord_point = pair_map[upper];
    // case 1: overlapping
    if (is_overlapping(lower, cord_point))
    {
        max_subsets[lower][upper] = max_subsets[lower][upper - 1] + 1;
    }
    // case 2: inside. if the max subset including the cord is larger than the max subset excluding the cord
    // if the first condition is not satisfied, the second condition will not be checked
    else if (is_inside(lower, cord_point, upper) && is_including_cord_larger(lower, cord_point, upper))
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
void solve_max_subsets()
{
    for (int del = 1; del < num_of_points; del++)
    {
        int lower = 0;
        int upper = del;
        while (upper < num_of_points)
        {
            solve_max_subset(lower, upper);
            lower++;
            upper++;
        }
    }

    best_score = max_subsets[0][num_of_points - 1];
    best_route.resize(best_score);
}

// this function is called recursively to extract the best subsets
void extract_best_subsets(int lower, int upper)
{
    if (lower >= upper)
    {
        return;
    }
    int cord_point = pair_map[upper];
    // case 1: overlapping.
    if (is_overlapping(lower, cord_point))
    {
        best_route[idx++] = Pair(upper, cord_point);
        extract_best_subsets(lower, upper - 1);
    }
    // case 2: if the max subset including the cord is larger than the max subset excluding the cord
    else if (is_inside(lower, cord_point, upper) && is_including_cord_larger(lower, cord_point, upper))
    {
        // is_including_cord_larger() is the only function that uses the max_subsets array...
        best_route[idx++] = Pair(upper, cord_point);
        // we need to extract the best subsets from both sides of the cord
        extract_best_subsets(lower, cord_point - 1);
        extract_best_subsets(cord_point + 1, upper - 1);
    }
    // case 3: otherwise
    else
    {
        extract_best_subsets(lower, upper - 1);
    }
}

// this is the function that will be called in main
void solve()
{
    init_max_subsets();
    solve_max_subsets();
    extract_best_subsets(0, num_of_points - 1);
}
