// 1355.cpp
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>

int const Maxn = 200005;
int n, rk[Maxn], sec[Maxn], sa[Maxn], sm[Maxn], h[Maxn][20], a[Maxn];
int q, tmp[Maxn], tot, x, y;

void makesa(int m);
void geth();
void st();
int ask(int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], tmp[i] = a[i];
    std::sort(tmp + 1, tmp + n + 1);
    tot = std::unique(tmp + 1, tmp + n + 1) - tmp - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(tmp + 1, tmp + tot + 1, a[i]) - tmp;
    makesa(tot);
    geth();
    st();
    while (q--) {
        std::cin >> x >> y;
        if (x == y) {
            std::cout << n - x + 1 << '\n';
            continue;
        }
        x = rk[x], y = rk[y];
        if (x > y)
            std::swap(x, y);
        x++;
        std::cout << ask(x, y) << '\n';
    }
    return 0;
}

void makesa(int m) {
    int *x = rk, *y = sec;
    for (int i = 0; i <= m; i++)
        sm[i] = 0;
    for (int i = 1; i <= n; i++)
        sm[x[i] = a[i]]++;
    for (int i = 1; i <= m; i++)
        sm[i] += sm[i - 1];
    for (int i = n; i >= 1; i--)
        sa[sm[x[i]]--] = i;
    for (int j = 1, p = 0; p < n; j *= 2, m = p) {
        p = 0;
        for (int i = n - j + 1; i <= n; i++)
            y[++p] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] - j > 0)
                y[++p] = sa[i] - j;
        for (int i = 0; i <= m; i++)
            sm[i] = 0;
        for (int i = 1; i <= n; i++)
            sm[x[i]]++;
        for (int i = 1; i <= m; i++)
            sm[i] += sm[i - 1];
        for (int i = n; i >= 1; i--)
            sa[sm[x[y[i]]]--] = y[i];
        std::swap(x, y);
        x[sa[1]] = 1;
        p = 1;
        for (int i = 2; i <= n; i++) {
            if (y[sa[i - 1]] != y[sa[i]] || y[sa[i - 1] + j] != y[sa[i] + j])
                p++;
            x[sa[i]] = p;
        }
    }
    for (int i = 1; i <= n; i++)
        rk[sa[i]] = i;
}

void geth() {
    int k = 0;
    for (int i = 1; i <= n; i++)
        if (rk[i] == 1)
            h[rk[i]][0] = 0;
        else {
            int j = sa[rk[i] - 1];
            while (a[i + k] == a[j + k])
                k++;
            h[rk[i]][0] = k;
            if (k > 0)
                k--;
        }
}

void st() {
    for (int j = 1; j <= (int)log2(n); j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            h[i][j] = std::min(h[i][j - 1], h[i + (1 << (j - 1))][j - 1]);
}

int ask(int l, int r) {
    int t = (int)log2(r - l + 1);
    return std::min(h[l][t], h[r - (1 << t) + 1][t]);
}