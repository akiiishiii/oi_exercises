// 2420.cpp
#include <cmath>
#include <iostream>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    double fab = (sqrt(5) + 1.0) / 2.0;
    while (std::cin >> a >> b) {
        if (a > b)
            std::swap(a, b);
        int tmp = (b - a) * fab;
        std::cout << int(!(tmp == a)) << '\n';
    }
    return 0;
}