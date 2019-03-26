// 1710.cpp
#include <iostream>

int const Maxn = 505;
int f[Maxn << 1][Maxn], x, n, mod, ans, m;

int inv(int a, int b = mod - 2);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> x >> n >> mod;
    f[0][0] = 1;
    m = 2 * n + 1;
    for (int i = 1; i <= m; i++)
        for (int j = f[i][0] = 1; j <= n; j++)
            f[i][j] = (f[i - 1][j] + (long long)i * f[i - 1][j - 1]) % mod;
    for (int i = 1; i <= m; i++) {
        int a = f[i][n], b = 1;
        for (int j = 1; j <= m; j++)
            if (i != j)
                a = (long long)a * (x - j) % mod, b = (long long)b * (i - j) % mod;
        a = (long long)a * inv(b) % mod;
        ans = (ans + a) % mod;
    }
    for (int i = 1; i <= n; i++)
        ans = (long long)ans * i % mod;
    std::cout << (ans + mod) % mod;
    return 0;
}

int inv(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1)
            ret = (long long)ret * a % mod;
        a = (long long)a * a % mod;
        b >>= 1;
    }
    return ret;
}