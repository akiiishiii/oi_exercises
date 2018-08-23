// 1458.cpp
#include <cmath>
#include <iostream>
#include <algorithm>

int n, m, prt[10005], h[10005], cnt = 0, vv[10005] = {0}, d[10005] = {0}, p[10005][30], g[10005][30];

struct {
    int next;
    int to;
    int v;
} a[10005 << 1];

struct edge {
    int x;
    int y;
    int z;
    bool operator<(edge const &e) const { return z < e.z; }
} e[50001];

int search(int x) { return prt[x] == x ? x : prt[x] = search(prt[x]); }
void addedge(int mx, int my, int mv);
void kruskal();
void dfs(int x, int fa, int dd);
void st();
int lca(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int q;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
        std::cin >> e[i].x >> e[i].y >> e[i].z;
    std::sort(e + 1, e + m + 1);
    kruskal();
    for (int i = 1; i <= n; i++)
        prt[i] = -1;
    for (int i = 1; i <= n; i++)
        if (prt[i] == -1)
            dfs(i, -1, 1);
    st();
    std::cin >> q;
    for (int i = 1, x, y; i <= q; i++) {
        std::cin >> x >> y;
        std::cout << lca(x, y) << '\n';
    }
    return 0;
}

void addedge(int mx, int my, int mv) {
    a[++cnt].to = my;
    a[cnt].next = h[mx];
    a[cnt].v = mv;
    h[mx] = cnt;
}

void kruskal() {
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    for (int i = 1; i <= m; i++) {
        int x = e[i].x, y = e[i].y, fx = search(x), fy = search(y);
        if (fx == fy)
            continue;
        prt[fx] = fy;
        addedge(x, y, e[i].z);
        addedge(y, x, e[i].z);
    }
}

void dfs(int x, int fa, int dd) {
    d[x] = dd;
    for (int i = h[x]; i; i = a[i].next) {
        if (a[i].to == fa)
            continue;
        prt[a[i].to] = x;
        vv[a[i].to] = a[i].v;
        dfs(a[i].to, x, dd + 1);
    }
}

void st() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 28; j++)
            p[i][j] = -1;
    for (int i = 1; i <= n; i++) {
        p[i][0] = prt[i];
        g[i][0] = vv[i];
    }
    for (int j = 1; j <= log2(n); j++)
        for (int i = 1; i <= n; i++) {
            p[i][j] = p[p[i][j - 1]][j - 1];
            g[i][j] = std::max(g[p[i][j - 1]][j - 1], g[i][j - 1]);
        }
}

int lca(int x, int y) {
    int ret = 0;
    if (d[x] < d[y])
        std::swap(x, y);
    int k = log2(d[x]);
    for (int j = k; j >= 0; j--)
        if (d[x] - (1 << j) >= d[y]) {
            ret = std::max(ret, g[x][j]);
            x = p[x][j];
        }
    if (x == y)
        return ret;
    for (int j = k; j >= 0; j--)
        if (d[x] - (1 << j) >= 1 && p[x][j] != p[y][j] && p[x][j] != 1) {
            ret = std::max(ret, std::max(g[x][j], g[y][j]));
            x = p[x][j];
            y = p[y][j];
        }
    if (p[x][0] == -1)
        return -1;
    ret = std::max(ret, std::max(g[x][0], g[y][0]));
    return ret;
}