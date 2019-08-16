// 1032.cpp
#include <iostream>

int n;
int cost[1505], f[1505][3], a[1505][1505];
bool vis[1505];

void dp(int t);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int k = 1, i, m; k <= n; k++) {
        std::cin >> i >> cost[i] >> m;
        for (int j = 1, t; j <= m; j++) {
            std::cin >> t;
            a[i][t] = a[t][i] = 1;
        }
    }
    dp(1);
    std::cout << std::min(f[1][1], f[1][2]) << '\n';
    return 0;
}

void dp(int t) {
    if (vis[t])
        return;
    vis[t] = true;
    int d = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
        if (a[t][i] && !vis[i]) {
            dp(i);
            f[t][0] += std::min(f[i][2], f[i][1]);
            f[t][1] += std::min(f[i][2], f[i][1]);
            d = std::min(d, f[i][2] - std::min(f[i][2], f[i][1]));
            f[t][2] += std::min(f[i][2], std::min(f[i][1], f[i][0]));
        }
    f[t][1] += d;
    f[t][2] += cost[t];
}