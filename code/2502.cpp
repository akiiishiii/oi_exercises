// 2502.cpp
#include <iostream>

long long exgcd(long long a, long long b, long long &x, long long &y);
long long power(long long n, long long k, long long p);
long long inv(long long n, long long p);
long long C(long long n, long long m, long long p, long long pi, long long pk);
long long mul(long long n, long long pi, long long pk);

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long m, n, p, T;
    std::cin >> T;
    while (T--) {
        long long ans = 0ll;
        std::cin >> n >> m >> p;
        for (long long x = p, i = 2; i <= p; i++)
            if (x % i == 0) {
                long long pk = 1ll;
                while (x % i == 0)
                    pk *= i, x /= i;
                ans = (ans + C(n, m, p, i, pk)) % p;
            }
        std::cout << ans << "\n";
    }
    return 0;
}

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, x, y);
    long long z = x;
    x = y;
    y = z - y * (a / b);
    return d;
}

long long power(long long n, long long k, long long p) {
    long long ans = 1ll;
    while (k) {
        if (k & 1ll)
            ans = (ans * n) % p;
        n = (n * n) % p;
        k >>= 1ll;
    }
    return ans;
}

long long C(long long n, long long m, long long p, long long pi, long long pk) {
    if (m > n)
        return 0ll;
    long long a = mul(n, pi, pk), b = mul(m, pi, pk), c = mul(n - m, pi, pk);
    long long k = 0ll, ans;
    for (long long i = n; i; i /= pi)
        k += i / pi;
    for (long long i = m; i; i /= pi)
        k -= i / pi;
    for (long long i = n - m; i; i /= pi)
        k -= i / pi;
    ans = a * inv(b, pk) % pk * inv(c, pk) % pk * power(pi, k, pk) % pk;
    return ans * (p / pk) % p * inv(p / pk, pk) % p;
}

long long inv(long long n, long long p) {
    if (!n)
        return 0ll;
    long long a = n, b = p, x = 0ll, y = 0ll;
    exgcd(a, b, x, y);
    x = ((x % b) + b) % b;
    if (!x)
        x += b;
    return x;
}

long long mul(long long n, long long pi, long long pk) {
    if (!n)
        return 1ll;
    long long ans = 1ll;
    if (n / pk) {
        for (long long i = 2; i <= pk; i++)
            if (i % pi)
                ans = ans * i % pk;
        ans = power(ans, n / pk, pk);
    }
    for (long long i = 2; i <= n % pk; i++)
        if (i % pi)
            ans = ans * i % pk;
    return ans * mul(n / pi, pi, pk) % pk;
}