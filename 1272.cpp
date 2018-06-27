// 1272.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n, f[1001][1001];
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        f[1][i] = f[i][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            f[i][j] = (f[i][j - 1] + f[i - 1][j]) % 100003;
    std::cout << f[n][n] << std::endl;
    return 0;
}