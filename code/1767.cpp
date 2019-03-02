// 1767.cpp
#include <algorithm>
#include <iostream>

int const Maxn = 30010;

int tot = 0, head[Maxn], ver[Maxn], edge[Maxn], Next[Maxn];
int n, m, k;
int prt[Maxn], dep[Maxn], f[Maxn][16], pows[16], mx[Maxn][16];

struct edges {
    int u, v, w;
    bool operator<(edges const &y) const { return w < y.w; }
} b[Maxn];

inline void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
int search(int x) { return (prt[x] == x ? x : prt[x] = search(prt[x])); }
void kruskal();
void dfs(int x, int d, int p);
void st();
int lca(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, y;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        std::cin >> b[i].u >> b[i].v >> b[i].w;
    kruskal();
    dfs(1, 1, 0);
    st();
    while (k--) {
        std::cin >> x >> y;
        std::cout << lca(x, y) << '\n';
    }
    return 0;
}

void kruskal() {
    int num = 0;
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    std::sort(b + 1, b + m + 1);
    for (int i = 1; i <= m; i++) {
        int p1 = search(b[i].u), p2 = search(b[i].v);
        if (p1 != p2) {
            num++;
            add(b[i].u, b[i].v, b[i].w), add(b[i].v, b[i].u, b[i].w);
            prt[p1] = p2;
        }
        if (num == n - 1)
            break;
    }
}

void dfs(int x, int d, int p) {
    dep[x] = d;
    f[x][0] = p;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        mx[y][0] = edge[i];
        dfs(y, d + 1, x);
    }
}

void st() {
    pows[0] = 1;
    for (int i = 1; i <= 15; i++)
        pows[i] = pows[i - 1] * 2;
    for (int j = 1; j <= 15; j++)
        for (int i = 1; i <= n; i++)
            if (f[i][j - 1]) {
                f[i][j] = f[f[i][j - 1]][j - 1];
                mx[i][j] = std::max(mx[i][j - 1], mx[f[i][j - 1]][j - 1]);
            }
}

int lca(int x, int y) {
    int ret = 0xcfcfcfcf;
    if (dep[x] < dep[y])
        std::swap(x, y);
    int t = dep[x] - dep[y];
    for (int i = 0; pows[i] <= t; i++)
        if (t & pows[i])
            ret = std::max(ret, mx[x][i]), x = f[x][i];
    for (int i = 15; i >= 0; i--)
        if (f[x][i] != f[y][i])
            ret = std::max(ret, std::max(mx[x][i], mx[y][i])), x = f[x][i], y = f[y][i];
    if (x == y)
        return ret;
    return std::max(ret, std::max(mx[x][0], mx[y][0]));
}