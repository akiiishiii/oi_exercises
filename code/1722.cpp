// 1722.cpp
#include <algorithm>
#include <iostream>

int const Maxn = 100010;
int n, m, cnt = 0;
int x[Maxn], a[Maxn], y[Maxn], rt[Maxn];

struct seg {
    int lc, rc, sum;
} tree[Maxn * 20];

int insert(int x, int last, int l, int r) {
    int c = ++cnt;
    tree[c] = tree[last];
    tree[c].sum++;
    if (l == r)
        return cnt;
    if (x <= (l + r) / 2)
        tree[c].lc = insert(x, tree[last].lc, l, (l + r) / 2);
    else
        tree[c].rc = insert(x, tree[last].rc, (l + r) / 2 + 1, r);
    return c;
}

int ask(int t1, int t2, int k, int l, int r) {
    if (l == r)
        return l;
    int x = tree[tree[t2].lc].sum - tree[tree[t1].lc].sum;
    if (k <= x)
        return ask(tree[t1].lc, tree[t2].lc, k, l, (l + r) / 2);
    else
        return ask(tree[t1].rc, tree[t2].rc, k - x, (l + r) / 2 + 1, r);
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> x[i], y[i] = x[i];
    std::sort(x + 1, x + n + 1);
    int sz = std::unique(x + 1, x + n + 1) - x - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(x + 1, x + sz + 1, y[i]) - x;
    for (int i = 1; i <= n; i++)
        rt[i] = insert(a[i], rt[i - 1], 1, n);
    for (int i = 1, l, r, k; i <= m; i++) {
        std::cin >> l >> r >> k;
        std::cout << x[ask(rt[l - 1], rt[r], k, 1, n)] << '\n';
    }
    return 0;
}