// 1080.cpp
#include <iostream>
#include <iomanip>

int main(int argc, const char * argv[]) {
    int k, n;
    double x, y;
    std::cin >> k >> n >> x >> y;
    std::cout << std::fixed << std::setprecision(2) << (n <= k ? n * x : k * x + (n - k) * y);
    return 0;
}