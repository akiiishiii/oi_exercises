// income.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("income.in");
std::ofstream out("income.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 2005;
int n, k, tot;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1], siz[Maxn];
long long edge[Maxn << 1], f[Maxn][Maxn];

void dp(int x, int p);
inline void add(int x, int y, int z);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> k;
    for (int i = 1, u, v, w; i < n; i++) {
        in >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
    dp(1, 0);
    out << f[1][k] << '\n';
    return 0;
}

inline void dp(int x, int p) {
    long long z;
    siz[x] = 1;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        dp(y, x);
        siz[x] += siz[y];
    }
    for (int i = 2; i <= siz[x]; ++i)
        f[x][i] = -1ll;
    f[x][0] = f[x][1] = 0ll;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        long long z = edge[i];
        if (y == p)
            continue;
        int dx = std::min(k, siz[x]);
        for (int j = dx; j >= 0; j--) {
            int dy = std::min(j, siz[y]);
            for (int l = 0; l <= dy && j >= l; ++l)
                if (f[x][j - l] != -1ll)
                    f[x][j] = std::max(
                        f[x][j],
                        f[x][j - l] + f[y][l] + (long long)l * (k - l) * z +
                            (long long)(siz[y] - l) * (n - k - siz[y] + l) * z);
        }
    }
}

inline void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}