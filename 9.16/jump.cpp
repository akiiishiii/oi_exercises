// jump.cpp
#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>

//#define debug

#ifndef debug

std::ifstream in("jump.in");
std::ofstream out("jump.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int q[500005], h, t, n, k;
long long dis[500005], val[500005], f[500005], d;

bool check(long long g);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> d >> k;
    for (int i = 1; i <= n; i++)
        in >> dis[i] >> val[i];
    long long l = 0ll, r = 1000000000ll, ans = -1ll;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    out << ans << '\n';
    return 0;
}

bool check(long long g) {
    int p = 0;
    h = 1, t = 0, q[h] = 0;
    for (int i = 1; i <= n; i++)
        f[i] = 0xcfcfcfcf;
    for (int i = 1; i <= n; i++) {
        while (dis[i] - dis[p] >= std::max(d - g, 1ll) && p < i) {
            while (f[q[t]] <= f[p] && t >= h)
                t--;
            q[++t] = p++;
        }
        while (dis[i] - dis[q[h]] > d + g && h <= t)
            h++;
        if (h > t || f[q[h]] == 0xcfcfcfcf)
            continue;
        else
            f[i] = f[q[h]] + val[i];
        if (f[i] >= k)
            return true;
    }
    return false;
}