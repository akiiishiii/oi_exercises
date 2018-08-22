// 1623.cpp
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

struct edge {
    int to;
    int next;
    int v;
} w[1001 << 1];

int d[1001] = {0}, prt[1001] = {0}, h[1001] = {0}, vs[1001] = {0}, p[1001][11], m, n, root = 1, cnt = 0;

void add_edge(int mx, int my, int mv);
void dfs(int mx, int depth, int mv);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, x, y, v; i < n; i++) {
        std::cin >> x >> y >> v;
        add_edge(x, y, v);
        prt[y] = x;
    }
    while (prt[root])
        root = prt[root];
    dfs(root, 1, 0);
    memset(p, -1, sizeof p);
    for (int i = 1; i <= n; i++)
        p[i][0] = prt[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++)
            if (p[i][j - 1] != -1)
                p[i][j] = p[p[i][j - 1]][j - 1];
    for (int i = 1, x, y; i <= m; i++) {
        std::cin >> x >> y;
        int vx = vs[x], vy = vs[y];
        if (d[x] < d[y])
            std::swap(x, y);
        int k = int(log2(d[x]));
        for (int j = k; j >= 0; j--)
            if (d[x] - (1 << j) >= d[y])
                x = p[x][j];
        if (x == y) {
            std::cout << vx + vy - 2 * vs[y] << '\n';
            continue;
        }
        for (int j = k; j >= 0; j--)
            if (p[x][j] != p[y][j]) {
                x = p[x][j];
                y = p[y][j];
            }
        std::cout << vx + vy - 2 * vs[p[x][0]] << '\n';
    }
    return 0;
}

void add_edge(int mx, int my, int mv) {
    w[++cnt].to = my;
    w[cnt].next = h[mx];
    w[cnt].v = mv;
    h[mx] = cnt;
}

void dfs(int mx, int depth, int mv) {
    d[mx] = depth;
    vs[mx] += mv + w[mx].v;
    for (int i = h[mx]; i; i = w[i].next) {
        dfs(w[i].to, depth + 1, vs[i]);
    }
}