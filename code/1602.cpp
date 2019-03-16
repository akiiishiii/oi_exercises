// 1602.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t, n, m, k;
    long long ans;
    long long x[21], y[21];
    std::cin >> t;
    while (t--) {
        ans = 0ll;
        std::cin >> n >> m >> k;
        for (int i = 0; i < k; i++)
            std::cin >> x[i] >> y[i];
        for (int i = 1; i < (1 << k); i++) {
            long long cnt = 0ll, x1 = 0ll, x2 = 0ll, y1 = 0ll, y2 = 0ll;
            for (int j = 0; j < k; j++)
                if ((1 << j) & i) {
                    if (cnt++) {
                        x1 = std::min(x1, x[j]), y1 = std::min(y1, y[j]);
                        x2 = std::max(x2, x[j]), y2 = std::max(y2, y[j]);
                    } else
                        x1 = x2 = x[j], y1 = y2 = y[j];
                }
            long long tmp = x1 * (n - x2 + 1) * y1 * (m - y2 + 1);
            if (cnt & 1)
                ans += tmp;
            else
                ans -= tmp;
        }
        std::cout << (1ll + n) * n * (1ll + m) * m / 4ll - ans << '\n';
    }
    return 0;
}