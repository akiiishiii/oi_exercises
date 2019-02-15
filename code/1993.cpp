// 1993.cpp
#include <cstring>
#include <iostream>
#include <cmath>

int const Maxn = 1005;
int n;
int f[Maxn][Maxn], val[Maxn];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> val[i];
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            int k = std::max(i, j) + 1;
            f[i][k] = std::min(f[i][k], f[i][j] + (j ? abs(val[j] - val[k]) : 0));
            f[k][j] = std::min(f[k][j], f[i][j] + (i ? abs(val[i] - val[k]) : 0));
        }
    int ans = 0x7fffffff;
    for (int i = 1; i <= n; i++)
        ans = std::min(ans, std::min(f[i][n], f[n][i]) + abs(val[n] - val[i]));
    std::cout << ans << '\n';
    return 0;
}