// 2791.cpp
#include <algorithm>
#include <iostream>

long long a[1000010], f[1000010], sum, ans;
int n;

int main(int const argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], sum += a[i];
    sum /= n;
    for (int i = 1; i <= n; i++)
        a[i] -= sum;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] + a[i];
    std::sort(f + 1, f + n + 1);
    for (int i = 1; i <= n; i++)
        ans += std::abs(f[i] - f[(n + 1) / 2]);
    std::cout << ans << '\n';
    return 0;
}