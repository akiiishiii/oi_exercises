// 2175.cpp
#include <iomanip>
#include <iostream>

int n;
double k, a[1005] = {0}, ans = 0, cnt = 0;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::cin >> k;
    for (int i = 1; i < n; i++) {
        if (k < a[i])
            continue;
        int tmp = k / a[i];
        for (int j = i + 1; j <= n; j++)
            ans = std::max(ans, tmp * (a[j] - a[i]));
    }
    for (int i = 1; i < n; i++)
        if (a[i] <= k)
            for (int j = i + 1; j <= n; j++)
                if (a[j] > a[i])
                    cnt++;
    double p = n * (n - 1) / 2;
    std::cout << std::fixed << std::setprecision(3) << ans << '\n'
              << cnt / p << '\n';
    return 0;
}