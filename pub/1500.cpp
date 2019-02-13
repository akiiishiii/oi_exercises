// 1500.cpp
#include <cstring>
#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[]) {
    int n, f[101][101], g[101][101], maxx = 0;
    char c[101][101];
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    memset(c, '\0', sizeof(c));
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i + 1; j++)
            std::cin >> c[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i + 1; j++) {
            f[i][j] = std::min(f[i - 1][j - 1], std::min(f[i - 1][j], f[i - 1][j + 1])) + 1;
            g[i][j] = std::min(g[i + 1][j - 1], std::min(g[i + 1][j], g[i + 1][j + 1])) + 1;
            maxx = std::max(maxx, std::max(f[i][j], g[i][j]));
        }
    std::cout << maxx * maxx << '\n';
    return 0;
}
