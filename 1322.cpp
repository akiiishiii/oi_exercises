// 1322.cpp
#include <iostream>
#include <iomanip>
#include <cmath>

double a, b, c, d;

double f(double x) { return a * pow(x, 3) + b * pow(x, 2) + c * x + d; }
void solve(double xl, double xr);

int main(int argc, char const * argv[]) {
    std::cin >> a >> b >> c >> d;
    for (int i = -100; i < 100; i++)
        if (!f(i))
            std::cout << std::fixed << std::setprecision(2) << double(i) << ' ';
        else if (f(i) * f(i + 1) < 0)
            solve(i, i + 1);
    std::cout << std::endl;
    return 0;
}

void solve(double xl, double xr) {
    double xm = (xl + xr) / 2, ym = f(xm), yl = f(xl), yr = f(xr);
    if (xr - xl < 0.001 && yl * yr < 0) {
        std::cout << std::fixed << std::setprecision(2) << xl << ' ';
        return;
    } else if (yl * ym < 0)
        solve(xl, xm);
    else if (ym * yr < 0)
        solve(xm, xr);
    return;
}