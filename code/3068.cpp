// 3068.cpp
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
struct Edge {
    int ver, edge, next;
} e[2000010];

int tot, n, m, prt[1000010], edge[1000010], head[1000010];
int f[1000010][3], len[1000010], g[1000010][20];
int ff[1000010][20], ans;

inline void add(int x, int y, int z) { e[++tot].ver = y, e[tot].edge = z, e[tot].next = head[x], head[x] = tot; }
void dp1(int x);
void dp2(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 2, x, y; i <= n; i++) {
        std::cin >> x >> y;
        add(x, i, y);
        prt[i] = x;
        edge[i] = y;
    }
    dp1(1);
    dp2(1);
    for (int i = 1; i <= n; i++) {
        len[i] = std::max(f[i][0], f[i][1]);
        g[i][0] = ff[i][0] = len[i];
    }
    for (int j = 1; j <= int(log2(double(n))); j++) {
        for (int i = 1; i <= (n - (1 << j) + 1); i++) {
            g[i][j] = std::min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
            ff[i][j] = std::max(ff[i][j - 1], ff[i + (1 << (j - 1))][j - 1]);
        }
    }
    int l = 1, r = 0;
    int minn = 100000000, maxx = -10000000;
    for (int i = 1; i <= n; i++) {
        if (len[++r] > maxx)
            maxx = len[i];
        if (len[r] < minn)
            minn = len[i];
        while (maxx - minn > m && l < r) {
            int t = int(log2(double(r - (++l) + 1)));
            maxx = std::max(ff[l][t], ff[r - (1 << t) + 1][t]);
            minn = std::min(g[l][t], g[r - (1 << t) + 1][t]);
        }
        if (r - l + 1 > ans)
            ans = r - l + 1;
    }
    std::cout << ans << '\n';
    return 0;
}

void dp1(int x) {
    for (int t = head[x]; t; t = e[t].next) {
        dp1(e[t].ver);
        if (f[x][1] < f[e[t].ver][1] + e[t].edge) {
            f[x][2] = f[x][1];
            f[x][1] = f[e[t].ver][1] + e[t].edge;
        }
        else if (f[x][2] < f[e[t].ver][1] + e[t].edge)
            f[x][2] = f[e[t].ver][1] + e[t].edge;
    }
}

void dp2(int x) {
    if (prt[x] != 0) {
        if (f[prt[x]][1] == f[x][1] + edge[x])
            f[x][0] = std::max(f[prt[x]][0], f[prt[x]][2]) + edge[x];
        else
            f[x][0] = std::max(f[prt[x]][0], f[prt[x]][1]) + edge[x];
    }
    for (int t = head[x]; t; t = e[t].next)
        dp2(e[t].ver);
}