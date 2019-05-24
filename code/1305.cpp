// 1305.cpp
#include <iostream>

long long mul(long long a, long long b, long long p) {
    long long ans = 0;
    for (; b; b >>= 1) {
        if (b & 1)
            ans = (ans + a) % p;
        a = a * 2 % p;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long a, b, p;
    std::cin >> a >> b >> p;
    std::cout << mul(a, b, p) % p << '\n';
    return 0;
}