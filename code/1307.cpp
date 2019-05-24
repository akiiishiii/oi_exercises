// 1307.cpp
#include <iostream>

int power(int a, int b, int p) {
    int ans = 1 % p;
    for (; b; b >>= 1) {
        if (b & 1)
            ans = (long long)ans * a % p;
        a = (long long)a * a % p;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, n, p;
    std::cin >> a >> n >> p;
    std::cout << power(a, n, p) % p << '\n';
    return 0;
}