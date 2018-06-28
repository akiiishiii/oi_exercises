// 1273.cpp
#include <iostream>
#include <cstring>

int main(int argc, const char * argv[]) {
    int x, y, n, m, f[1001][1001];
    std::cin >> n >> m;
    memset(f, 1, sizeof(f));
    for (int i = 0; i < m; i++) {
        std::cin >> x >> y;
        f[x][y] = 0;
    }
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            if (f[i][j])
                f[i][j] = (f[i][j - 1] + f[i - 1][j]) % 100003;
    std::cout << f[n][n] << std::endl;
    return 0;
}
