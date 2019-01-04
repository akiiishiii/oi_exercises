// 4530.cpp
#include <iostream>

int const Maxn = 1000010;
int n, q, m, cnt;
int a[Maxn], rts[Maxn * 20];

struct arr {
    int lc, rc;
    int val;
} tree[Maxn * 20];

void build(int &root, int l, int r);
void insert(int &root, int pre, int l, int r, int q, int v);
int query(int root, int l, int r, int q);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    build(rts[0], 1, n);
    for (int i = 1, op, x, pre, v; i <= m; i++) {
        std::cin >> op >> pre >> x;
        if (op == 1) {
            std::cin >> v;
            insert(rts[i], rts[pre], 1, n, x, v);
        }
        if (op == 2) {
            std::cout << query(rts[pre], 1, n, x) << "\n";
            rts[i] = rts[pre];
        }
    }
    return 0;
}

void build(int &root, int l, int r) {
    root = ++cnt;
    if (l == r) {
        tree[root].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(tree[root].lc, l, mid);
    build(tree[root].rc, mid + 1, r);
}

void insert(int &root, int pre, int l, int r, int q, int v) {
    root = ++cnt;
    tree[root].lc = tree[pre].lc;
    tree[root].rc = tree[pre].rc;
    tree[root].val = tree[pre].val;
    if (l == r) {
        tree[root].val = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (q <= mid)
        insert(tree[root].lc, tree[pre].lc, l, mid, q, v);
    else
        insert(tree[root].rc, tree[pre].rc, mid + 1, r, q, v);
}

int query(int root, int l, int r, int q) {
    if (l == r)
        return tree[root].val;
    int mid = (l + r) >> 1;
    if (q <= mid)
        return query(tree[root].lc, l, mid, q);
    else
        return query(tree[root].rc, mid + 1, r, q);
}