// segmenttree.cpp
#include <iostream>

const int MAXN = 100005;
struct SegmentTree {
    int a, b, c;
} tree[4 * MAXN + 5];

void build(int v, int l, int r) {
    int mid;
    tree[v].a = l;
    tree[v].b = r;
    tree[v].c = 0;
    if (l==r)
        return;
    mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
}

void add(int v, int x, int d) {
    if (x < tree[v].a || x > tree[v].b)
        return;
    if (x >= tree[v].a && x <= tree[v].b)
        tree[v].sum
}