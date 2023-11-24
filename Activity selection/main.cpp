#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generate_random_activities(vector<pair<int, int>> &activities, int n)
{
    for (int i = 0; i < n; i++)
    {
        int start = rand() % 100;
        int end = start + rand() % 99 + 1;
        activities.push_back(make_pair(start, end));
    }
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

vector<pair<int, int>> greedy_select(vector<pair<int, int>> &activities)
{
    vector<pair<int, int>> selected;
    selected.push_back(activities[0]);
    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[i].first >= selected.back().second)
        {
            selected.push_back(activities[i]);
        }
    }
    return selected;
}

void print_activities(vector<pair<int, int>> &activities)
{
    cout << "Selected activities: " << endl;
    cout << "Length: " << activities.size() << endl;
    cout << "Start End" << endl;
    for (int i = 0; i < activities.size(); i++)
    {
        cout << activities[i].first << " " << activities[i].second << endl;
    }
}

int main()
{
    vector<pair<int, int>> activities;
    generate_random_activities(activities, 100);
    sort(activities.begin(), activities.end(), compare);
    vector<pair<int, int>> selected = greedy_select(activities);
    print_activities(selected);
}