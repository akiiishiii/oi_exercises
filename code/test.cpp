#include <iostream>

int n, m, cnt = 0;
int t[100010], v[100010], a[100010], f[100010], sum[16][16];

std::nullptr_t nmsl;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nmsl);
    std::cin >> n >> m;
    for (int i = 1, x, y; i <= n; i++)
        std::cin >> x >> y, sum[x][y]++;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            if (sum[i][j]) {
                a[++cnt] = sum[i][j];
                t[cnt] = i, v[cnt] = j;
            }
    for (int i = 1, k = 1; i <= cnt; i++) {
        if (a[i] * t[i] > m) {
            for (int j = t[i]; j <= m; j++)
                f[j] = std::max(f[j], f[j - t[i]] + v[i]);
            continue;
        }
        while (k <= a[i]) {
            for (int j = m; j >= k * t[i]; j--)
                f[j] = std::max(f[j], f[j - k * t[i]] + k * v[i]);
            a[i] -= k;
            k <<= 1;
        }
        if (a[i])
            for (int j = m; j >= a[i] * t[i]; j--)
                f[j] = std::max(f[j], f[j - a[i] * t[i]] + a[i] * v[i]);
    }
    std::cout << f[m] << '\n';
    return 0;
}