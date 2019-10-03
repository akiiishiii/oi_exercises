// brackets.cpp
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

//#define debug

#ifndef debug

std::ifstream in("brackets.in");
std::ofstream out("brackets.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

long long random(long long n) { return (long long)rand() * rand() % n; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    srand(unsigned(time(NULL)));
    std::string s;
    in >> s;
    out << random(s.length()) << '\n';
    return 0;
}
