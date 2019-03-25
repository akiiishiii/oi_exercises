#include <iostream>
#include <cmath>

inline long long calc(long long n);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n, ans = 0ll;
    std::cin >> n;
    long long lim = sqrt(n);
    for (long long i = 1; i <= lim; i++)
        if ((n / i) & 1)
            ans ^= i;
    for (long long i = 1; n/(i + 1) >= lim; i += 2)
        ans ^= calc(n / (i + 1)) ^ calc(n / i);
    std::cout << ans << '\n';
    return 0;
}

inline long long calc(long long n) {
    switch (n % 4) {
        case 1:
            return 1;
        case 2:
            return n + 1;
        case 3:
            return 0;
        default:
            return n;
    }
}