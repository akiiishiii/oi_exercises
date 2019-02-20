// 1155.cpp
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
int cnt = 0, h[205], tot[15];
struct node {
    int to, next, tot;
} q[20005];
int q1[50005], wz[50005], l, r, vst[205][1205];
int st[2005], d[205][1205], maxx, n;
int f[2005], g[205], a[15], b[15];
void add(int x, int y, int z) {
    cnt++;
    q[cnt].to = y;
    q[cnt].next = h[x];
    h[x] = cnt;
    q[cnt].tot = z;
}
void spfa() {
    int x, y, now, j, i;
    while (l != r) {
        l = (l + 1) % 50000;
        x = q1[l];
        y = wz[l];
        vst[x][y] = 0;
        for (i = h[x]; i; i = q[i].next) {
            j = q[i].to;
            now = (y | st[j]);
            if (d[j][now] > d[x][y] + q[i].tot) {
                d[j][now] = d[x][y] + q[i].tot;
                if (now == y && vst[j][now] == 0) {
                    vst[j][now] = 1;
                    r = (r + 1) % 50000;
                    q1[r] = j;
                    wz[r] = now;
                }
            }
        }
    }
}
void sitanna_tree() {
    int i, j, t;
    l = 0;
    r = 0;
    for (i = 0; i <= maxx; i++) {
        for (j = 0; j <= n; j++) {
            if (st[j] != 0 && (st[j] & i) == 0)
                continue;
            for (t = (i - 1) & i; t; t = (t - 1) & i)
                d[j][i] = min(d[j][i], d[j][t | st[j]] + d[j][(i - t) | st[j]]);
            if (d[j][i] < 0x7fffffff / 2) {
                r = (r + 1) % 50000;
                q1[r] = j;
                wz[r] = i;
                vst[j][i] = 1;
            }
        }
        spfa();
    }
}
int Check(int now) {
    int x = 0, y = 0, i;
    for (i = 1; i <= a[0]; i++)
        if (((1 << (i - 1)) & now) != 0)
            x += tot[i];

    for (i = 1; i <= b[0]; i++)
        if (((1 << (a[0] + i - 1)) & now) != 0)
            y++;

    if (x >= y)
        return 1;
    return 0;
}
void dp() {
    int i, j, ans1, ans2, x1, x2, y;

    for (i = 0; i <= maxx; i++) {
        f[i] = 0x7fffffff / 2;
        for (j = 0; j <= n; j++)
            f[i] = min(f[i], d[j][i]);
    }

    ans1 = 0;
    ans2 = 0;
    for (i = 1; i <= maxx; i++)
        if (Check(i) == 1) {
            for (j = (i - 1) & i; j; j = (j - 1) & i)
                if (f[j] < 0x7fffffff / 2 && f[i - j] < 0x7fffffff / 2 &&
                    Check(j) == 1 && Check(i - j) == 1)
                    f[i] = min(f[i], f[j] + f[i - j]);
        }
    for (i = 1; i <= maxx; i++)
        if (f[i] < 0x7fffffff / 2 && Check(i) == 1) {
            y = 0;
            for (j = 1; j <= b[0]; j++)
                if (((1 << (a[0] + j - 1)) & i) != 0)
                    y++;

            if (y == ans1)
                ans2 = min(f[i], ans2);
            if (y > ans1) {
                ans1 = y;
                ans2 = f[i];
            }
        }
    printf("%d %d\n", ans1, ans2);
}
int main() {
    int k, i, x, y, z, j, m, bjj = 0;
    while (scanf("%d", &n) != EOF) {
        memset(st, 0, sizeof(st));
        a[0] = 0;
        b[0] = 0;
        n--;
        for (i = 0; i <= n; i++) {
            scanf("%d%d", &x, &y);
            if (x != 0) {
                a[0]++;
                a[a[0]] = i;
                tot[a[0]] = x;
            }
            if (y != 0) {
                b[0]++;
                b[b[0]] = i;
            }
        }
        k = a[0] + b[0];
        for (i = 1; i <= a[0]; i++)
            st[a[i]] += (1 << (i - 1));

        for (i = 1; i <= b[0]; i++)
            st[b[i]] += (1 << (a[0] + i - 1));

        maxx = (1 << k) - 1;

        for (i = 0; i <= maxx; i++)
            for (j = 0; j <= n; j++)
                d[j][i] = 0x7fffffff / 2;
        for (i = 0; i <= n; i++)
            d[i][st[i]] = 0;

        cnt = 0;
        memset(h, 0, sizeof(h));
        scanf("%d", &m);
        for (i = 1; i <= m; i++) {
            scanf("%d%d%d", &x, &y, &z);
            x--;
            y--;
            add(x, y, z);
            add(y, x, z);
        }

        sitanna_tree();
        dp();
    }
    return 0;
}