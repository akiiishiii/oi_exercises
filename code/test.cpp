#include <iostream>

int f[100005], sum[11][11], t[105], v[105], mn[105];
int n, m, tot = 0;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1, v, t; i <= n; i++)
        std::cin >> t >> v, sum[t][v]++;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            if (sum[i][j]) {
                mn[++tot] = sum[i][j];
                t[tot] = i, v[tot] = j;
            }
    for (int i = 1, k = 1; i <= tot; i++) {
        if (mn[i] * t[i] > m) {
            for (int j = t[i]; j <= m; j++)
                if (f[j - t[i]] + v[i] > f[j])
                    f[j] = f[j - t[i]] + v[i];
            continue;
        }
        while (k <= mn[i]) {
            for (int j = m; j >= t[i] * k; j--)
                f[j] = std::max(f[j], f[j - t[i] * k] + v[i] * k);
            mn[i] = mn[i] - k;
            k *= 2;
        }
        if (mn[i])
            for (int j = m; j >= t[i] * mn[i]; j--)
                f[j] = std::max(f[j], f[j - t[i] * mn[i]] + v[i] * mn[i]);
    }
    std::cout << f[m] << '\n';
    return 0;
}