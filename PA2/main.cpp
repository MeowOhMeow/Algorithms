#include "utility.h"

#include <iostream>
#include <chrono>

int main(int argc, char *argv[])
{
    auto start = std::chrono::steady_clock::now();
    init(argc, argv);
    sovle();
    save_path();
    auto end = std::chrono::steady_clock::now();
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    return 0;
}