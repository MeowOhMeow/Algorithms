#ifndef PAIR_H
#define PAIR_H

#include <vector>

using namespace std;

/*
    this class is used to store the pairs of numbers
    and the best route and score for each pair

    the pair will be defined as (upper, lower)
    where higher is the larger number and lower is the smaller number
*/
class Pair
{
private:
    // data members
    int upper;
    int lower;
    int my_best_score;
    vector<Pair> my_best_route;

public:
    // constructors

    Pair() = default;
    Pair(int var1, int var2);

    // getters and setters

    int get_upper();
    int get_lower();
    int get_my_best_score();
    vector<Pair> get_my_best_route();
    void set_my_best_score(int score);
    void set_my_best_route(vector<Pair> route);

    /*
        arguments: Pair
        return: bool
        description: overload the <= operator
    */
    bool operator<=(const Pair &p) const
    {
        return (this->upper <= p.upper);
    }

    /*
        arguments: Pair
        return: bool
        description: overload the >= operator
    */
    bool operator>=(const Pair &p) const
    {
        return (this->upper >= p.upper);
    }
};

#endif /* pair_h */