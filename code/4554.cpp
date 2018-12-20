// 4554.cpp
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

int const SIZE = 50500;
int n, m, tot, cnt, top;
int ver[SIZE << 1], Next[SIZE << 1], head[SIZE];
int d[SIZE], prt[SIZE], f[SIZE][20], c[SIZE], dfn[SIZE];

struct query {
    int x, y;
    int a, b, i;
    bool operator<(query const &n) const { return ((c[x] == c[n.x]) ? (dfn[y] < dfn[n.y]) : (c[x] < c[n.x])); }
} q[SIZE << 1];

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs(int x, int prt);
void st();
int lca(int a, int b);

int main(int argc, char const *argv[]) {
    std::cin >>
    return 0;
}

void dfs(int x, int p) {
    d[x] = d[p];
    int k, bottom = top;
    dfn[x] = ++cnt;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        prt[y] = x;
        d[y] = d[x] + 1
        dfs(y, x);
    }
}

void st() {
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[i][0] = prt[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++)
            if (f[i][j - 1] != -1)
                f[i][j] = f[f[i][j - 1]][j - 1];
}

int lca(int a, int b) {
    int k;
    if (d[a] < d[b])
        std::swap(a, b);
    k = int(log2(d[a]));
    for (int i = k; i >= 0; i--)
        if (d[a] - (1 << i) >= d[b])
            a = f[a][i];
    if (a == b)
        return b;
    for (int i = k; i >= 0; i--)
        if (f[a][i] != -1 && f[a][i] != f[b][i]) {
            a = f[a][i];
            b = f[b][i];
        }
    return f[a][0];
}