// 1289.cpp
#include <iostream>

int f[1001][1001];

int main(int argc, const char * argv[]) {
    int m, n;
    std::cin >> m >> n;
    for (int i = 1; i <= m; i++)
        f[i][1] = 1;
    for (int i = 1; i <= n; i++)
        f[1][i] = 1;
    for (int i = 2; i <= m; i++)
        for (int j = 2; j <= n; j++)
            f[i][j] = f[i][j - 1] + f[i - 1][j];
    std::cout << f[m][n] << std::endl;
    return 0;
}