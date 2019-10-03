// game.cpp
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

//#define debug

#ifndef debug

std::ifstream in("game.in");
std::ofstream out("game.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

long long random(long long n) { return (long long)rand() * rand() % n; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    srand(unsigned(time(NULL)));
    int n;
    in >> n;
    out << random(n) << '\n';
    return 0;
}
