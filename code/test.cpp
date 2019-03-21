#include <iostream>

long long const Mod = 10007;

long long power(long long a, long long b);
inline long long inv(long long x) { return power(x, Mod - 2); }
long long C(long long n, long long m);
long long lucas(long long n, long long m);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long T, n, m;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        std::cout << lucas(n, m) << '\n';
    }
    return 0;
}

long long power(long long a, long long b) {
    long long ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % Mod;
        b >>= 1;
        a = (a * a) % Mod;
    }
    return ans;
}

long long C(long long n, long long m) {
    if (n < m)
        return 0;
    long long up = 1, down = 1;
    for (long long i = n - m + 1; i <= n; ++i)
        up = up * i % Mod;
    for (long long i = 1; i <= m; ++i)
        down = down * i % Mod;
    return up * inv(down) % Mod;
}

long long lucas(long long n, long long m) {
    if (m > n)
        return 0;
    if (m == 0)
        return 1;
    return C(n % Mod, m % Mod) % Mod * lucas(n / Mod, m / Mod) % Mod;
}