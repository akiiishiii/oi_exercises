// 1308.cpp
#include <cstring>
#include <iostream>

int f[1 << 20][20];
int hamilton(int n, int weight[20][20]) {
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for (int i = 1; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    if (i >> k & 1)
                        f[i][j] =
                            std::min(f[i][j], f[i ^ 1 << j][k] + weight[k][j]);
    return f[(1 << n) - 1][n - 1];
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, a[20][20];
    std::cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> a[i][j];
    std::cout << hamilton(n, a) << '\n';
    return 0;
}