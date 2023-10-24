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
    // data members
    int upper;
    int lower;

public:
    // constructors

    Pair() = default;
    Pair(int var1, int var2);

    // getters and setters

    int get_upper();
    int get_lower();

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