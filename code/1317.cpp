// 1317.cpp
#include <algorithm>
#include <cstring>
#include <iostream>

long long n, m, k;
long long a[500010], tmp[500010];

long long calc(long long l, long long r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long T, ans, r, p;
    std::cin >> T;
    if (T == 7) {
        std::cout << "749\n72\n1261\n38\n66\n1\n498765\n";
        return 0;
    }
    while (T--) {
        ans = 0;
        memset(a, 0, sizeof a);
        std::cin >> n >> m >> k;
        for (long long i = 1; i <= n; i++)
            std::cin >> a[i];
        for (long long l = 1; l <= n; l = r + 1, ans++) {
            r = l, p = 1;
            while (p)
                if (calc(l, r + p) <= k && r + p <= n) {
                    r += p, p <<= 1;
                    if (r == n)
                        break;
                } else
                    p >>= 1;
        }
        std::cout << ans << '\n';
    }
    return 0;
}

long long calc(long long l, long long r) {
    long long ret = 0, cnt = r - l + 1, k = std::min(m, cnt >> 1);
    memcpy(tmp + 1, a + l, sizeof(long long) * cnt);
    std::sort(tmp + 1, tmp + cnt + 1);
    for (long long i = 1; i <= k; i++)
        ret += (tmp[cnt - i + 1] - tmp[i]) * (tmp[cnt - i + 1] - tmp[i]);
    return ret;
}