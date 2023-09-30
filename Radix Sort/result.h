#ifndef RESULT_H
#define RESULT_H

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Result
{
private:
    std::chrono::duration<double> elapsed;

public:
    Result(std::chrono::duration<double> elapsed);
    void print();
};

#endif /* result_h */
