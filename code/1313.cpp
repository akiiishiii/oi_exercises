// 1313.cpp
#include <algorithm>
#include <iostream>

int n, a[100005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    long long ans = 0ll;
    for (int i = 1; i <= n; i++)
        ans += std::abs((long long)a[i] - a[((n & 1) ? (n + 1) : n) / 2]);
    std::cout << ans << '\n';
    return 0;
}