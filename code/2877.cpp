// 2877.cpp
#include <iostream>

int n, a[205][205], ans = 0;
bool vis[205];

void dfs(int v, int d);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        dfs(i, 1);
    std::cout << ans << '\n';
    return 0;
}

void dfs(int v, int d) {
    if (d == n) {
        ans++;
        return;
    }
    vis[v] = true;
    for (int i = 1; i <= n; i++)
        if (a[v][i] && !vis[i])
            dfs(i, d + 1);
    vis[v] = false;
}