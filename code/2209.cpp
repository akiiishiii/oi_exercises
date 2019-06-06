// 2209.cpp
#include <iostream>

int a[200010], q[200010], n, m;
long long sum[200010] = {0}, ans = 0;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int l = 1, r = 1;
    q[l] = 0;
    for (int i = 1; i <= n; i++) {
        while (l <= r && q[l] < i - m)
            l++;
        ans = std::max(ans, sum[i] - sum[q[l]]);
        while (l <= r && sum[q[r]] >= sum[i])
            r--;
        q[++r] = i;
    }
    std::cout << ans << '\n';
    return 0;
}