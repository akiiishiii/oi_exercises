// 1192.cpp
#include <iostream>

int f[60000][11], pow3[11], d[60000][11], g[15][15];
int n, m;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    pow3[0] = 1;
    for (int i = 1; i < 11; i++)
        pow3[i] = pow3[i - 1] * 3;
    for (int i = 0; i < pow3[10]; i++) {
        int tmp = i;
        for (int j = 0; j < 10; j++) {
            d[i][j] = tmp % 3;
            tmp /= 3;
        }
    }
    while (std::cin >> n >> m) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = 100000000;
        for (int i = 0; i < pow3[n]; i++)
            for (int j = 0; j < n; j++)
                f[i][j] = 100000000;
        while (m--) {
            int a, b, c;
            std::cin >> a >> b >> c;
            g[a - 1][b - 1] = g[b - 1][a - 1] = std::min(c, g[a - 1][b - 1]);
        }
        for (int i = 0; i < n; i++)
            f[pow3[i]][i] = 0;
        int ans = 100000000;
        for (int j = 0; j < pow3[n]; j++) {
            bool flag = true;
            for (int i = 0; i < n; i++) {
                if (!d[j][i])
                    flag = false;
                if (f[j][i] != 100000000)
                    for (int k = 0; k < n; k++)
                        if (g[i][k] != 100000000 && d[j][k] != 2)
                            f[j + pow3[k]][k] =
                                std::min(f[j][i] + g[i][k], f[j + pow3[k]][k]);
            }
            if (flag)
                for (int i = 0; i < n; i++)
                    ans = std::min(ans, f[j][i]);
        }
        if (ans >= 100000000)
            std::cout << "-1\n";
        else
            std::cout << ans << '\n';
    }
    return 0;
}