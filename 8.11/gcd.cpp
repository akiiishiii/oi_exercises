// gcd.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("gcd.in");
std::ofstream out("gcd.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 1000010, Maxm = 80000;
long long a[Maxn], p[Maxm], phi[Maxn], t;
long long ans[Maxn];
bool b[Maxn];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    long long tot, n = 0;
    in >> tot;
    for (int i = 1; i <= tot; i++) {
        std::cin >> a[i];
        n = std::max(n, a[i]);
    }
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!b[i])
            phi[i] = i - 1, p[++t] = i;
        for (int j = 1; j <= t && i * p[j] <= n; j++) {
            b[i * p[j]] = true;
            if (i % p[j] == 0) {
                phi[i * p[j]] = phi[i] * p[j];
                break;
            } else
                phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= n / i; j++)
            ans[i * j] += phi[i] * j;
    for (int i = 2; i <= n; i++)
        ans[i] += ans[i - 1];
    for (int i = 1; i <= tot; i++)
        out << ans[a[i]] << '\n';
    return 0;
}