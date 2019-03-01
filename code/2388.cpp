// 2388.cpp
#include <iomanip>
#include <iostream>

int const Maxn = 105;
double const eps = 1e-9;
int n, m, x, y, d[Maxn];
double g[Maxn][Maxn], ans = 1.0;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
        std::cin >> x >> y, d[x]++, d[y]++, g[x][y] = g[y][x] = -1;
    for (int i = 1; i <= n; i++)
        g[i][i] = d[i];
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j < n && g[j][i] < eps)
            j++;
        if (j == n) {
            ans = 0;
            break;
        }
        ans *= g[i][i];
        for (int k = 1; k < n; k++)
            std::swap(g[i][k], g[j][k]);
        for (j = i + 1; j < n; j++)
            for (int k = i + 1; k < n; k++)
                g[j][k] -= g[j][i] * g[i][k] / g[i][i];
    }
    std::cout << std::fixed << std::setprecision(0) << ans << '\n';
    return 0;
}