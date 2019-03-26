// 4696.cpp
#include <iostream>

int const Mod = 1e9 + 7, Maxn = 105;
int n, m, k, u[Maxn], r[Maxn], c[Maxn][Maxn], inv[Maxn], f[Maxn], ans;

int power(int a, int b);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m >> k;
    k = n - 1 - k;
    for (int i = 1; i <= m; i++)
        std::cin >> u[i];
    for (int i = 1; i <= m; i++)
        std::cin >> r[i];
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % Mod;
    }
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = 1ll * inv[Mod % i] * (Mod - Mod / i) % Mod;
    for (int i = 0; i <= k; i++) {
        int ret = c[k][i];
        for (int j = 1; j <= m; j++)
            ret = 1ll * ret * c[k - i][r[j] - 1] % Mod;
        if (i & 1)
            ret = Mod - ret;
        (ans += ret) %= Mod;
    }
    for (int i = 1; i <= m; i++) {
        int ret = 0;
        for (int j = 1; j <= n; j++) {
            f[j] = 0;
            for (int k = 1; k <= j; k++)
                f[j] = (f[j] +
                        1ll * power(k, n - r[i]) * power(j - k, r[i] - 1)) %
                       Mod;
        }
        if (u[i] <= n) {
            ans = 1ll * ans * f[u[i]] % Mod;
            continue;
        }
        for (int j = 1; j <= n; j++) {
            int s = f[j];
            for (int k = 0; k <= n; k++)
                if (k != j)
                    s = 1ll * s * (u[i] - k) % Mod *
                        (j > k ? inv[j - k] : Mod - inv[k - j]) % Mod;
            (ret += s) %= Mod;
        }
        ans = 1ll * ans * ret % Mod;
    }
    std::cout << 1ll * ans * c[n - 1][k] % Mod << '\n';
    return 0;
}

int power(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1)
            ret = 1ll * ret * a % Mod;
        a = 1ll * a * a % Mod;
        b >>= 1;
    }
    return ret;
}