// 1724.cpp
#include <algorithm>
#include <cstring>
#include <iostream>

int const U = 100010;
long long b[U], c[U], f[U];
long long n, m, t;

long long calc(long long a[U], int n);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m >> t;
    for (int i = 1, x, y; i <= t; i++) {
        std::cin >> x >> y;
        b[x]++, c[y]++;
    }
    for (int i = 1; i <= n; i++)
        b[0] += b[i];
    for (int i = 1; i <= m; i++)
        c[0] += c[i];
    if (!(b[0] % n || c[0] % m))
        std::cout << "both " << calc(b, n) + calc(c, m) << '\n';
    else if (!(b[0] % n))
        std::cout << "row " << calc(b, n) << '\n';
    else if (!(c[0] % m))
        std::cout << "column " << calc(c, m) << '\n';
    else
        std::cout << "impossible\n";
    return 0;
}

long long calc(long long a[U], int n) {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        a[i] -= a[0] / n;
        f[i] = f[i - 1] + a[i];
    }
    std::sort(f + 1, f + n + 1);
    for (int i = 1; i <= n; i++)
        ans += llabs(f[i] - f[(n + 1) >> 1]);
    return ans;
}