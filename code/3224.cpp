// 3224.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long p, ans, n;
    std::cin >> n;
    ans = n;
    for (long long i = 2; i * i <= n; i++)
        if (!(n % i)) {
            p = i;
            long long a = 0;
            while (!(n % p))
                a++, n /= p;
            ans += ans * a * (p - 1) / p;
        }
    if (n != 1)
        ans = ans * (n * 2 - 1) / n;
    std::cout << ans << '\n';
    return 0;
}