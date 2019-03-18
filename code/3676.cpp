// 3676.cpp
#include <iostream>
#include <map>
#include <cmath>

long long p, a, b, x1, t;
std::map<long long, long long> ma;

long long power(long long x, long long y);
long long baby_step_giant_step(long long a, long long b);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> p >> a >> b >> x1 >> t;
        if (x1 == t) {
            std::cout << "1\n";
            continue;
        } else if (!a) {
            if (b == t)
                std::cout << "2\n";
            else
                std::cout << "-1\n";
            continue;
        } else if (a == 1) {
            if (!b)
                std::cout << "-1\n";
            else {
                long long m = t - x1, inv = power(b, p - 2);
                m = (m % p + p) % p;
                std::cout <<  m * inv % p + 1ll << '\n';
            }
            continue;
        } else {
            x1 %= p, a %= p, b %= p, t %= p;
            long long tmp = b * power(a - 1, p - 2) % p, m = (t + tmp) % p, n = (x1 + tmp) % p, inv = power(n, p - 2);
            std::cout << baby_step_giant_step(a, m % p * inv % p) + 1ll << '\n';
        }
    }
    return 0;
}

long long power(long long x, long long y) {
    long long ret = 1;
    while (y) {
        if (y & 1)
            ret = ret * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ret;
}

long long baby_step_giant_step(long long a, long long b) {
    a %= p;
    if (!a)
        return -2;
    ma.clear();
    long long m = ceil(sqrt(p)), tmp = b % p;
    for (long long i = 1; i <= m; i++) {
        tmp = tmp * a % p;
        ma[tmp] = i;
    }
    long long t = power(a, m), d = t, ans;
    for (long long i = 1; i <= m; i++) {
        ans = ma[d];
        if (ans) {
            long long re = i * m % p - ans % p;
            return (re % p + p) % p;
        }
        d = d * t % p;
    }
    return -2;
}