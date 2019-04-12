// 1005.cpp
#include <cstring>
#include <iostream>

int const Mod = 100000000;

int n, f[155][155][155];
char a[155], b[155], c[155];
int g1[155], g2[155], g3[155], g[155];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], g1[i] = g[a[i] - 'a'], g[a[i] - 'a'] = i;
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= n; i++)
        std::cin >> b[i], g2[i] = g[b[i] - 'a'], g[b[i] - 'a'] = i;
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= n; i++)
        std::cin >> c[i], g3[i] = g[c[i] - 'a'], g[c[i] - 'a'] = i;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                f[i][j][k] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++) {
                if (a[i] == b[j] && b[j] == c[k]) {
                    f[i][j][k] = f[i - 1][j - 1][k - 1] * 2;
                    if (g1[i] && g2[j] && g3[k])
                        f[i][j][k] -= f[g1[i] - 1][g2[j] - 1][g3[k] - 1];
                } else {
                    f[i][j][k] =
                        f[i - 1][j][k] + f[i][j - 1][k] + f[i][j][k - 1];
                    f[i][j][k] -= f[i - 1][j - 1][k] + f[i][j - 1][k - 1] +
                                  f[i - 1][j][k - 1];
                    f[i][j][k] += f[i - 1][j - 1][k - 1];
                }
                f[i][j][k] = (f[i][j][k] % Mod + Mod) % Mod;
            }
    std::cout << (f[n][n][n] - 1) % Mod << '\n';
    return 0;
}