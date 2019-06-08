// 2382.cpp
#include <iostream>

int const Maxn = 50100;
int n, num, root, x, m, now;
int a[Maxn], b[Maxn];

struct Node {
    int lc, rc;
    int v, fix;
    int size, cnt;
} tree[Maxn];

void update(int i);
void zig(int &i);
void zag(int &i);
void insert(int &i, int x);
int query(int i, int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= m; i++)
        std::cin >> x, b[x]++;
    for (int i = 1; i <= n; i++) {
        insert(root, a[i]);
        while (b[i]--)
            std::cout << query(root, ++now) << '\n';
    }
    return 0;
}

void update(int i) {
    tree[i].size = tree[tree[i].lc].size + tree[tree[i].rc].size + tree[i].cnt;
}

void zig(int &i) {
    int t = tree[i].rc;
    tree[i].rc = tree[t].lc;
    tree[t].lc = i;
    tree[t].size = tree[i].size;
    update(i);
    i = t;
}

void zag(int &i) {
    int t = tree[i].lc;
    tree[i].lc = tree[t].rc;
    tree[t].rc = i;
    tree[t].size = tree[i].size;
    update(i);
    i = t;
}

void insert(int &i, int x) {
    if (i == 0) {
        num++;
        i = num;
        tree[i].v = x;
        tree[i].size = tree[i].cnt = 1;
        tree[i].fix = rand();
        return;
    }
    tree[i].size++;
    if (tree[i].v == x)
        tree[i].cnt++;
    if (x < tree[i].v) {
        insert(tree[i].lc, x);
        if (tree[tree[i].lc].fix < tree[i].fix)
            zag(i);
    }
    if (x > tree[i].v) {
        insert(tree[i].rc, x);
        if (tree[tree[i].rc].fix < tree[i].fix)
            zig(i);
    }
}

int query(int i, int x) {
    if (i == 0)
        return 0;
    if (x <= tree[tree[i].lc].size)
        return query(tree[i].lc, x);
    if (x > tree[tree[i].lc].size + tree[i].cnt)
        return query(tree[i].rc, x - tree[tree[i].lc].size - tree[i].cnt);
    else
        return tree[i].v;
}