// 1646.cpp
#include<iostream>

long long m, n, x, y, l;

long long exgcd(long long a, long long b, long long &x, long long &y);
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (std::cin >> x >> y >> m >> n >> l) {
        exgcd(n - m, l, x, y);
        long long d = gcd(n - m, l);
        if ((x - y) % d || m == n)
            std::cout << "Impossible\n";
        else
            std::cout << (x % (l / d) + (l / d)) % (l / d) << '\n';
    }
    return 0;
}

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, x, y);
    long long z = x;
    x = y;
    y = z - y * (a / b);
    return d;
}