// 1615.cpp
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

int arr[50001] = {0}, maxf[50001][16], minf[50001][16];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k;
    std::cin >> n >> k;
    memset(maxf, 0, sizeof maxf);
    memset(minf, 0, sizeof minf);
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
        minf[i][0] = maxf[i][0] = arr[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            maxf[i][j] = std::max(maxf[i][j - 1], maxf[i + (1 << (j - 1))][j - 1]);
            minf[i][j] = std::min(minf[i][j - 1], minf[i + (1 << (j - 1))][j - 1]);
        }
    for (int i = 1, l, r, x; i <= k; i++) {
        std::cin >> l >> r;
        x = int(log(r - l + 1) / log(2));
        std::cout << std::max(maxf[l][x], maxf[r - (1 << x) + 1][x]) - std::min(minf[l][x], minf[r - (1 << x) + 1][x]) << '\n';
    }
    return 0;
}
