// 1369.cpp
#include <iostream>
#include <cstring>
#include <algorithm>

int main(int argc, char const *argv[]) {
    int f[201], v[11][31], w[11][31], c[11] = {0}, m, n, tot;
    memset(f, 0xCF, sizeof(f));
    f[0] = 0;
    memset(v, 0, sizeof(v));
    memset(w, 0, sizeof(w));
    std::cin >> m >> tot >> n;
    for (int i = 1; i <= tot; i++) {
        int vi, wi, ci;
        std::cin >> vi >> wi >> ci;
        v[ci][++c[ci]] = vi;
        w[ci][c[ci]] = wi;
    }
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 1; k <= c[i]; k++)
                if (j >= v[i][k])
                    f[j] = std::max(f[j], f[j - v[i][k]] + w[i][k]);
    std::cout << f[m] << '\n';
    return 0;
}
