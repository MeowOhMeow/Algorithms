#include <iostream>
#include <vector>

using namespace std;

class Set
{
public:
    int value;
    Set *representative;
};

Set *make_set(int x)
{
    Set *s = new Set;
    s->value = x;
    s->representative = s;
    return s;
}

Set *find_set(Set *x)
{
    if (x->representative == x)
    {
        return x;
    }
    else
    {
        return find_set(x->representative);
    }
}

void union_set(Set *x, Set *y)
{
    Set *x_rep = find_set(x);
    Set *y_rep = find_set(y);
    if (x_rep == y_rep)
    {
        return;
    }
    else
    {
        y_rep->representative = x_rep;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    vector<Set *> sets;
    for (int i = 0; i < 4; i++)
    {
        sets.push_back(make_set(arr[i]));
    }

    cout << "Find set" << endl;
    for (int i = 0; i < sets.size(); i++)
    {
        cout << find_set(sets[i])->value << endl;
    }

    cout << "Union 1 and 2" << endl;
    union_set(sets[0], sets[1]);
    cout << find_set(sets[0])->value << endl;
    cout << find_set(sets[1])->value << endl;

    cout << "Union 3 and 4" << endl;
    union_set(sets[2], sets[3]);
    cout << find_set(sets[2])->value << endl;
    cout << find_set(sets[3])->value << endl;

    cout << "Union 1 and 3" << endl;
    union_set(sets[0], sets[2]);
    cout << find_set(sets[0])->value << endl;
    cout << find_set(sets[1])->value << endl;
    cout << find_set(sets[2])->value << endl;
    cout << find_set(sets[3])->value << endl;
}