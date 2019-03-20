// 1751.cpp
#include <iostream>

long long x, xx, y, yy, p, facts[200010];

long long power(long long a, long long b);
long long inv(long long x) { return power(x, p - 2); }
long long C(long long n, long long m);
long long lucas(long long n, long long m);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (std::cin >> x >> y >> xx >> yy >> p) {
        facts[0] = 1;
        long long cnt = std::min(p, std::max(yy + 5, xx + 5));
        for (long long i = 1; i <= cnt; i++)
            facts[i] = (facts[i - 1] * i) % p;
        long long ans = 0;
        for (long long j = y + 1; j <= yy + 1; ++j) {
            ans = (ans + lucas(xx + 1, j) - lucas(x, j)) % p;
        }
        std::cout << ans << '\n';
    }
    return 0;
}

long long power(long long a, long long b) {
    long long ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return ans;
}

long long C(long long n, long long m) {
    if (n < m)
        return 0;
    return facts[n] * inv(facts[m]) % p * inv(facts[n - m]) % p;
}

long long lucas(long long n, long long m) {
    if (m > n)
        return 0;
    if (m == 0)
        return 1;
    return C(n % p, m % p) % p * lucas(n / p, m / p) % p;
}