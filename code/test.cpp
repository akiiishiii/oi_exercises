// 3601.cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define LL long long
const LL mod = 1e9 + 7;
inline LL read() {
    LL x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + c - 48, c = getchar();
    return x;
}
int T;
LL n, m, fac[55], a[55];
inline LL quick(LL a, LL b) {
    LL S = 1;
    while (b) {
        if (b & 1ll)
            S = S * a % mod;
        b >>= 1ll;
        a = a * a % mod;
    }
    return S;
}
inline LL calc(LL n, int m) {
    if (n <= m + 2) {
        LL ans = 0;
        for (int i = 1; i <= n; i++)
            ans = (ans + quick(i, m) % mod) % mod;
        return ans;
    }
    LL ans = 1, now = 0, tot = 0;
    for (int i = 1; i <= m + 2; i++)
        ans = (ans * (n - i + mod) % mod) % mod;
    for (int i = 1; i <= m + 2; i++) {
        now = now + quick(i, m);
        now %= mod;
        LL t = ans * quick((n - i + mod) % mod, mod - 2) % mod,
           q = quick(fac[m + 2 - i] * fac[i - 1] % mod, mod - 2);
        if ((m + 2 - i) & 1)
            tot -= now * t % mod * q % mod;
        else
            tot += now * t % mod * q % mod;
        tot += mod;
        tot %= mod;
    }
    return tot;
}
int main() {
    T = read();
    fac[0] = 1;
    for (int i = 1; i <= 54; i++)
        fac[i] = (fac[i - 1] * (LL)i) % mod;
    while (T--) {
        n = read(), m = read();
        for (int i = 1; i <= m; i++)
            a[i] = read();
        std::sort(a + 1, a + m + 1);
        LL ans = 0;
        for (int i = 0; i <= m; i++) {
            ans += calc(n - a[i], m + 1);
            ans %= mod;
            for (int j = i + 1; j <= m; j++)
                ans = (ans - quick(a[j] - a[i], m + 1) % mod + mod) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}