// 3213.cpp
#include <iostream>
#include <iomanip>
#include <cstring>

double const eps = 1e-9;
int n, m, d[105];
long double ans, g[105][105], a[105][105];

void det(int t);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    n++;
    for (int i = 1, x; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            std::cin >> x;
            if (x == 1)
                d[i]++, g[i][j] = -1.0;
        }
    for (int i = 1; i <= n; i++)
        g[i][i] = d[i];
    memcpy(a, g, sizeof(a));
    det(n - 1);
    std::cout << std::fixed << std::setprecision(0) << ans << '\n';
    for (int i = 1, x, y; i <= m; i++) {
        std::cin >> x >> y;
        a[x][x]--, a[y][y]--;
        a[x][y] = a[y][x] = 0;
        memcpy(g, a, sizeof(g));
        det(n - 1);
        std::cout << std::fixed << std::setprecision(0) << ans << '\n';
    }
    return 0;
}

void det(int t) {
    ans = 1.0;
    for (int i = 1, j; i <= t; i++) {
        for (j = i; j <= t && g[j][i] < eps; j++);
        if (j == n) {
            ans = 0;
            break;
        }
        ans *= g[i][i];
        for (int k = 1; k <= t; k++)
            std::swap(g[i][k], g[j][k]);
        for (int k = i + 1; k <= t; k++)
            for (int l = i + 1; l <= t; l++)
                g[k][l] -= g[k][i] * g[i][l] / g[i][i];
    }
}