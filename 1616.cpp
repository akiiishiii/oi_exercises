// 1616.cpp
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

int arr[100002] = {0}, num[100002] = {0}, sum[100002] = {0}, f[100002][17];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k;
    std::cin >> n >> k;
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
        if (arr[i] == arr[i - 1] && i != 1)
            num[i] = num[i - 1]++;
        else
            num[i] = 1;
        f[i][0] = num[i];
    }
    for (int i = n; i >= 1; i--)
        if (num[i] == num[i + 1] && i != n)
            sum[i] = sum[i + 1];
        else
            sum[i] = num[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = std::max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    for (int i = 1, l, r, x; i <= k; i++) {
        std::cin >> l >> r;
        x = int(log((r - num[r]) - (l + sum[l] - num[l] + 1) + 1) / log(2));
        std::cout << std::max(std::max(sum[l] - num[l] + 1, num[r]), std::max(f[l + sum[l] - num[l] + 1][x], f[(r - num[r]) - (1 << x) + 1][x])) << '\n';
    }
    return 0;
}
