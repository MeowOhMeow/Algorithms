#include <iostream>

using namespace std;

void halfAdd(bool a, bool b, bool &s, bool &c)
{
    s = a ^ b;
    c = a & b;
}

void fullAdd(bool a, bool b, bool c, bool &s, bool &d)
{
    bool s1, c1, c2;
    halfAdd(a, b, s1, c1);
    halfAdd(s1, c, s, c2);
    d = c1 | c2;
}

void add(bool a[], bool b[], bool c[], int n)
{
    bool s, d;
    d = 0;
    for (int i = 0; i < n; i++)
    {
        fullAdd(a[i], b[i], d, s, d);
        c[i] = s;
    }
    c[n] = d;
}

int main()
{
    bool arra[4], arrb[4], arrc[5];
    for (int i = 3; i >= 0; i--)
    {
        cin >> arra[i];
    }
    for (int i = 3; i >= 0; i--)
    {
        cin >> arrb[i];
    }
    add(arra, arrb, arrc, 4);
    for (int i = 4; i >= 0; i--)
    {
        cout << arrc[i];
    }
    return 0;
}
