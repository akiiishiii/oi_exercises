// 1052.cpp
#include <algorithm>
#include <iostream>

int f[10005], d[10005], a[10005], flag[10005], p, s, t, n;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> p >> s >> t >> n;
    if (s == t) {
        int cnt = 0, tmp;
        for (int i = 1; i <= n; ++i)
            std::cin >> tmp, cnt += ((tmp % s) == 0);
        std::cout << cnt << '\n';
        return 0;
    }
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    a[0] = f[0] = 0;
    d[n + 1] = std::min(p - a[n], 100);
    p = 0;
    for (int i = 1; i <= n; i++)
        d[i] = std::min(a[i] - a[i - 1], 90), p += d[i], flag[p] = 1;
    p += d[n + 1];
    for (int i = 1; i <= p + 9; i++) {
        f[i] = 0x3f3f3f3f;
        for (int j = s; j <= t; j++)
            if (i >= j)
                f[i] = std::min(f[i], f[i - j] + flag[i]);
    }
    int minn = 0x3f3f3f3f;
    for (int i = p; i <= p + 9; i++)
        minn = std::min(minn, f[i]);
    std::cout << minn << '\n';
    return 0;
}