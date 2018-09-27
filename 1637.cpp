// 1637.cpp
#include <iostream>

int calc(int n);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n)
        std::cout << calc(n) << '\n';
    return 0;
}

int calc(int n) {
    if (n < 5)
        return 0;
    else {
        n /= 5;
        return n + calc(n);
    }
}