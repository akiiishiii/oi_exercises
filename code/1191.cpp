// 1191.cpp
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>

double f[1005][1005];
std::pair<double, double> a[1005];

inline double dis(std::pair<double, double> const &a,
                  std::pair<double, double> const &b) {
    return sqrt((a.first - b.first) * (a.first - b.first) +
                (a.second - b.second) * (a.second - b.second));
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i].first >> a[i].second;
    std::sort(a + 1, a + n + 1);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            f[i][j] = 1e100;
    f[2][1] = dis(a[2], a[1]);
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i - 2; j++)
            f[i][j] = f[i - 1][j] + dis(a[i - 1], a[i]);
        for (int j = 1; j <= i - 2; j++)
            f[i][i - 1] = std::min(f[i][i - 1], f[i - 1][j] + dis(a[j], a[i]));
    }
    double ans = 1e100;
    for (int i = 1; i < n; i++)
        ans = std::min(ans, f[n][i] + dis(a[n], a[i]));
    std::cout << std::fixed << std::setprecision(2) << ans;
    return 0;
}