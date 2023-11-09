#include "util.h"
#include "solution.h"

#include <iostream>


using namespace std;

/*
    arguments: argc, argv[]
    return: int
    description: main function
*/
int main(int argc, char *argv[])
{

    // main program
    init(argc, argv);
    solve();
    msort(best_route); // merge sort
    save(argv[2]);     // save the result
    clean();           // clean up


    return 0;
}