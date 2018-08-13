// 1358.cpp
#include <iostream>
#include <cstring>
#include <algorithm>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t, r, c, mat[105][105], f[105][105];
    std::cin >> t;
    for (int times = 0; times < t; times++) {
        std::cin >> r >> c;
        memset(mat, 0, sizeof(mat));
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                std::cin >> mat[i][j];
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                f[i][j] = std::max(f[i - 1][j], f[i][j - 1]) + mat[i][j];
        std::cout << f[r][c] << '\n';
    }
    return 0;
}
