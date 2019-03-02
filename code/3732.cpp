// 3732.cpp
#include <algorithm>
#include <cstring>
#include <iostream>

int tot = 0, head[55], ver[105], Next[105], s[55];
int n, m, pos = 2333, mod = 1000000007;
long long ans[55][55];
bool vis[55];

inline void add(int u, int v) { ver[++tot] = v, Next[tot] = head[u], head[u] = tot; }
long long dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++) {
        std::cin >> n;
        s[t] = n, tot = 0;
        memset(head, 0, sizeof(head));
        for (int i = 1, j; i <= n; i++) {
            std::cin >> j;
            if (j)
                add(j, i), add(i, j);
        }
        for (int i = 1; i <= n; i++) {
            memset(vis, false, sizeof(vis));
            vis[i] = true;
            ans[t][i] = dfs(i);
        }
        std::sort(ans[t] + 1, ans[t] + 1 + n);
        for (int i = 1; i <= t; i++) {
            bool flag = false;
            for (int j = 1; j <= n; j++)
                if (ans[t][j] != ans[i][j])
                    flag = true;
            if (!flag) {
                std::cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}

long long dfs(int x) {
    long long res = pos, e[55];
    int ps = 0;
    for (int i = head[x]; i; i = Next[i])
        if (!vis[ver[i]])
            vis[ver[i]] = 1, e[++ps] = dfs(ver[i]);
    std::sort(e + 1, e + ps + 1);
    for (int i = 1; i <= ps; i++)
        res = ((res * pos) % mod + e[i]) % mod;
    return res;
}