// 1366.cpp
#include <iostream>
#include <iomanip>

double H, h, D;

inline double f(double x) { return (h * D - H * x) / (D - x) + x; }
double tri(double l, double r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> H >> h >> D;
        std::cout << std::fixed << std::setprecision(3) << f(tri(0, (h / H) * D)) << '\n';
    }
    return 0;
}

double tri(double l, double r) {
    while (l + 1e-8 < r) {
        double mid1 = l + (r - l) / 3.0, mid2 = r - (r - l) / 3.0;
        if (f(mid1) > f(mid2))
            r = mid2;
        else
            l = mid1;
    }
    return l;
}