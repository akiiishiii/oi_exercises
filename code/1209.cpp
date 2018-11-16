// 1209.cpp
#include <algorithm>
#include <iostream>

int const Maxn = 40005;

struct rectangle {
    int s, t, h;
} a[Maxn];

struct segment_tree {
    int a, b;
    int h;
} tree[Maxn * 6];

int b[Maxn << 1];

void build(int v, int l, int r);
void insert(int v, int r, int l, int x);

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].s >> a[i].t >> a[i].h;
        b[i] = a[i].s;
        b[i + n] = a[i].t;
    }
    std::sort(b + 1, b + 2 * n + 1);
    int tot = std::unique(b + 1, b + 2 * n + 1) - b - 1;
    for (int i = 1; i <= n; i++) {
        a[i].s = std::lower_bound(b + 1, b + tot + 1, a[i].s) - b;
        a[i].t = std::lower_bound(b + 1, b + tot + 1, a[i].t) - b;
    }

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

void insert(int v, int r, int l, int x) {
    if (l > tree[v].b || r < tree[v].a || x <= tree[v].h)
        return;
    if (l <= tree[v].a || r >= tree[v].b) {
        tree[v].h = x;
        return;
    }
    if (tree[v].h > 0) {
        tree[v << 1].h = tree[(v << 1) | 1].h = tree[v].h;
        tree[v].h = -1;
    }
    insert(v << 1, l, r, x);
}