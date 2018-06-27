// 1270.cpp
#include <iostream>
#include <cstring>

int main(int argc, const char * argv[]) {
    int n, f[1001][1001];
    memset(f, 1, sizeof(f));
    std::cin >> n;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            f[i][j] = (f[i][j - 1] % 100003 + f[i - 1][j] % 100003) % 100003;
    std::cout << f[n][n] << std::endl;
    return 0;
}