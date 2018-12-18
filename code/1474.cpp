// 1474.cpp
#include <cmath>
#include <iostream>
#include <queue>

int const SIZE = 100010;
int f[SIZE][20], d[SIZE];
int ver[SIZE << 1], Next[SIZE << 1], head[SIZE];
int s[SIZE];
int n, m, tot, t;
std::queue<int> q;

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void bfs();
int lca(int x, int y);
void dfs(int x, int p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long ans = 0;
    std::cin >> n >> m;
    t = int(log2(n)) + 1;
    for (int i = 1, x, y; i < n; i++) {
        std::cin >> x >> y;
        add(x, y), add(y, x);
    }
    bfs();
    for (int i = 1, x, y, dlca; i <= m; i++) {
        std::cin >> x >> y;
        dlca = lca(x, y);
        s[x]++, s[y]++;
        s[dlca] -= 2;
    }
    dfs(1, 0);
    for (int i = 2; i <= n; i++)
        switch (s[i]) {
        case 0:
            ans += m;
            break;
        case 1:
            ans++;
            break;
        default:
            break;
        }
    std::cout << ans << '\n';
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
            f[y][0] = x;
            for (int j = 1; j <= t; j++)
                f[y][j] = f[f[y][j - 1]][j - 1];
            q.push(y);
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

void dfs(int x, int p) {
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[x];
        if (y == p)
            continue;
        dfs(y, x);
        s[x] += s[y];
    }
}