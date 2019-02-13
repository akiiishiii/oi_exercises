// 1378.cpp
#include <iostream>
#include <cstring>
#include <algorithm>

int main(int argc, char const *argv[]) {
    int n, a[101] = {0}, sum[101] = {0}, f[101][101];
    memset(f, 0x3f, sizeof(f));
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        f[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++)
                f[l][r] = std::min(f[l][r], f[l][k] + f[k + 1][r]);
            f[l][r] += sum[r] - sum[l - 1];
        }
    std::cout << f[1][n] << '\n';
    return 0;
}
