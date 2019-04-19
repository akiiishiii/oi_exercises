// 1008.cpp
#include <iostream>

int n, m, a[25][25], f[25][25];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> m >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 0, maxx = 0xcfcfcfcf; j <= m; j++) {
            for (int k = 0; k <= j; k++)
                maxx = std::max(maxx, f[i - 1][k] + a[i][j - k]);
            f[i][j] = maxx;
        }
    std::cout << f[n][m] << '\n';
    return 0;
}

/*
f[i, j] = max{f[i - 1, k] + a[i, j - k]} (1 ≤ i ≤ n, 0 ≤ j ≤ m, 0 ≤ k ≤ j)
f[i, 0] = 0
ans = f[n, m]
*/