// 1329.cpp
#include <algorithm>
#include <iostream>

int a[10010], b[10010];
int n, x, y, ans;

int main(int const argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i] >> b[i];
    std::sort(b + 1, b + n + 1);
    y = b[(n + 1) >> 1];
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        a[i] -= i;
    std::sort(a + 1, a + n + 1);
    x = a[(n + 1) >> 1];
    for (int i = 1; i <= n; i++)
        ans += std::abs(a[i] - x) + std::abs(b[i] - y);
    std::cout << ans << '\n';
    return 0;
}