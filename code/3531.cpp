// 3531.cpp
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>


struct rec {
    int x, y;
    bool operator<(rec const &r) const { return y < r.y; }
};

std::set<rec> s;
std::set<rec>::iterator it, lt, rt;
int const Maxn = 100010;
long long da[18][Maxn][2], db[18][Maxn][2], ansa, ansb, a, r;
int f[18][Maxn][2], ans, n, m, t, i, j, k, h[Maxn], g[Maxn], ga[Maxn], gb[Maxn], xx, p, x, y;

bool cmp(int a, int r) {
    return abs(h[a] - h[i]) < abs(h[r] - h[i]) ||
           (abs(h[a] - h[i]) == abs(h[r] - h[i]) && h[a] < h[r]);
}

void solve(int s, int xx, long long &a, long long &r) {
    a = r = k = 0;
    for (int i = t; i >= 0; i--)
        if (f[i][s][k] && da[i][s][k] + db[i][s][k] <= xx) {
            xx -= da[i][s][k] + db[i][s][k];
            a += da[i][s][k], r += db[i][s][k];
            s = f[i][s][k];
        }
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (i = 1; i <= n; i++)
        std::cin >> h[i];
    for (i = n; i; i--) {
        rec r;
        r.x = i, r.y = h[i];
        s.insert(r);
        it = s.find(r);
        lt = it, rt = it, m = 0;
        if (lt != s.begin())
            lt--, g[++m] = lt->x;
        if (lt != s.begin())
            lt--, g[++m] = lt->x;
        if (rt++, rt != s.end()) {
            g[++m] = rt->x;
            if (rt++, rt != s.end())
                g[++m] = rt->x;
        }
        std::sort(g + 1, g + m + 1);
        if (m)
            gb[i] = g[1];
        if (m > 1)
            ga[i] = g[2];
    }
    for (i = 1; i <= n; i++) {
        if (ga[i]) {
            f[0][i][0] = ga[i];
            da[0][i][0] = abs(h[ga[i]] - h[i]);
            db[0][i][0] = 0;
        }
        if (gb[i]) {
            f[0][i][1] = gb[i];
            da[0][i][1] = 0;
            db[0][i][1] = abs(h[gb[i]] - h[i]);
        }
    }
    t = (int)(log(n * 1.0) / log(2.0) + 0.001);
    for (i = 1; i <= t; i++)
        for (j = 1; j <= n; j++)
            for (k = 0; k <= 1; k++) {
                if (i == 1)
                    p = k ^ 1;
                else
                    p = k;
                if (f[i - 1][j][k])
                    f[i][j][k] = f[i - 1][f[i - 1][j][k]][p];
                if (f[i][j][k]) {
                    da[i][j][k] =
                        da[i - 1][j][k] + da[i - 1][f[i - 1][j][k]][p];
                    db[i][j][k] =
                        db[i - 1][j][k] + db[i - 1][f[i - 1][j][k]][p];
                }
            }
    std::cin >> xx;
    ansa = 1, ansb = 0;
    for (i = 1; i <= n; i++) {
        solve(i, xx, a, r);
        if (!r)
            a = 1;
        if (a * ansb < ansa * r || (a * ansb == ansa * r && h[i] > h[ans]))
            ansa = a, ansb = r, ans = i;
    }
    std::cout << ans << '\n';
    std::cin >> m;
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        solve(x, y, a, r);
        printf("%lld %lld\n", a, r);
    }
    return 0;
}