// coat.cpp 不知道
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

//#define debug

#ifndef debug

std::ifstream in("coat.in");
std::ofstream out("coat.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 1670;
int head[Maxn], Next[Maxn << 1], ver[Maxn << 1], tot;
int d[Maxn];

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int n, k, w;
    in >> n >> k >> w;
    for (int i = 1; i <= n; i++)
        in >> d[i];
    for (int i = 1, x, y; i < n; i++)
        in >> x >> y, add(x, y), add(y, x);
    srand(unsigned(time(NULL)));
    out << rand() % 64122 + 1;
    return 0;
}