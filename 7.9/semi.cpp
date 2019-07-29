// semi.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

//#define debug

#ifndef debug

std::ifstream in("semi.in");
std::ofstream out("semi.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    srand(unsigned(time(NULL)));
    out << rand() << '\n' << rand() <<< '\n';
    return 0;
}
