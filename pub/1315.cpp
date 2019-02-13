// 1315.cpp
#include <iostream>

int main(int argc, char const * argv[]) {
    long long a, n, p, ans;
    std::cin >> a >> n >> p;
    ans = 1;
    while (n) {
        if (n & 1)
            ans = ans % p * a % p;
        a = a * a % p;
        n = n / 2;
    }
    std::cout << ans << std::endl;
    return 0;
}