// 1027.cpp
#include <iostream>
#include <cmath>

int main(int argc, const char * argv[]) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (b * b - 4 * a * c >= 0)
        std::cout << "YES\n";
    else
        std::cout << "NO SOLUTION\n";
    return 0;
}
