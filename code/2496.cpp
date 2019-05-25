// 2496.cpp
#include <iostream>

int f[5010][5010], a[5010][5010];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, R, r, c, ans = 0;
    std::cin >> n >> R;
    r = c = R;
    for (int i = 1, x, y, v; i <= n; i++) {
        std::cin >> x >> y >> v;
        a[++x][++y] = v;
        r = std::max(r, x), c = std::max(c, y);
    }
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
    for (int i = R; i <= r; i++)
        for (int j = R; j <= c; j++)
            ans = std::max(ans, f[i][j] - f[i][j - R] - f[i - R][j] +
                                    f[i - R][j - R]);
    std::cout << ans << '\n';
    return 0;
}