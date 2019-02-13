// 1009.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int a, b;
    std::cin >> a >> b;
    std::cout << a / b << ' ' << a - a / b * b << std::endl;
    return 0;
}
