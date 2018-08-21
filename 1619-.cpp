// 1619-.cpp (倍增)
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

struct edge {
    int to;
    int next;
} w[200001 << 1];

int d[200001] = {0}, prt[200001] = {0}, h[200001] = {0}, p[200001][18], m, n, root = 1, cnt = 0;

void add_edge(int mx, int my);
void dfs(int mx, int depth);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, x, y; i < n; i++) {
        std::cin >> x >> y;
        add_edge(x, y);
        prt[y] = x;
    }
    while (prt[root])
        root = prt[root];
    dfs(root, 1);
    memset(p, -1, sizeof p);
    for (int i = 1; i <= n; i++)
        p[i][0] = prt[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++)
            if (p[i][j - 1] != -1)
                p[i][j] = p[p[i][j - 1]][j - 1];
    for (int i = 1, x, y; i <= m; i++) {
        std::cin >> x >> y;
        if (d[x] < d[y])
            std::swap(x, y);
        int k = int(log2(d[x]));
        for (int j = k; j >= 0; j--)
            if (d[x] - (1 << j) >= d[y])
                x = p[x][j];
        if (x == y) {
            std::cout << y << '\n';
            continue;
        }
        for (int j = k; j >= 0; j--)
            if (p[x][j] != p[y][j]) {
                x = p[x][j];
                y = p[y][j];
            }
        std::cout << p[x][0] << '\n';
    }
    return 0;
}

void add_edge(int mx, int my) {
    w[++cnt].to = my;
    w[cnt].next = h[mx];
    h[mx] = cnt;
}

void dfs(int mx, int depth) {
    d[mx] = depth;
    for (int i = h[mx]; i; i = w[i].next)
        dfs(w[i].to, depth + 1);
}