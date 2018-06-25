// 1007.cpp
#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, const char * argv[]) {
    double x, a, b, c, d;
    std::cin >> x >> a >> b >> c >> d;
    std::cout << std::fixed << std::setprecision(7) << a * pow(x, 3) + b * pow(x, 2) + c * x + d << std::endl;
    return 0;
}
