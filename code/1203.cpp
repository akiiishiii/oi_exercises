// 1203.cpp
#include <iostream>

int const Maxn = 60005;

struct segment_tree {
    int a, b;
    int c, min;
} tree[4 * Maxn + 5];

int c, s, r, minn, dl, dr, dn;

void build(int v, int l, int r);
void pushdown(int v);
void search(int v, int l, int r);
void modify(int v, int l, int r);

int main(int argc, const char * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> c >> s >> r;
    build(1, 1, c);
    for (int i = 1; i <= r; i++) {
        std::cin >> dl >> dr >> dn;
        minn = 0x3f3f3f3f;
        search(1, dl, --dr);
        if (minn >= dn)
            std::cout << "YES\n", modify(1, dl, dr);
        else
            std::cout << "NO\n";
    }
    return 0;
}

void build(int v, int l, int r) {
    tree[v].a = l;
    tree[v].b = r;
    tree[v].min = s;
    tree[v].c = 0;
    if(l == r)
        return;
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

void pushdown(int v) {
    if (tree[v].c > 0) {
        tree[v << 1].min -= tree[v].c;
        tree[(v << 1) | 1].min -= tree[v].c;
        tree[v << 1].c += tree[v].c;
        tree[(v << 1) | 1].c += tree[v].c;
        tree[v].c = 0;
    }
}

void search(int v, int l, int r) {
    if (l > tree[v].b || r < tree[v].a)
        return;
    if (l <= tree[v].a && r >= tree[v].b) {
        minn = std::min(minn, tree[v].min);
        return;
    }
    pushdown(v);
    search(v << 1, l, r);
    search((v << 1) | 1, l, r);
    tree[v].min = std::min(tree[v << 1].min, tree[(v << 1) | 1].min);
}

void modify(int v, int l, int r) {
    if (l > tree[v].b || r < tree[v].a)
        return;
    if (l <= tree[v].a && r >= tree[v].b) {
        tree[v].min -= dn;
        tree[v].c += dn;
        return;
    }
    pushdown(v);
    modify(v << 1, l, r);
    modify((v << 1) | 1, l, r);
    tree[v].min = std::min(tree[v << 1].min, tree[(v << 1) | 1].min);
}