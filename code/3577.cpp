// 3577.cpp
#include <iostream>

int const Maxn = 200005;
int w[Maxn], f[Maxn], q[Maxn];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> w[i];
    int l = 0, r = 0, ans = 2e9;
    for (int i = 1; i <= n; i++) {
        while (l <= r && q[l] < i - m)
            l++;
        f[i] = f[q[l]] + w[i];
        if (i >= n - m + 1)
            ans = std::min(ans, f[i]);
        while (l <= r && f[q[r]] >= f[i])
            r--;
        q[++r] = i;
    }
    std::cout << ans << '\n';
    return 0;
}