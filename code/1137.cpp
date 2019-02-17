// 1137.cpp
#include <algorithm>
#include <iostream>
#include <cstring>

int const Maxn = 90005;
int n, m, e, f[Maxn], d[Maxn * 10];

struct segment_tree {
    int ll, rr, S;
    bool operator<(segment_tree const &s) { return rr < s.rr; }
} a[Maxn];

void update(int i) { d[i] = std::min(d[i * 2], d[i * 2 + 1]); }
void build(int l, int r, int i);
void change(int ll, int rr, int i, int pos, int w);
int query(int ll, int rr, int i, int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m >> e;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].ll >> a[i].rr >> a[i].S;
        a[i].ll = std::max(a[i].ll, m);
        a[i].rr = std::min(a[i].rr, e);
    }
    std::sort(a + 1, a + 1 + n);
    build(m - 1, e, 1);
    memset(f, 0x3f, sizeof f);
    f[m - 1] = 0;
    for (int i = 1; i <= n; i++) {
        int c = query(m - 1, e, 1, a[i].ll - 1, a[i].rr - 1) + a[i].S;
        if (f[a[i].rr] > c)
            change(m - 1, e, 1, a[i].rr, f[a[i].rr] = c);
    }
    std::cout << (f[e] == 0x3f3f3f3f ? -1 : f[e]) << '\n';
    return 0;
}

void build(int l, int r, int i) {
    if (l == r) {
        if (l == m - 1)
            d[i] = 0;
        else
            d[i] = 0x3f3f3f3f;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, i * 2);
    build(mid + 1, r, i * 2 + 1);
    update(i);
}

void change(int ll, int rr, int i, int pos, int w) {
    if (ll == rr) {
        d[i] = w;
        return;
    }
    int mid = (ll + rr) >> 1;
    if (pos <= mid)
        change(ll, mid, i * 2, pos, w);
    else if (pos > mid)
        change(mid + 1, rr, i * 2 + 1, pos, w);
    update(i);
}

int query(int ll, int rr, int i, int l, int r) {
    int ans = 0x3f3f3f3f;
    int mid = (ll + rr) >> 1;
    if (ll == l && rr == r)
        return d[i];
    if (l <= mid && r >= mid + 1) {
        ans = std::min(ans, query(ll, mid, i * 2, l, mid));
        ans = std::min(ans, query(mid + 1, rr, i * 2 + 1, mid + 1, r));
    }
    if (r <= mid)
        ans = std::min(ans, query(ll, mid, i * 2, l, r));
    if (l >= mid + 1)
        ans = std::min(ans, query(mid + 1, rr, i * 2 + 1, l, r));
    return ans;
}