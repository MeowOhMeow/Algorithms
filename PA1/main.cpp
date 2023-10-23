#include "util.h"
#include <chrono>
#include <iostream>

using namespace std;

// global variables
int the_best_score = 0;
int the_best_index = 0;

int main(int argc, char *argv[])
{
    auto start = chrono::high_resolution_clock::now();

    // main program
    vector<Pair> arr = init(argc, argv);
    sort(arr);              // quick sort
    build_best_paths(arr);  // this is the core function
    save(argv[2], arr, the_best_score, the_best_index);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}