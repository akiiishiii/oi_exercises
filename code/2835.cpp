// 2835.cpp
#include <iostream>

long long f[100010];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long ans = 0;
    int n, m;
    std::cin >> n >> m;
    for (int i = std::min(n, m); i >= 1; i--) {
        f[i] = (long long)(n / i) * (m / i);
        for (int j = i * 2; j <= std::min(n, m); j += i)
            f[i] -= f[j];
        ans += f[i] * (i * 2 - 1);
    }
    std::cout << ans << '\n';
    return 0;
}