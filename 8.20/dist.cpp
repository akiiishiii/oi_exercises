// dist.cpp
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("dist.in");
std::ofstream out("dist.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 30005, Maxm = 60005;
int n, m, k, tot;
int head[Maxn], ver[Maxm], edge[Maxm], Next[Maxm];

void add(int x, int y, int z);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m >> k;
    for (int i = 1, a, b, c; i <= m; i++) {
        in >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    out << random(Maxm * Maxn) << ' ' << random(Maxm * Maxn) << '\n';
    return 0;
}

void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}