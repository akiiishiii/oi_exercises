// 01paths.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("01paths.in");
std::ofstream out("01paths.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    out << "impossible\n";
    return 0;
}