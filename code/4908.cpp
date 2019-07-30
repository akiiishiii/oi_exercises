// 4908.cpp
#include <cstring>
#include <iostream>

int const MAXN = 2e3 + 5;
double const inf = 1e17 + 5;
int n, m, v, e, c[MAXN][2], mp[305][305];
double k[MAXN], dp[MAXN][MAXN][2], ans;

int main() {
    memset(mp, 63, sizeof(mp));
    std::cin >> n >> m >> v >> e;
    for (int i = 1; i <= n; i++)
        std::cin >> c[i][0];
    for (int i = 1; i <= n; i++)
        std::cin >> c[i][1];
    for (int i = 1; i <= n; i++)
        scanf("%lf", &k[i]);
    for (int i = 1; i <= e; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        mp[x][y] = mp[y][x] = std::min(mp[x][y], w);
    }
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                mp[i][j] = std::min(mp[i][j], mp[i][k] + mp[k][j]);
    for (int i = 1; i <= v; i++)
        mp[i][i] = mp[i][0] = mp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j][0] = dp[i][j][1] = inf;
    dp[1][0][0] = dp[1][1][1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i][0][0] = dp[i - 1][0][0] + mp[c[i - 1][0]][c[i][0]];
        for (int j = 1; j <= std::min(i, m); j++) {
            int C1 = c[i - 1][0], C2 = c[i - 1][1], C3 = c[i][0], C4 = c[i][1];
            dp[i][j][0] =
                std::min(dp[i][j][0], std::min(dp[i - 1][j][0] + mp[C1][C3],
                                               dp[i - 1][j][1] +
                                                   mp[C1][C3] * (1 - k[i - 1]) +
                                                   mp[C2][C3] * k[i - 1]));
            dp[i][j][1] = std::min(
                dp[i][j][1],
                std::min(dp[i - 1][j - 1][0] + mp[C1][C3] * (1 - k[i]) +
                             mp[C1][C4] * k[i],
                         dp[i - 1][j - 1][1] + mp[C2][C4] * k[i] * k[i - 1] +
                             mp[C2][C3] * k[i - 1] * (1 - k[i]) +
                             mp[C1][C4] * (1 - k[i - 1]) * k[i] +
                             mp[C1][C3] * (1 - k[i - 1]) * (1 - k[i])));
        }
    }
    ans = inf;
    for (int i = 0; i <= m; i++)
        ans = std::min(ans, std::min(dp[n][i][0], dp[n][i][1]));
    printf("%.2lf", ans);
    return 0;
}