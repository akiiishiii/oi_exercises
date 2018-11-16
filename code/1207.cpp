// 1207.cpp
#include <iostream>

int const Maxn = 200005;

struct segment_tree {
    int a, b;
    int cnt;
} tree[4 * Maxn + 5];

int ans = 0;

void build(int v, int l, int r);
void insert(int v, int l, int r);
void search(int v, int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int xc, n, p;
    int const D = 100000;
    build(1, 0, 200000);
    std::cin >> xc >> n;
    for (int i = 1, l, r, c; i <= n; i++) {
        std::cin >> l >> r >> c;
        insert(1, l + D, r + D - 1);
    }
    std::cin >> p;
    search(1, p + D, p + D);
    std::cout << ans << '\n';
    return 0;
}

void build(int v, int l, int r) {
    tree[v].a = l;
    tree[v].b = r;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

void insert(int v, int l, int r) {
    if (l > tree[v].b || r < tree[v].a)
        return;
    if (l <= tree[v].a && r >= tree[v].b) {
        tree[v].cnt++;
        return;
    }
    insert(v << 1, l, r);
    insert((v << 1) | 1, l, r);
}

void search(int v, int l, int r) {
    if (l > tree[v].b || r < tree[v].a)
        return;
    ans += tree[v].cnt;
    search(v << 1, l, r);
    search((v << 1) | 1, l, r);
}