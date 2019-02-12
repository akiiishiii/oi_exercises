// 3661.cpp
#include <iomanip>
#include <iostream>
#include <algorithm>

double const eps = 1e-8;
int const Maxn = 1005;
int a[Maxn], b[Maxn];
int n, m;

double chk(double lambda);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (std::cin >> n >> m && (n || m)) {
        for (int i = 1; i <= n; i++)
            std::cin >> a[i];
        for (int i = 1; i <= n; i++)
            std::cin >> b[i];
        double l = 0.0, r = 1.0, ans = 0.0;
        while (r - l > eps) {
            double mid = (l + r) / 2.0;
            if (chk(mid) >= 0.0)
                ans = mid, l = mid;
            else
                r = mid;
        }
        std::cout << std::fixed << std::setprecision(0) << ans * 100 << '\n';
    }
    return 0;
}

double chk(double lambda) {
    double ret = 0.0, c[2005];
    for (int i = 1; i <= n; i++)
        c[i] = a[i] - lambda * b[i];
    std::sort(c + 1, c + n + 1);
    for (int i = m + 1; i <= n; i++)
        ret += c[i];
    return ret;
}