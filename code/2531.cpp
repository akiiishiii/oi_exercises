// 2531.cpp
#include <cstring>
#include <iostream>

bool map[505][505], vis[505];
int my[505], n, m;

bool dfs(int i);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (std::cin >> n >> m && (n || m)) {
        memset(map, false, sizeof(map));
        memset(my, 0, sizeof(my));
        for (int i = 1, x, y; i <= m; i++) {
            std::cin >> x >> y;
            map[x][y] = true;
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (i != j)
                        map[i][j] = (map[i][j]) || (map[i][k] && map[k][j]);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            memset(vis, 0, sizeof(vis));
            if (dfs(i))
                ans++;
        }
        std::cout << n - ans << '\n';
    }
    return 0;
}

bool dfs(int i) {
    for (int j = 1; j <= n; j++)
        if (!vis[j] && map[i][j]) {
            vis[j] = 1;
            if (!my[j] || dfs(my[j])) {
                my[j] = i;
                return true;
            }
        }
    return false;
}