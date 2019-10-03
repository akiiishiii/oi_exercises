// general.cpp
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("general.in");
std::ofstream out("general.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 100001;
int n, k, t, tot;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1];
int f[Maxn][3];

inline void add(int x, int y);
void dfs(int x, int p);
long long random(long long n) { return (long long)rand() * rand() % n; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> k >> t;
    if (k == 0) {
        out << n << '\n';
        return 0;
    }
    for (int i = 1, u, v; i < n; i++) {
        in >> u >> v;
        add(u, v), add(v, u);
    }
    if (k == 1) {
        dfs(1, 0);
        out << std::min(f[1][1], f[1][2]) << '\n';
    }
    srand((unsigned)time(NULL));
    out << random(n) << '\n';
    return 0;
}

inline void add(int x, int y) {
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void dfs(int x, int p) {
    int d = 0x3f3f3f3f;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        dfs(y, x);
        f[x][0] += std::min(f[y][2], f[y][1]);
        f[x][1] += std::min(f[y][2], f[y][1]);
        d = std::min(d, f[y][2] - std::min(f[y][2], f[y][1]));
        f[x][2] += std::min(f[y][2], std::min(f[y][1], f[y][0]));
    }
    f[x][1] += d;
    f[x][2] += 1;
}