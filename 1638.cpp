// 1638.cpp
#include <iostream>

int calc(int n, int p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, p, t;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> p;
        std::cout << calc(2 * n, p) - 2 * calc(n, p)  << '\n';
    }
    return 0;
}

int calc(int n, int p) {
    if (n < p)
        return 0;
    else {
        n /= p;
        return n + calc(n, p);
    }
}
