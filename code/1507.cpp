// 1507.cpp
#include <iostream>

int n;
long long f[100005] = {0};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long p = 0, q = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> f[i];
    for (int i = n; i >= 2; i--)
        f[i] -= f[i - 1];
    for (int i = 2; i <= n; i++)
        if (f[i] > 0)
            p += f[i];
        else if (f[i] < 0)
            q -= f[i];
    std::cout << std::max(p, q) << '\n' << std::abs(p - q) + 1 << '\n';
    return 0;
}