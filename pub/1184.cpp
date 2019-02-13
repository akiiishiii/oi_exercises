// 1184.cpp
#include <iostream>
#include <cstring>

int main(int argc, const char * argv[]) {
    int m, n, f[32][31];
    memset(f, 0, sizeof f);
    f[1][1] = 1;
    std::cin >> n >> m;
    for (int i = 2; i <= m + 1; i++)
        for (int j = 1; j <= n; j++)
            if (j == 1)
                f[i][j] = f[i - 1][n] + f[i - 1][2];
            else if (j == n)
                f[i][j] = f[i - 1][n - 1] + f[i - 1][1];
            else
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1];
    std::cout << f[m + 1][1] << std::endl;
    return 0;
}