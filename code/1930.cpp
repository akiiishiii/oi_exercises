// 1930.cpp
#include <iostream>

int const Mod = 1234567;

long long power(long long a, long long b);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::cout << power(2, n - 1) << '\n';
    return 0;
}

long long power(long long a, long long b) {
    long long ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return ans % Mod;
}