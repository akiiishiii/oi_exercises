#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll p[65], d[65], tot, bj;
inline ll in() {
    ll s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * w;
}
inline void charu(ll x) {
    for (ll i = 62; i >= 0; i--)
        if ((x >> i) & 1) {
            if (!p[i]) {
                p[i] = x;
                return;
            }
            x ^= p[i];
        }
    if (!x)
        bj = 1;
}
void build() {
    for (ll i = 62; i >= 0; i--)
        for (ll j = i - 1; j >= 0; j--)
            if ((p[i] >> j) & 1)
                p[i] ^= p[j];
    for (ll i = 0; i <= 62; i++)
        if (p[i])
            d[tot++] = p[i];
}
inline ll ask(ll x) {
    ll ans = 0, i;
    if (bj) {
        if (x == 1)
            return 0;
        else
            x--;
    }
    if (x >> tot)
        return -1;
    for (i = tot - 1; i >= 0; i--)
        if ((x >> i) & 1)
            ans ^= d[i];
    return ans;
}
int main() {
    int n, i, m;
    ll x;
    n = in();
    for (i = 1; i <= n; i++)
        x = in(), charu(x);
    build();
    m = in();
    while (m--) {
        x = in();
        printf("%lld\n", ask(x));
    }
}