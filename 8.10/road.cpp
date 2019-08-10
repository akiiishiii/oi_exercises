// road.cpp
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("road.in");
std::ofstream out("road.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int random(int n) { return (long long)rand() * rand() % n; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    srand((unsigned)std::time(NULL));
    out << random(2009) << '\n';
    return 0;
}