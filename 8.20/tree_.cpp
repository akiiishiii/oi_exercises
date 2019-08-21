#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int n, cnt, h[201], f[201][201], k, zx1, zx2, ans, son[201],
    mod = 10007, g[201][201], w[201];
struct pp {
    int to, next;
} a[201 * 2];
void add(int x, int y) {
    cnt++;
    a[cnt].to = y;
    a[cnt].next = h[x];
    h[x] = cnt;
}
void find(int x, int fa) {
    int maxx = 0;
    son[x] = 1;
    for (int i = h[x]; i; i = a[i].next) {
        int y = a[i].to;
        if (y == fa)
            continue;
        find(y, x);
        son[x] += son[y];
        maxx = max(son[y], maxx);
    }
    if (n - son[x] > maxx)
        maxx = n - son[x];
    if (maxx < ans)
        ans = maxx, k = 1, zx1 = x;
    else if (maxx == ans)
        k = 2, zx2 = x;
}
void pre(int x, int fa) {
    f[x][0] = 0;
    f[x][1] = 1;
    son[x] = 1;
    for (int i = h[x]; i; i = a[i].next) {
        int y = a[i].to;
        if (y == fa)
            continue;
        pre(y, x);
        son[x] += son[y];
        for (int k = son[x]; k >= 1; k--)
            for (int j = 1; j <= min(son[y], k - 1); j++)
                f[x][k] = (f[x][k] + f[y][j] * f[x][k - j]) % mod;
    }
}
void solve1(int q, int x) {
    pre(x, 0);
    int ans1 = 0, tot = 0, mx = 0;
    for (int i = h[x]; i; i = a[i].next) {
        int y = a[i].to;
        tot += son[y];
        mx = max(mx, son[y]);
        for (int j = tot; j >= 1; j--)
            for (int u = min(j, son[y]); u >= 1; u--) {
                if (j == u) {
                    g[j][u] = (g[j][u] + f[y][u]) % mod;
                    continue;
                }
                for (int tt = 1; tt <= u; tt++) {
                    g[j][u] = (g[j][u] + g[j - u][tt] * f[y][u]) % mod;
                }
                for (int t = u + 1; t <= mx && t <= j; t++) {
                    g[j][t] = (g[j][t] + g[j - u][t] * f[y][u]) % mod;
                }
            }
    }
    for (int j = 1; j <= tot; j++)
        for (int t = 1; t <= mx; t++)
            if (t * 2 < (j + 1))
                ans1 = (ans1 + g[j][t]) % mod;
    printf("Case %d: %d\n", q, (ans1 + 1) % mod);
}
void solve2(int q) {
    pre(zx1, 0);
    int ans1 = 0, tot = 0;
    w[0] = 1;
    for (int i = h[zx1]; i; i = a[i].next) {
        int y = a[i].to;
        if (y == zx2)
            continue;
        tot += son[y];
        for (int j = min(tot, son[zx2] - 1); j >= 1; j--) {
            for (int u = min(j, son[y]); u >= 1; u--) {
                w[j] = (w[j] + w[j - u] * f[y][u]) % mod;
            }
        }
    }
    for (int i = son[zx2] - 1; i >= 0; i--)
        ans1 = (ans1 + w[i] * f[zx2][i + 1]) % mod;
    printf("Case %d: %d\n", q, ans1 % mod);
}
int main() {
    int Q, x, y;
    cin >> Q;
    for (int q = 1; q <= Q; q++) {
        memset(h, 0, sizeof(h));
        cnt = 0;
        memset(son, 0, sizeof(son));
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        scanf("%d", &n);
        k = 0;
        ans = 0x7fffffff / 2;
        for (int i = 1; i < n; i++)
            scanf("%d%d", &x, &y), add(x, y), add(y, x);
        find(1, 0);
        memset(son, 0, sizeof(son));
        if (k == 1)
            solve1(q, zx1);
        else
            solve2(q), memset(w, 0, sizeof(w));
    }
    return 0;
}
