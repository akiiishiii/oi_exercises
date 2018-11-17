// 1210.cpp
#include <iostream>

int const Maxn = 1005;

struct segment_tree2 {
    struct segment_tree {
        int l, r, c;
    } f[Maxn * 4];
    int l, r;
} tree[Maxn * 4];

int x1, x2, y1, y2, n, ans;

void build(int v, int l, int r);
void build(int p, int v, int l, int r);
void add(int v);
void add(int p, int v);
void ask(int v);
void ask(int p, int v);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, t;
    char ch;
    std::cin >> x;
    while (x--) {
        std::cin >> n >> t;
        build(1, 1, n);
        for (int j = 1; j <= t; j++) {
            std::cin >> ch;
            if (ch == 'C') {
                std::cin >> x1 >> y1 >> x2 >> y2;
                add(1);
            } else {
                std::cin >> x1 >> y1;
                ans = 0;
                ask(1);
                std::cout << ans % 2 << '\n';
            }
        }
        std::cout.put('\n');
    }
}

void build(int v, int l, int r) {
    tree[v].l = l;
    tree[v].r = r;
    build(v, 1, 1, n);
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

void build(int p, int v, int l, int r) {
    tree[p].f[v].l = l;
    tree[p].f[v].r = r;
    tree[p].f[v].c = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(p, v << 1, l, mid);
    build(p, (v << 1) | 1, mid + 1, r);
}

void add(int v) {
    if (tree[v].l > x2 || tree[v].r < x1)
        return;
    if (x1 <= tree[v].l && tree[v].r <= x2) {
        add(v, 1);
        return;
    }
    add(v << 1);
    add((v << 1) | 1);
}

void add(int p, int v) {
    if (tree[p].f[v].l > y2 || tree[p].f[v].r < y1)
        return;
    if (y1 <= tree[p].f[v].l && tree[p].f[v].r <= y2) {
        tree[p].f[v].c++;
        return;
    }
    if (tree[p].f[v].l == tree[p].f[v].r)
        return;
    add(p, v << 1);
    add(p, (v << 1) | 1);
}

void ask(int v) {
    if (tree[v].l > x1 || x1 > tree[v].r)
        return;
    if (tree[v].l <= x1 && x1 <= tree[v].r)
        ask(v, 1);
    if (tree[v].l == tree[v].r)
        return;
    int mid = (tree[v].l + tree[v].r) >> 1;
    if (x1 <= mid)
        ask(v << 1);
    else
        ask((v << 1) | 1);
}

void ask(int p, int v) {
    if (tree[p].f[v].l > y1 || y1 > tree[p].f[v].r)
        return;
    if (tree[p].f[v].l <= y1 && y1 <= tree[p].f[v].r)
        ans += tree[p].f[v].c;
    if (tree[p].f[v].l == tree[p].f[v].r)
        return;
    int mid = (tree[p].f[v].l + tree[p].f[v].r) >> 1;
    if (y1 <= mid)
        ask(p, v << 1);
    else
        ask(p, (v << 1) | 1);
}