#include <algorithm>
#include <iostream>

int const Maxn = 100005;
long long const Mod = 1e9 + 7;
long long n, m, a[Maxn], x[Maxn], y[Maxn];

long long power(long long a, long long b);
long long lagrange(long long k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        for (int i = 1; i <= m; i++)
            std::cin >> a[i];
        std::sort(a + 1, a + 1 + m);
        for (int i = m; i >= 1; i--) {
            if (a[i] == n)
                n--, m--;
            else
                break;
        }
        for (int i = 1; i <= m + 3; i++) {
            x[i] = i, y[i] = power(i, m + 1);
            y[i] += y[i - 1], y[i] %= Mod;
        }
        long long ans = 0;
        for (int i = 0; i <= m; i++) {
            ans += lagrange(n - a[i]);
            ans %= Mod;
            for (int j = i + 1; j <= m; j++)
                ans -= power(a[j] - a[i], m + 1), ans += Mod, ans %= Mod;
        }
        std::cout << ans % Mod << '\n';
    }
    return 0;
}

long long power(long long a, long long b) {
    long long p = 1;
    while (b) {
        if (b & 1)
            p *= a, p %= Mod;
        a *= a, a %= Mod;
        b >>= 1;
    }
    return p;
}

long long lagrange(long long k) {
    long long p = 0;
    k %= Mod;
    for (int i = 1; i <= m + 3; i++) {
        long long pos = 1;
        for (int j = 1; j <= m + 3; j++) {
            if (i == j)
                continue;
            long long now = (x[i] - x[j] + Mod) % Mod;
            pos = pos * (k - x[j] + Mod) % Mod * power(now, Mod - 2) % Mod;
        }
        p = p + (pos * y[i] % Mod), p %= Mod;
    }
    return p;
}