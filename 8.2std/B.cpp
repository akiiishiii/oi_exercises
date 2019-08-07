// A.cpp
#include <algorithm>
#include <iostream>
#include <vector>

int const Maxn = 2005, Mod = 998244353;
int f[Maxn][Maxn], s[Maxn], g[Maxn];
int C[Maxn][Maxn];
std::vector<int> T[Maxn];

void dfs(int u, int p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
    }
    int n;
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1, 0);
    std::cout << f[1][1] << '\n';
    return 0;
}

void dfs(int u, int p) {
    s[u] = 1;
    f[u][1] = 1;
    for (int i = 0; i < T[u].size(); i++) {
        int v = T[u][i];
        if (v == p)
            continue;
        dfs(v, u);
        std::fill(g, g + s[u] + s[v] + 1, 0);
        for (int k = 1; k <= s[u]; k++)
            for (int d = 0; d <= s[v]; d++)
                g[k + d] = (g[k + d] +
                            1ll * C[k + d - 1][d] * f[u][k] % Mod * f[v][d]) %
                           Mod;
        s[u] += s[v];
        for (int k = 1; k <= s[u]; k++)
            f[u][k] = g[k];
    }
    for (int i = s[u]; i >= 0; i--)
        f[u][i] = (f[u][i] + f[u][i + 1]) % Mod;
}