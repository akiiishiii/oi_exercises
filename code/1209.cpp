// 1209.cpp
#include <algorithm>
#include <iostream>

int const Maxn = 80005;

struct rectangle {
    int s, t, h;
    bool operator<(rectangle const &r) const { return h < r.h; }
} a[Maxn * 4 + 1];

struct segment_tree {
    int a, b;
    int h;
} tree[Maxn * 4 + 1];

int b[Maxn * 4 + 1];
long long ans = 0;

void build(int v, int l, int r);
void insert(int v, int l, int r, int x);
void calc(int v);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].s >> a[i].t >> a[i].h;
        b[i] = a[i].s;
        b[i + n] = a[i].t;
    }
    std::sort(b + 1, b + 2 * n + 1);
    int tot = std::unique(b + 1, b + 2 * n + 1) - b - 1;
    build(1, 1, tot);
    for (int i = 1; i <= n; i++) {
        a[i].s = std::lower_bound(b + 1, b + tot + 1, a[i].s) - b;
        a[i].t = std::lower_bound(b + 1, b + tot + 1, a[i].t) - b;
    }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        insert(1, a[i].s, a[i].t - 1, a[i].h);
    calc(1);
    std::cout << ans << '\n';
    return 0;
}

void build(int v, int l, int r) {
    tree[v].a = l;
    tree[v].b = r;
    tree[v].h = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

void insert(int v, int l, int r, int x) {
    if (l > tree[v].b || r < tree[v].a)
        return;
    if (l <= tree[v].a && r >= tree[v].b) {
        tree[v].h = x;
        return;
    }
    if (tree[v].h > 0) {
        tree[v << 1].h = tree[(v << 1) | 1].h = tree[v].h;
        tree[v].h = -1;
    }
    insert(v << 1, l, r, x);
    insert((v << 1) | 1, l, r, x);
    if (tree[v << 1].h == tree[(v << 1) | 1].h)
        tree[v].h = tree[v << 1].h;
}

void calc(int v) {
    if (tree[v].h > 0) {
        ans += tree[v].h * (long long)(b[tree[v].b + 1] - b[tree[v].a]);
        return;
    }
    if (tree[v].a == tree[v].b)
        return;
    calc(v << 1);
    calc((v << 1) + 1);
}