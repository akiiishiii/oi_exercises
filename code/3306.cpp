// 3306.cpp
#include <iostream>

int T, n;
int s[100005], e[100005], d[100005];

int calc(int x);

int main(int const argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; i++)
            std::cin >> s[i] >> e[i] >> d[i];
        int ans = 0;
        long long l = 0, r = 2147483647;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (calc(mid) & 1)
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        if (!ans)
            std::cout << "Poor QIN Teng:(\n";
        else
            std::cout << ans << ' ' << calc(ans) - calc(ans - 1) << '\n';
    }
    return 0;
}

int calc(int x) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] <= x)
            sum += (std::min(e[i], x) - s[i]) / d[i] + 1;
    return sum;
}