// division.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("division.in");
std::ofstream out("division.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int n;
    in >> n;
    out << n << '\n';
    return 0;
}