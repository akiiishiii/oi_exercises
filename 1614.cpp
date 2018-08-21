// 1614.cpp
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

int arr[1000001] = {0}, f[1000001][21];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k;
    std::cin >> n >> k;
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
        f[i][0] = arr[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = std::max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    for (int i = 1, l, r, x; i <= k; i++) {
        std::cin >> l >> r;
        x = int(log(r - l + 1) / log(2));
        std::cout << std::max(f[l][x], f[r - (1 << x) + 1][x]) << '\n';
    }
    return 0;
}
