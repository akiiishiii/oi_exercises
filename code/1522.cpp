// 1522.cpp
#include <iostream>

long long const P = 1234567891, Maxn = 157;
long long a, n, d, m, k;
long long s1[Maxn], s2[Maxn];
long long g[Maxn], f[Maxn], inv[Maxn << 1];

long long power(long long a, long long b);
long long lagrange(long long *a, int n, long long pos);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> k >> a >> n >> d;
        for (int i = 1; i <= k + 3; i++)
            g[i] = power(i, k);
        for (int i = 2; i <= k + 3; i++)
            (g[i] += g[i - 1]) %= P;
        for (int i = 2; i <= k + 3; i++)
            (g[i] += g[i - 1]) %= P;
        f[0] = lagrange(g, k + 3, a);
        for (int i = 1; i <= k + 5; i++)
            f[i] = lagrange(g, k + 3, (i * d + a) % P), (f[i] += f[i - 1]) %= P;
        std::cout << (lagrange(f, k + 5, n) + P) % P << '\n';
    }
    return 0;
}

long long power(long long a, long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            (ret *= a) %= P;
        (a *= a) %= P;
        b >>= 1;
    }
    return ret;
}

long long lagrange(long long *a, int n, long long pos) {
    if (pos <= n)
        return a[pos];
    long long ret = 0;
    for (int i = 1; i <= n; i++) {
        long long s1 = 1, s2 = 1;
        for (int j = 1; j <= n; j++)
            if (i != j) {
                (s1 *= (pos - j)) %= P;
                (s2 *= (i - j)) %= P;
            }
        (ret += a[i] * s1 % P * power(s2, P - 2)) %= P;
    }
    return ret;
}