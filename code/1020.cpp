// 1020.cpp
#include <iostream>

int n, k, f[10005][1005];

int main(int argc, const char *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
        f[i][1] = f[i][0] = 1;
    for (int x = 2; x <= k; x++)
        f[1][x] = f[0][x] = 0;
    for (int i = 2; i <= n; i++)
        for (int x = 2; x <= k; x++)
            if (i > x)
                f[i][x] =
                    ((f[i - 1][x - 1] % 10003) + (f[i - x][x] % 10003) % 10003);
            else
                f[i][x] = f[i - 1][x - 1];
    std::cout << (f[n][k] % 10003) << std::endl;
    return 0;
}