// 1202.cpp
#include <iostream>

int const Maxn = 100005;

struct segment_tree {
    int a, b;
    int sum, delta;
} tree[4 * Maxn + 5];

void build(int v, int l, int r);
void paint(int d, int v, int l, int r);
void pushdown(int v);

int main(int argc, const char * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    build(1, 1, n);
    for (int k = 1, i, a, b; k <= m; k++) {
        std::cin >> i >> a >> b;
        b--;
        paint(i == 1 ? 1 : -1, 1, a, b);
    }
    std::cout << tree[1].sum << '\n';
    return 0;
}

void build(int v, int l, int r) {
    tree[v].a = l;
    tree[v].b = r;
    tree[v].sum = tree[v].delta = 0;
    if(l == r)
        return;
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

void paint(int d, int v, int l, int r) {
    if(tree[v].a > r || tree[v].b < l)
        return;
    if(tree[v].delta == d)
        return;
    if(tree[v].a >= l && tree[v].b <= r) {
        tree[v].delta = d;
        tree[v].sum = tree[v].b - tree[v].a + 1;
        if(d == -1)
            tree[v].sum = 0;
        return;
    }
    pushdown(v);
    paint(d, v << 1, l, r);
    paint(d, (v << 1) | 1, l, r);
    tree[v].sum = tree[v << 1].sum + tree[(v << 1) | 1].sum;
}

void pushdown(int v) {
    if(tree[v].delta == -1) {
        tree[v << 1].delta = tree[(v << 1) | 1].delta = -1;
        tree[v << 1].sum = tree[(v << 1) | 1].sum = 0;
        tree[v].delta = 0;
    } else if(tree[v].delta == 1) {
        tree[v << 1].delta = tree[(v << 1) | 1].delta = 1;
        tree[v << 1].sum = tree[v << 1].b - tree[v << 1].a + 1;
        tree[(v << 1) | 1].sum = tree[(v << 1) | 1].b - tree[(v << 1) | 1].a + 1;
        tree[v].delta = 0;
    }
}