// 1368.cpp
#include <iostream>
#include <cmath>

double x, y, l, w;

double f(double a) { return l * cos(a) + (w - x * cos(a)) / sin(a); }
double ternary(double l, double r);

int main(int argc, char const *argv[]) {
    while (std::cin >> x >> y >> l >> w)
        std::cout << (f(ternary(0, 1.57075)) <= y ? "yes\n" : "no\n");
    return 0;
}

double ternary(double l, double r) {
    while (l + 1e-4 < r) {
        double mid1 = l + (r - l) / 3.0, mid2 = r - (r - l) / 3.0;
        if (f(mid1) > f(mid2))
            r = mid2;
        else
            l = mid1;
    }
    return l;
}