// 1551.cpp
#include <iostream>

int n;

void build(int k);

int main(int argc, char const *argv[]) {
    std::cin >> n;
    std::cout << '(';
    build(1);
    std::cout << ")\n";
    return 0;
}

void build(int k) {
    if (k <= n)
        std::cout << k;
    if (2 * k <= n) {
        std::cout << '(';
        build(2 * k);
    }
    if (2 * k + 1 <= n) {
        std::cout << ',';
        build(2 * k + 1);
    }
    if (2 * k <= n)
        std::cout << ')';
    return;
}
