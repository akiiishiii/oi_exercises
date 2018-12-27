// 1525.cpp
#include <algorithm>
#include <iostream>

int const Maxn = 5000010;

int cnt;
int d[Maxn], prt[Maxn], h[Maxn], root[Maxn], ans[Maxn];
int ls[Maxn], rs[Maxn], sum[Maxn];

struct node {
    int a, b, w;
    int ans, id, f;
    bool operator<(node const &x) const { return w < x.w || (w == x.w && f < x.f); }
} a[Maxn];

int search(int x) { return x == prt[x] ? x : prt[x] = search(prt[x]); }
void insert(int &k, int l, int r, int val);
int query(int k, int l, int r, int rank);
int merge(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, q;
    std::cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        std::cin >> h[i], d[i] = h[i];
    std::sort(d + 1, d + n + 1);
    for (int i = 1; i <= n; i++)
        h[i] = std::lower_bound(d + 1, d + n + 1, h[i]) - d;
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    for (int i = 1; i <= m; i++)
        a[i].f = 0, std::cin >> a[i].a >> a[i].b >> a[i].w;
    for (int i = m + 1; i <= m + q; i++) {
        a[i].f = 1, a[i].id = i - m;
        std::cin >> a[i].a >> a[i].w >> a[i].b;
    }
    std::sort(a + 1, a + m + q + 1);
    for (int i = 1; i <= n; i++)
        insert(root[i], 1, n, h[i]);
    for (int i = 1; i <= m + q; i++)
        if (!a[i].f) {
            int p = search(a[i].a), q = search(a[i].b);
            if (p != q) {
                prt[p] = q;
                root[q] = merge(root[p], root[q]);
            }
        } else {
            int x = search(a[i].a);
            if (sum[root[x]] < a[i].b)
                ans[a[i].id] = -1;
            else
                ans[a[i].id] =
                    d[query(root[x], 1, n, sum[root[x]] - a[i].b + 1)];
        }
    for (int i = 1; i <= q; i++)
        std::cout << ans[i] << "\n";
    return 0;
}

void insert(int &k, int l, int r, int val) {
    if (!k)
        k = ++cnt;
    sum[k] = 1;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (val <= mid)
        insert(ls[k], l, mid, val);
    else
        insert(rs[k], mid + 1, r, val);
}

int query(int k, int l, int r, int rank) {
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    if (sum[ls[k]] >= rank)
        return query(ls[k], l, mid, rank);
    else
        return query(rs[k], mid + 1, r, rank - sum[ls[k]]);
}

int merge(int x, int y) {
    if (!x)
        return y;
    if (!y)
        return x;
    if (!ls[x] && !rs[x]) {
        sum[x] = sum[x] + sum[y];
        return x;
    }
    ls[x] = merge(ls[x], ls[y]);
    rs[x] = merge(rs[x], rs[y]);
    sum[x] = sum[ls[x]] + sum[rs[x]];
    return x;
}