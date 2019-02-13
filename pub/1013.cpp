// 1013.cpp
#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, const char * argv[]) {
    double xa, ya, xb, yb, xc, yc, a, b, c;
    std::cin >> xa >> ya >> xb >> yb >> xc >> yc;
    a = sqrt(pow(xb - xc, 2) + pow(yb - yc, 2));
    b = sqrt(pow(xa - xc, 2) + pow(ya - yc, 2));
    c = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
    double p = (a + b + c) / 2;
    std::cout << std::fixed << std::setprecision(2) << sqrt(p * (p - a) * (p - b) * (p - c)) << std::endl;
    return 0;
}
