// news.cpp
#include <cstring>
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("news.in");
std::ofstream out("news.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 200005;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1];
int f[Maxn];
int n, tot;
bool mark[Maxn];

inline void add(int x, int y);
void dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    memset(f, 0, sizeof f);
    in >> n;
    for (int i = 2, prt; i <= n; i++) {
        in >> prt;
        add(prt, i), add(i, prt);
    }
    dfs(1);
    out << f[1] << '\n';
    // ......
    return 0;
}

inline void add(int x, int y) {
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void dfs(int x) {
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y != x)
            dfs(y, x);
        if (!mark[x])
            if (f[x] < f[y])
                mark[x] = true;
        if (mark[y])
            f[x] = std::max(f[x], f[y] + y);
    }
}