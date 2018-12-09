// 4295.cpp
#include <iostream>

int const Maxn = 100010;

struct splay_tree {
    int l, r;
    int prt, sum;
    int maxx, val, size, add, rev;
} tree[Maxn];

int a[Maxn], root, n, m;

void pushup(int x);
void pushdown(int x);
void zag(int x);
void zig(int x);
void splay(int x, int prt);
int query(int x);
void reverse(int l, int r);
int getmax(int l, int r);
int getkth(int k);
int getsum(int l, int r);
void add(int k, int val);
int build(int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 0; i <= n + 2; i++) {
        tree[i].sum = tree[i].val = tree[i].maxx = a[i];
        tree[i].add = tree[i].l = tree[i].r = tree[i].rev = tree[i].prt = 0;
        tree[i].size = 1;
    }
    root = build(1, n + 1);
    tree[root].prt = 0;
    tree[0].prt = 0;
    tree[0].r = root;
    tree[0].size = 0;
    for (int i = 1, order, x, y; i <= m; i++) {
        std::cin >> order >> x;
        if (order != 1)
            std::cin >> y;
        switch (order) {
        case 1:
            std::cout << getkth(x) << '\n';
            break;
        case 2:
            add(x, y);
            break;
        case 3:
            std::cout << getsum(x, y) << '\n';
            break;
        case 4:
            std::cout << getmax(x, y) << '\n';
            break;
        case 5:
            reverse(x, y);
            break;
        default:
            break;
        }
    }
    return 0;
}

void pushup(int x) {
    tree[x].sum = tree[x].maxx = tree[x].val;
    tree[x].size = 1;
    if (tree[x].l) {
        tree[x].maxx = std::max(tree[x].maxx, tree[tree[x].l].maxx);
        tree[x].size += tree[tree[x].l].size;
        tree[x].sum += tree[tree[x].l].sum;
    }
    if (tree[x].r) {
        tree[x].maxx = std::max(tree[x].maxx, tree[tree[x].r].maxx);
        tree[x].size += tree[tree[x].r].size;
        tree[x].sum += tree[tree[x].r].sum;
    }
}

void pushdown(int x) {
    if (x) {
        if (tree[x].add) {
            if (tree[x].l) {
                tree[tree[x].l].val += tree[x].add;
                tree[tree[x].l].maxx += tree[x].add;
                tree[tree[x].l].sum += tree[x].add * tree[tree[x].l].size;
                tree[tree[x].l].add += tree[x].add;
            }
            if (tree[x].r) {
                tree[tree[x].r].val += tree[x].add;
                tree[tree[x].r].maxx += tree[x].add;
                tree[tree[x].r].sum += tree[x].add * tree[tree[x].r].size;
                tree[tree[x].r].add += tree[x].add;
            }
            tree[x].add = 0;
        }
        if (tree[x].rev) {
            if (tree[x].l)
                tree[tree[x].l].rev = 1 - tree[tree[x].l].rev;
            if (tree[x].r)
                tree[tree[x].r].rev = 1 - tree[tree[x].r].rev;
            std::swap(tree[x].l, tree[x].r);
            tree[x].rev = 0;
        }
    }
}

void zag(int x) {
    int p = tree[x].prt;
    tree[p].r = tree[x].l;
    if (tree[x].l)
        tree[tree[x].l].prt = p;
    tree[x].prt = tree[p].prt;
    if (tree[p].prt) {
        if (p == tree[tree[p].prt].l)
            tree[tree[p].prt].l = x;
        else
            tree[tree[p].prt].r = x;
    }
    tree[x].l = p;
    tree[p].prt = x;
    pushup(p);
}

void zig(int x) {
    int p = tree[x].prt;
    tree[p].l = tree[x].r;
    if (tree[x].r)
        tree[tree[x].r].prt = p;
    tree[x].prt = tree[p].prt;
    if (tree[p].prt) {
        if (p == tree[tree[p].prt].l)
            tree[tree[p].prt].l = x;
        else
            tree[tree[p].prt].r = x;
    }
    tree[x].r = p;
    tree[p].prt = x;
    pushup(p);
}

void splay(int x, int prt) {
    int p;
    if (x == prt)
        return;
    while (tree[x].prt != prt) {
        p = tree[x].prt;
        pushdown(tree[p].prt);
        pushdown(p);
        pushdown(x);
        if (tree[p].prt == prt) {
            if (x == tree[p].l)
                zig(x);
            else
                zag(x);
            break;
        }
        if (x == tree[p].l) {
            if (p == tree[tree[p].prt].l) {
                zig(p);
                zig(x);
            } else {
                zig(x);
                zag(x);
            }
        } else {
            if (p == tree[tree[p].prt].r) {
                zag(p);
                zag(x);
            } else {
                zag(x);
                zig(x);
            }
        }
    }
    pushup(x);
    if (!prt)
        root = x;
}

int query(int x) {
    int p = root;
    pushdown(p);
    if (!x)
        return 0;
    while (tree[tree[p].l].size != x - 1) {
        if (x <= tree[tree[p].l].size)
            p = tree[p].l;
        else {
            x -= tree[tree[p].l].size + 1;
            p = tree[p].r;
        }
        pushdown(p);
    }
    return p;
}

void reverse(int l, int r) {
    int u = query(l - 1), v = query(r + 1);
    splay(u, 0);
    splay(v, u);
    tree[tree[v].l].rev = 1 - tree[tree[v].l].rev;
}

int getmax(int l, int r) {
    int u = query(l - 1), v = query(r + 1);
    splay(u, 0);
    splay(v, u);
    return tree[tree[v].l].maxx;
}

int getkth(int k) {
    int u = query(k);
    return tree[u].val;
}

int getsum(int l, int r) {
    int u = query(l - 1), v = query(r + 1);
    splay(u, 0);
    splay(v, u);
    return tree[tree[v].l].sum;
}

void add(int k, int val) {
    int u = query(k - 1), v = query(k + 1);
    splay(u, 0);
    splay(v, u);
    tree[tree[v].l].maxx += val;
    tree[tree[v].l].val += val;
    tree[tree[v].l].add += val;
    tree[tree[v].l].sum += val * tree[tree[v].l].size;
}

int build(int l, int r) {
    if (l > r)
        return 0;
    if (l == r)
        return l;
    int mid = (l + r) >> 1, lc, rc;
    lc = tree[mid].l = build(l, mid - 1);
    rc = tree[mid].r = build(mid + 1, r);
    tree[lc].prt = tree[rc].prt = mid;
    pushup(mid);
    return mid;
}