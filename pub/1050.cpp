// 1050.cpp
#include <iostream>
#include <iomanip>

int main(int argc, const char * argv[]) {
    int x, n;
    std::cin >> x >> n;
    double result = x;
    for (int i = 0; i < n; i++)
        result *= 1.001;
    std::cout << std::fixed << std::setprecision(4) << result << std::endl;
    return 0;
}
