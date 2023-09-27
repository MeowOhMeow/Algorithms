#include "result.h"
using namespace std;

Result::Result(std::chrono::duration<double> elapsed)
{
    this->elapsed = elapsed;
}

void Result::print()
{
    cout << "Elapsed time: " << elapsed.count() << "s" << endl;
}
