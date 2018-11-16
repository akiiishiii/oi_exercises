// 1206.cpp
#include <iostream>

int const Maxn = 200005;

struct segment_tree {
    int a, b;
    int cnt;
    int lc, rc, color;
} tree[4 * Maxn + 5];

void build(int v, int l, int r);
void insert(int v, int l, int r, int c);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int xc, n;
    int const D = 100000;
    build(1, 0, 199999);
    std::cin >> xc >> n;
    tree[1].lc = tree[1].rc = tree[1].color = xc;
    tree[1].cnt = 1;
    for (int i = 1, l, r, c; i <= n; i++) {
        std::cin >> l >> r >> c;
        insert(1, l + D, r + D - 1, c);
    }
    std::cout << tree[1].cnt << '\n';
    return 0;
}

void build(int v, int l, int r) {
    tree[v].a = l;
    tree[v].b = r;
    if(l == r)
        return;
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

void insert(int v, int l, int r, int c) {
    if (l > tree[v].b || r < tree[v].a)
        return;
    if (l <= tree[v].a && r >= tree[v].b) {
        tree[v].cnt = 1;
        return;
    }
    if (tree[v].color > 0) {
        tree[v << 1].lc = tree[v << 1].rc = tree[v << 1].color = tree[v].color;
        tree[v << 1 | 1].lc = tree[v << 1 | 1].rc = tree[v << 1 | 1].color = tree[v].color;
        tree[v << 1].cnt = tree[v << 1 | 1].cnt = 1;
        tree[v].color = -1;
    }
    insert(v << 1, l, r, c);
    insert((v << 1) | 1, l, r, c);
    tree[v].lc = tree[v << 1].lc;
    tree[v].rc = tree[(v << 1) | 1].rc;
    tree[v].cnt = tree[v << 1].cnt + tree[(v << 1) | 1].cnt;
    if (tree[v << 1].rc == tree[(v << 1) | 1].lc)
        tree[v].cnt--;
}