#include "solution.h"

unordered_map<int, int> pair_map;
vector<Pair> best_route;
int **max_subsets;
int num_of_points;
int best_score;
int current_score;

inline bool is_overlapping(int lower, int cord_point)
{
    return lower == cord_point;
}

inline bool is_inside(int lower, int cord_point, int upper)
{
    return lower < cord_point && cord_point < upper;
}

inline bool is_including_cord_larger(int lower, int cord_point, int upper)
{
    return max_subsets[lower][cord_point - 1] + max_subsets[cord_point + 1][upper - 1] + 1 > max_subsets[lower][upper - 1];
}

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

inline void solve_max_subset(int lower, int upper)
{
    int cord_point = pair_map[upper];
    // case 1: overlapping
    if (is_overlapping(lower, cord_point))
    {
        max_subsets[lower][upper] = max_subsets[lower][upper - 1] + 1;
    }
    // case 2: inside
    else if (is_inside(lower, cord_point, upper))
    {
        // case 2.1: if the max subset including the cord is larger than the max subset excluding the cord
        if (is_including_cord_larger(lower, cord_point, upper))
        {
            max_subsets[lower][upper] = max_subsets[lower][cord_point - 1] + max_subsets[cord_point + 1][upper - 1] + 1;
        }
        // case 2.2: otherwise
        else
        {
            max_subsets[lower][upper] = max_subsets[lower][upper - 1];
        }
    }
    // case 3: outside
    else
    {
        max_subsets[lower][upper] = max_subsets[lower][upper - 1];
    }
}

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
    current_score = best_score;
    best_route.resize(best_score);
}

void extract_best_subsets(int lower, int upper)
{
    if (lower >= upper)
    {
        return;
    }
    int cord_point = pair_map[upper];
    if (is_overlapping(lower, cord_point))
    {
        best_route[--current_score] = Pair(upper, cord_point);
        extract_best_subsets(lower, upper - 1);
    }
    else if (is_inside(lower, cord_point, upper))
    {
        if (is_including_cord_larger(lower, cord_point, upper))
        {
            best_route[--current_score] = Pair(upper, cord_point);
            extract_best_subsets(cord_point + 1, upper - 1);
            extract_best_subsets(lower, cord_point - 1);
        }
        else
        {
            extract_best_subsets(lower, upper - 1);
        }
    }
    else
    {
        extract_best_subsets(lower, upper - 1);
    }
}

void solve()
{
    init_max_subsets();
    solve_max_subsets();
    extract_best_subsets(0, num_of_points - 1);
}

// i build the paths from the buttom to the peak(?), so I need to sort the array first
void sort(vector<Pair> &arr)
{
    qsort(arr, false);
}
