// 1177.cpp
#include <iostream>
#include <cstring>

double dp[1100][1100], p[1100][1100];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, num, ans = 0;
    std::cin >> n;
    num = 1 << n;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < num; i++)
        dp[0][i] = 1;
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            std::cin >> p[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < num; j++)
            for (int k = 0; k < num; k++)
                if ((j >> (i - 1)) == ((k >> (i - 1)) ^ 1))
                    dp[i][j] += dp[i - 1][j] * (dp[i - 1][k] * (p[j][k] / 100));
    for (int i = 1; i < num; i++)
        if (dp[n][i] > dp[n][ans])
            ans = i;
    std::cout << ans + 1 << '\n';
    return 0;
}
