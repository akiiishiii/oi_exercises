// 1006.cpp
#include <algorithm>
#include <iostream>

struct nmsl {
    int s, e, c;
    bool operator<(nmsl const &n) const { return e < n.e; }
} p[30005];

int n, f[30005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int d = 0xcfcfcfcf;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i].s >> p[i].e >> p[i].c;
        d = std::max(d, p[i].e);
    }
    std::sort(p + 1, p + n + 1);
    for (int i = 1, j = 1; j <= d; j++) {
        f[j] = f[j - 1];
        while (p[i].e == j)
            f[j] = std::max(f[j], f[p[i].s] + p[i].c), i++;
    }
    std::cout << f[d] << '\n';
    return 0;
}