// 2727.cpp
#include <cmath>
#include <iomanip>
#include <iostream>

double ax, ay, bx, by, cx, cy, dx, dy, p, q, r;

inline double dis(double x1, double y1, double x2, double y2) { return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }
double cal(double x, double y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(NULL);
    std::cin.tie(NULL);
    std::cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy >> p >> q >> r;
    double lx = ax, ly = ay, rx = bx, ry = by;
    double x1, y1, x2, y2, t1, t2;
    while (fabs(rx - lx) > 1e-6 || fabs(ry - ly) > 1e-6) {
        x1 = lx + (rx - lx) / 3, y1 = ly + (ry - ly) / 3;
        x2 = lx + (rx - lx) / 3 * 2, y2 = ly + (ry - ly) / 3 * 2;
        t1 = cal(x1, y1), t2 = cal(x2, y2);
        if (t1 > t2)
            lx = x1, ly = y1;
        else
            rx = x2, ry = y2;
    }
    std::cout << std::fixed << std::setprecision(2) << cal(lx, ly) << '\n';
    return 0;
}

double cal(double x, double y) {
    double lx = cx, ly = cy, rx = dx, ry = dy;
    double x1, y1, x2, y2, t1, t2;
    while (fabs(rx - lx) > 1e-6 || fabs(ry - ly) > 1e-6) {
        x1 = lx + (rx - lx) / 3, y1 = ly + (ry - ly) / 3;
        x2 = lx + (rx - lx) / 3 * 2, y2 = ly + (ry - ly) / 3 * 2;
        t1 = dis(ax, ay, x, y) / p + dis(x, y, x1, y1) / r + dis(x1, y1, dx, dy) / q;
        t2 = dis(ax, ay, x, y) / p + dis(x, y, x2, y2) / r + dis(x2, y2, dx, dy) / q;
        if (t1 > t2)
            lx = x1, ly = y1;
        else
            rx = x2, ry = y2;
    }
    return dis(ax, ay, x, y) / p + dis(x, y, lx, ly) / r + dis(lx, ly, dx, dy) / q;
}