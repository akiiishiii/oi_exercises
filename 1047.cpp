// 1047.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n = 1, m;
    double sum = 0;
    std::cin >> m;
    while (sum <= m)
        sum += 1.0 / n++;
    std::cout << n - 2 << std::endl;
    return 0;
}
