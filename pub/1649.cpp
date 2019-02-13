// 1649.cpp
#include <iostream>

long long M;
long long m[11] = {0}, a[11] = {0};

long long exgcd(long long a, long long b, long long &x, long long &y);
long long intChina(int r);

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> m[i] >> a[i];
    std::cout << intChina(n) << '\n';
    return 0;
}

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1, y = 0; return a; }
    long long d = exgcd(b, a%b, x, y);
    long long z = x; x = y; y = z - y * (a / b);
    return d;
}

long long intChina(int r) {
    long long Mi, x0, y0, ans = 0;
    M = 1;
    for (int i = 1; i <= r; i++)
        M *= m[i];
    for (int i = 1; i <= r; i++) {
        Mi = M / m[i];
        exgcd(Mi, m[i], x0, y0);
        ans = (ans + Mi * x0 * a[i]) % M;
    }
    return (ans + M) % M;
}
