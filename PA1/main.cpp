#include "util.h"
#include "solution.h"

#include <chrono>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    auto start = chrono::high_resolution_clock::now();

    // main program
    init(argc, argv);
    solve();
    sort(best_route); // quick sort
    save(argv[2]);    // save the result

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: "
         << duration.count() / 1000 << " milliseconds" << endl;
    return 0;
}