// 5208.cpp
#include <iostream>

long long n, p;
long long inv[6000005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> p;
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (p - p / i) * inv[p % i] % p;
    for (int i = 1; i <= n; i++)
        std::cout << inv[i] << '\n';
    return 0;
}