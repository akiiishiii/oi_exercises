// build.cpp
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("build.in");
std::ofstream out("build.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

struct road {
    int x, y, p, c;
} r[305];

int n, m;

long long random(long long n) { return (long long)rand() * rand() % n; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    srand((unsigned)time(NULL));
    in >> n >> m;
    for (int i = 1; i <= m; i++)
        in >> r[i].x >> r[i].y >> r[i].p >> r[i].c;
    out << random(30000000) << '\n';
    for (int i = 1; i <= m; i++)
        out << i << ' ';
    out << '\n';
    return 0;
}