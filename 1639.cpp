// 1639.cpp
#include <iostream>

template <typename T>
T getgcd(T const &a, T const &b) { return (b) ? getgcd(b, a % b) : a; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, lcm, gcd, a, b;
    std::cin >> n >> a >> b;
    gcd = getgcd<int>(a, b);
    lcm = a * b / gcd;
    for (int i = 3; i <= n; i++) {
        std::cin >> a;
        gcd = getgcd(gcd, a);
        lcm = lcm / getgcd(lcm, a) * a;
    }
    std::cout << gcd << '\n'
              << lcm << '\n';
    return 0;
}
