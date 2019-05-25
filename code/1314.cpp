// 1314.cpp
#include <iostream>

double a[100005], b[100005], s[100005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, F;
    std::cin >> N >> F;
    for (int i = 1; i <= N; i++)
        std::cin >> a[i];
    double eps = 1e-5, l = -1e6, r = 1e6;
    while (r - l > eps) {
        double mid = (l + r) / 2.0;
        for (int i = 1; i <= N; i++)
            b[i] = a[i] - mid;
        for (int i = 1; i <= N; i++)
            s[i] = (s[i - 1] + b[i]);
        double ans = -1e10, min_val = 1e10;
        for (int i = F; i <= N; i++) {
            min_val = std::min(min_val, s[i - F]);
            ans = std::max(ans, s[i] - min_val);
        }
        if (ans >= 0)
            l = mid;
        else
            r = mid;
    }
    std::cout << int(r * 1000) << '\n';
    return 0;
}