// 1271.cpp
#include <iostream>
#include <cstring>

template <typename T>
inline T min(const T &a, const T &b) { return a < b ? a : b;}

int main(int argc, const char * argv[]) {
    int n, mat[1001][1001], f[1001][1001];
    memset(mat, 0, sizeof(mat));
    memset(f, 0, sizeof(f));
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            std::cin >> mat[i][j];
            f[i][j] = mat[i][j];
        }
    for (int i = 2; i <= n; i++) {
        f[i][1] = f[i - 1][1] + mat[i][1];
        f[1][i] = f[1][i - 1] + mat[1][i];
    }
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            f[i][j] = min(f[i][j - 1], f[i - 1][j]) + mat[i][j];
    std::cout << f[n][n] << std::endl;
    return 0;
}