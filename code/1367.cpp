// 1367.cpp
#include <iostream>
#include <iomanip>
#include <algorithm>

int n;
int a[10000] = {0}, b[10000] = {0}, c[10000] = {0};

double f(double x);
double tri(double l, double r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 0; i < n; i++)
            std::cin >> a[i] >> b[i] >> c[i];
        std::cout << std::fixed << std::setprecision(4) << f(tri(0, 1000)) << '\n';
    }
    return 0;
}

double f(double x) {
    double maxx = -1e10;
    for (int i = 0; i < n; i++) {
        double y = double(a[i]) * x * x + double(b[i]) * x + double(c[i]);
        maxx = std::max(maxx, y);
    }
    return maxx;
}

double tri(double l, double r) {
    while (l + 1e-10 < r) {
        double mid1 = l + (r - l) / 3.0, mid2 = r - (r - l) / 3.0;
        if (f(mid1) <= f(mid2))
            r = mid2;
        else
            l = mid1;
    }
    return l;
}