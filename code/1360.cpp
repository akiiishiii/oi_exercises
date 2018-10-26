// 1360.cpp
#include <iostream>

int a[2000010], q[2000010];
int l, r, ans;

template <typename T1, typename T2>
auto max(T1 const &a, T2 const &b) -> decltype(a > b ? a : b) { return a > b ? a : b; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], a[i + n] = a[i];
    for (int i = 1; i <= n; i++)
        a[i + n] = a[i];
    for (int i = 1; i <= n << 1; i++) {
        while (i - q[l] > n / 2 && r > l)
            l++;
        ans = ::max(ans, a[i] + a[q[l]] + i - q[l]);
        while (a[i] - i >= a[q[r]] - q[r] && r > l)
            r--;
        q[++r] = i;
    }
    std::cout << ans << '\n';
    return 0;
}
