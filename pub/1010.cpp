// 1010.cpp
#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, const char * argv[]) {
    double a, b, c;
    std::cin >> a >> b >> c;
    double p = (a + b + c) / 2;
    std::cout << std::fixed << std::setprecision(2) << sqrt(p * (p - a) * (p - b) * (p - c)) << std::endl;
    return 0;
}
