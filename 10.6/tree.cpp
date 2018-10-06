// tree.cpp
#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>

#define debug

#ifndef debug

std::ifstream in("tree.in");
std::ofstream out("tree.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

const int Maxn = 100010;
int f[Maxn][20], d[Maxn], son[Maxn], prt[Maxn];
int ver[Maxn << 1], Next[Maxn << 1], head[Maxn];
int n, m, tot, t, maxd = 1;
bool v[Maxn] = {false};
std::queue<int> q;

inline void add(int x, int y) { ver[++tot] = y; Next[tot] = head[x]; head[x] = tot; }
void bfs();
void dfs(int x);
int lca(int x, int y);
int pprt(int x, int ds);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n;
    t = int(log2(n)) + 1;
    for (int i = 1; i <= n; i++)
        head[i] = d[i] = 0, son[i] = 1, prt[i] = i;
    tot = 0;
    for (int i = 1, x, y; i < n; i++) {
        in >> x >> y;
        add(x, y);
        add(y, x);
    }
    bfs();
    dfs(1);
    in >> m;
    for (int i = 1, x, y, res, dd, dlca; i <= m; i++) {
        in >> x >> y;
        dlca = lca(x, y);
        dd = d[x] + d[y] - 2 * d[dlca];
        if (dd & 1)
            res = 0;
        else if (x == y)
            res = n;
        dd /= 2;
        if (d[x] < d[y])
            std::swap(x, y);
        int z = x;
        z = pprt(z, d[z] - dd);
        if (z != dlca)
            res = son[z] - son[pprt(x, d[z] + 1)];
        else
            res = n - son[pprt(x, d[z] + 1)] - son[pprt(y, d[z] + 1)];
        out << res << '\n';
    }
    return 0;
}

void bfs() {
    q.push(1);
    d[1] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i];
            if (d[y])
                continue;
            d[y] = d[x] + 1;
            prt[y] = x;
            maxd = std::max(maxd, d[y]);
            f[y][0] = x;
            for (int j = 1; j <= t; j++)
                f[y][j] = f[f[y][j - 1]][j - 1];
            q.push(y);
        }
    }
}

void dfs(int x) {
    if (d[x] == maxd)
        return;
    v[x] = true;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (!v[y]) {
            dfs(y);
            son[x] += son[y];
        }
    }
}

int lca(int x, int y) {
    if (d[x] > d[y])
        std::swap(x, y);
    for (int i = t; i >= 0; i--)
        if (d[f[y][i]] >= d[x])
            y = f[y][i];
    if (x == y)
        return x;
    for (int i = t; i >= 0; i--)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}

int pprt(int x, int ds) {
    int k = int(log2(d[x]));
    for (int i = k; i >= 0; i--)
        if (d[x] - (1 << i) >= ds)
            x = f[x][i];
    return x;
}