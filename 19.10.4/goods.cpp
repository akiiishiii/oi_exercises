// goods.cpp
#include <fstream>
#include <iostream>
#include <queue>

//#define debug

#ifndef debug

std::ifstream in("goods.in");
std::ofstream out("goods.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 100005;
int f[Maxn], c[Maxn], d[Maxn], a[Maxn], w[Maxn], af[Maxn], n;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n;
    for (int i = 1; i <= n; i++)
        in >> f[i] >> c[i] >> d[i] >> a[i];
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        af[i] = a[f[i]];
        w[i] = d[f[i]] - c[i];
        ans += (long long)af[i] * w[i];
    }
    out << ans << '\n';
    return 0;
}