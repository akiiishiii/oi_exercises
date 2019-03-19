// 2592.cpp
#include <iostream>

long long power(long long n, long long k, long long p);
long long C(long long n, long long m, long long p);
long long lucas(long long n, long long m, long long p) { return (m ? C(n % p, m % p, p) * lucas(n / p, m / p, p) : 1); }

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long m, n, p, T;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m >> p;
        std::cout << lucas(n, m, p) << "\n";
    }
    return 0;
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

long long C(long long n, long long m, long long p) {
    if (!m)
        return 1ll;
    if (m > n - m)
        m = n - m;
    long long up = 1ll, down = 1ll;
    for (int i = 1; i <= m; i++) {
        up = (up * (n - i + 1ll)) % p;
        down = (down * i) % p;
    }
    return up * power(down, p - 2ll, p) % p;
}