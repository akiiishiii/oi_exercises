// 1365.cpp
#include <iostream>
#include <cstring>
#include <algorithm>

int main(int argc, char const *argv[]) {
    int f[201], v[31] = {0}, w[31] = {0}, m, n;
    memset(f, 0xCF, sizeof(f));
    f[0] = 0;
    std::cin >> m >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = std::max(f[j], f[j - v[i]] + w[i]);
    int ans = 0;
    for (int j = 0; j <= m; j++)
        ans = std::max(ans, f[j]);
    std::cout << "max=" << ans << '\n';
    return 0;
}
