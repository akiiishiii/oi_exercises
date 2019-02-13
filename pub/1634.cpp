// 1634.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, n;
    long long ans = 1;
    int p[3402] = {0}, c[3402] = {0};
    while (std::cin >> n) {
        ans = 1, m = 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                p[++m] = i, c[m] = 0;
                while (n % i == 0)
                    n /= i, c[m]++;
            }
        }
        if (n > 1)
            p[++m] = n, c[m] = 1;
        for (int i = 1; i <= m; i++)
            ans *= c[i] + 1;
        std::cout << ans << '\n';
    }
    return 0;
}