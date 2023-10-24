#ifndef PAIR_H
#define PAIR_H

#include <vector>

using namespace std;

/*
    this class is used to store the pairs of numbers

    the pair will be defined as (upper, lower)
    where upper is the larger number and lower is the smaller number
*/
class Pair
{
private:
    

public:
    // constructors

    Pair() = default;
    Pair(int var1, int var2);

    // data members

    int upper;
    int lower;

    // operators
    bool operator<=(const Pair &rhs) const
    {
        return (lower <= rhs.lower);
    }

    bool operator>=(const Pair &rhs) const
    {
        return (lower >= rhs.lower);
    }
};

#endif /* pair_h */