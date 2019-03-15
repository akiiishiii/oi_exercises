// 3969.cpp
#include <iostream>
#include <vector>

int const Maxn = 2005;
int n, m, k;
int head[Maxn], ver[Maxn * 3], Next[Maxn * 3], tot = 0;
int vis[Maxn], d[Maxn], g[Maxn], ans = false;
std::vector<int> v[Maxn];

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m >> k;
    for (int i = 1, x, y; i <= m; i++)
        std::cin >> x >> y, add(x, y);
    for (int i = 1, x; i <= k; i++) {
        std::cin >> x;
        dfs(x);
        ans ^= d[x];
    }
    std::cout << (ans ? "win\n" : "lose\n");
    return 0;
}

void dfs(int x) {
    if (vis[x])
        return;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        dfs(y);
        v[x].push_back(d[y]);
    }
    vis[x] = true;
    for (int i = 0; i < v[x].size(); i++)
        g[v[x][i]] = 1;
    for (int i = 0; i <= n; i++)
        if (!g[i]) {
            d[x] = i;
            break;
        }
    for (int i = 0; i < v[x].size(); i++)
        g[v[x][i]] = 0;
}