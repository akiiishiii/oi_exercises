// 1314.cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

double a[100001], b[100001], sum[100001];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, F;
    std::cin >> N >> F;
    for (int i = 1; i <= N; i++)
        std::cin >> a[i];
    double eps = 1e-5;
    double l = -1e6, r = 1e6;
    while (r - l > eps) {
        double mid = (l + r) / 2.0;
        for (int i = 1; i <= N; i++)
            b[i] = a[i] - mid;
        for (int i = 1; i <= N; i++)
            sum[i] = (sum[i - 1] + b[i]);
        double ans = -1e10, min_val = 1e10;
        for (int i = F; i <= N; i++) {
            min_val = std::min(min_val, sum[i - F]);
            ans = std::max(ans, sum[i] - min_val);
        }
        if (ans >= 0)
            l = mid;
        else
            r = mid;
    }
    std::cout << int(r * 1000) << '\n';
    return 0;
}