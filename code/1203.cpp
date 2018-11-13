// 1203.cpp
#include <iostream>

int const Maxn = 100005;

struct segment_tree {
    int a, b;
    int sum, delta;
} tree[4 * Maxn + 5];

void build(int v, int l, int r);

void pushdown(int v);

int main(int argc, const char * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int c, s, r;
    std::cin >> c >> s >> r;

    build(1, 1, c);
    for (int i = 1; i <= r; i++) {

    }
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