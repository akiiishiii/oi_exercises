// 2543.cpp
#include <cstring>
#include <iostream>

int mat[205][205], v[205], c[205], gap[205], vis[205];
int n, m, sum = 0;

int dfs(int x, int maxf);
int sap();
void dfs(int u);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> m >> n;
    for (int i = 1, x; i <= m; i++) {
        std::cin >> v[i];
        sum += v[i];
        while (std::cin >> x && x) {
            mat[i][x + m] = (1 << 30);
        }
    }
    for (int i = 1; i <= n; i++)
        std::cin >> c[i];
    for (int i = 1; i <= m; i++)
        mat[0][i] = v[i];
    for (int i = m + 1; i <= m + n; i++)
        mat[i][n + m + 1] = c[i - m];
    n = n + m + 1;
    int flow = sap();
    memset(vis, 0, sizeof vis);
    dfs(0);
    for (int i = 1; i <= m; i++)
        if (vis[i])
            std::cout << i << ' ';
    std::cout << '\n';
    for (int i = m + 1; i <= n - 1; i++)
        if (vis[i])
            std::cout << i - m << ' ';
    std::cout << '\n';
    std::cout << sum - flow << '\n';
    return 0;
}

int dfs(int x, int maxf) {
    if (x == n)
        return maxf;
    int ret = 0, delta = 0;
    for (int i = 1; i <= n; i++)
        if (vis[x] == vis[i] + 1 && mat[x][i] > 0) {
            delta = dfs(i, std::min(maxf, mat[x][i]));
            mat[x][i] -= delta;
            mat[i][x] += delta;
            maxf -= delta;
            ret += delta;
            if (vis[0] == n || !maxf)
                return ret;
        }
    if (!(--gap[vis[x]])) {
        vis[0] = n;
        return ret;
    }
    gap[++vis[x]]++;
    return ret;
}

int sap() {
    int ret = 0;
    gap[0] = n + 1;
    while (vis[0] < n)
        ret += dfs(0, 1 << 30);
    return ret;
}

void dfs(int u) {
    vis[u] = 1;
    for (int i = 1; i <= n; i++)
        if (!vis[i] && mat[u][i])
            dfs(i);
}