// 1474_.cpp
#include <cmath>
#include <cstring>
#include <iostream>

int const SIZE = 200005;
int n, m, tot;
int ver[SIZE << 1], Next[SIZE << 1], head[SIZE];
int d[SIZE], prt[SIZE], f[SIZE][20], s[SIZE];

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs_1(int x, int depth);
void st();
int lca(int a, int b);
void dfs_2(int x, int p);

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long ans = 0;
    std::cin >> n >> m;
    for (int i = 1, x, y; i < n; i++) {
        std::cin >> x >> y;
        add(x, y);
        prt[y] = x;
    }
    dfs_1(1, 0);
    st();
    for (int i = 1, x, y, dlca; i <= m; i++) {
        std::cin >> x >> y;
        dlca = lca(x, y);
        s[x]++, s[y]++;
        s[dlca] -= 2;
    }
    dfs_2(1, 0);
    for (int i = 2; i <= n; i++) {
        if (!s[i])
            ans += m;
        else if (s[i] == 1)
            ans++;
    }
    std::cout << ans << "\n";
    return 0;
}

void dfs_1(int x, int depth) {
    d[x] = depth;
    for (int i = head[x]; i; i = Next[i])
        dfs_1(ver[i], depth + 1);
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

void dfs_2(int x, int p) {
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        dfs_2(y, x);
        s[x] += s[y];
    }
}