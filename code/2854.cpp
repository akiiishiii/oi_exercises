// 2854.cpp
#include <algorithm>
#include <iostream>

int mk[16], g[102][102], f[32780][16];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, n, t, ans = 0x3f3f3f3f;
    std::cin >> n >> m >> t;
    mk[1] = 1;
    for (int i = 2; i <= m + 1; i++)
        std::cin >> mk[i];
    std::sort(mk + 1, mk + ++m + 1);
    m = std::unique(mk + 1, mk + m + 1) - mk - 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = 0x3f3f3f3f;
    for (int i = 1, x, y, z; i <= t; i++)
        std::cin >> x >> y >> z, g[x][y] = g[y][x] = std::min(z, g[x][y]);
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (g[i][k] != 0x3f3f3f3f && g[k][j] != 0x3f3f3f3f && g[i][j] > g[i][k] + g[k][j])
                    g[i][j] = g[i][k] + g[k][j];
    for (int i = 1; i < (1 << m); i++)
        for (int j = 1; j <= m; j++)
            f[i][j] = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++)
        f[(1 << (i - 1)) + 1][i] = g[1][mk[i]];
    for (int i = 1; i < (1 << m); i++)
        for (int j = 1; j <= m; j++)
            if ((i & (1 << (j - 1))) && f[i][j] != 0x3f3f3f3f)
                for (int k = 1; k <= m; k++)
                    if (g[mk[j]][mk[k]] != 0x3f3f3f3f && !(i & (1 << (k - 1))))
                        f[i | (1 << (k - 1))][k] = std::min(f[i | (1 << (k - 1))][k], f[i][j] + g[mk[j]][mk[k]]);
    for (int j = 2; j <= m; j++)
        ans = std::min(ans, f[(1 << m) - 1][j] + g[mk[j]][1]);
    if (ans < 0x3f3f3f3f)
        std::cout << ans << '\n';
    else
        std::cout << "-1\n";
    return 0;
}