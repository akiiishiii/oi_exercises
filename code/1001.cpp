// 1001.cpp
#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, ans = 0;
    int a[1001] = {0}, f[1001];
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], f[i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[j] <= a[i] && f[j] + 1 > f[i])
                f[i] = f[j] + 1;
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, f[i]);
    std::cout << ans << '\n';
    return 0;
}
