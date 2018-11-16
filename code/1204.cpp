// 1204.cpp
#include <iostream>

int const Maxn = 200005;

struct segment_tree {
    int a, b;
    int sum;
} tree[4 * Maxn + 5];

void build(int v, int l, int r);
void insert(int v, int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int l, r, n, d;
    std::cin >> l >> r >> n;
    d = -l;
    build(1, l + d, r + d - 1);
    for (int i = 1, bl, br; i <= n; i++) {
        std::cin >> bl >> br;
        insert(1, bl + d, br + d - 1);
    }
    std::cout << tree[1].sum << '\n';
    return 0;
}

void build(int v, int l, int r) {
    tree[v].a = l;
    tree[v].b = r;
    tree[v].sum = 0;
    if(l == r)
        return;
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

void insert(int v, int l, int r) {
    if (l > tree[v].b || r < tree[v].a)
        return;
    if (l <= tree[v].a && r >= tree[v].b) {
        tree[v].sum = tree[v].b - tree[v].a + 1;
        return;
    }
    if (tree[v].sum == tree[v].b - tree[v].a + 1)
        return;
    if (tree[v << 1].sum < tree[v << 1].b - tree[v << 1].a + 1)
        insert(v << 1, l, r);
    if (tree[(v << 1) | 1].sum < tree[(v << 1) | 1].b - tree[(v << 1) | 1].a + 1)
        insert((v << 1) | 1, l, r);
    tree[v].sum = tree[v << 1].sum + tree[(v << 1) | 1].sum;
}