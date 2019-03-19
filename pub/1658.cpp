// 1658.cpp
#include <iostream>

long long fac[100010] = {0};

long long exgcd(long long a, long long b, long long &x, long long &y);
long long inv(long long a, long long mod);
long long C(int n, int m, int mod);
long long lucas(long long n, long long m, long long mod) { return (m ? C(n % mod, m % mod, mod) * lucas(n / mod, m / mod, mod) % mod : 1ll); }

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long T, a, b, mod;
    fac[0] = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> a >> b >> mod;
        for (int i = 1; i <= mod; i++)
            fac[i] = (fac[i - 1] * i) % mod;
        std::cout << lucas(a + b, a, mod) << '\n';
    }
    return 0;
}

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

long long inv(long long a, long long mod) {
    long long x, y;
    long long d = exgcd(a, mod, x, y);
    if (d == 1)
        return (x % mod + mod) % mod;
    return -1;
}

long long C(int n, int m, int mod) {
    if (m > n)
        return 0;
    long long ret = fac[n];
    ret *= inv((fac[m] * fac[n - m]) % mod, mod);
    return ret % mod;
}