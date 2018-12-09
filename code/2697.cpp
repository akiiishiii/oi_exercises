// 2697.cpp
#include <cstring>
#include <string>
#include <iostream>

int const SIZE = 100010;

struct segment_tree {
    int l, r;
    int max, min, negate;
} tree[SIZE * 3];

int head[SIZE], Next[SIZE << 1], ver[SIZE << 1];
int top[SIZE], prt[SIZE], depth[SIZE], num[SIZE], p[SIZE], fp[SIZE], son[SIZE];
int mat[SIZE][3];
int tot, cnt;

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs1(int x, int p, int d);
void dfs2(int x, int t);
void build(int i, int l, int r);
void pushup(int i);
void pushdown(int i);
void update(int i, int k, int val);
void nupdate(int i, int l, int r);
int query(int i, int l, int r);
int find(int x, int y);
void negate(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 0; i < n - 1; i++) {
        std::cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
        add(mat[i][0], mat[i][1]), add(mat[i][1], mat[i][0]);
    }
    dfs1(1, 0, 0);
    dfs2(1, 1);
    build(1, 0, cnt - 1);
    for (int i = 0; i < n - 1; i++) {
        if (depth[mat[i][0]] > depth[mat[i][1]])
            std::swap(mat[i][0], mat[i][1]);
        update(1, p[mat[i][1]], mat[i][2]);
    }
    std::string op;
    int x, y;
    while (std::cin >> op) {
        if (op[0] == 'D')
            break;
        std::cin >> x >> y;
        if (op[0] == 'Q')
            std::cout << find(x, y) << '\n';
        else if (op[0] == 'N')
            negate(x, y);
        else
            update(1, p[mat[x - 1][1]], y);
    }
    return 0;
}

void dfs1(int x, int p, int d) {
    depth[x] = d;
    prt[x] = p;
    num[x] = 1;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y != p) {
            dfs1(y, x, d + 1);
            num[x] += num[y];
            if (son[x] == -1 || num[y] > num[son[x]])
                son[x] = y;
        }
    }
}

void dfs2(int x, int t) {
    top[x] = t;
    p[x] = cnt++;
    fp[p[x]] = x;
    if (!son[x])
        return;
    dfs2(son[x], t);
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y != son[x] && y != prt[x])
            dfs2(y, y);
    }
}

void build(int i, int l, int r) {
    tree[i].l = l;
    tree[i].r = r;
    tree[i].max = tree[i].min = tree[i].negate = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build((i << 1) | 1, mid + 1, r);
}

void pushup(int i) {
    tree[i].min = std::min(tree[i << 1].min, tree[(i << 1) | 1].min);
    tree[i].max = std::max(tree[i << 1].max, tree[(i << 1) | 1].max);
}

void pushdown(int i) {
    if (tree[i].l == tree[i].r)
        return;
    if (tree[i].negate) {
        tree[i << 1].max = -tree[i << 1].max;
        tree[i << 1].min = -tree[i << 1].min;
        std::swap(tree[i << 1].max, tree[i << 1].min);
        tree[(i << 1) | 1].max = -tree[(i << 1) | 1].max;
        tree[(i << 1) | 1].min = -tree[(i << 1) | 1].min;
        std::swap(tree[(i << 1) | 1].max, tree[(i << 1) | 1].min);
        tree[i << 1].negate ^= 1;
        tree[(i << 1) | 1].negate ^= 1;
        tree[i].negate = 0;
    }
}

void update(int i, int k, int val) {
    if (tree[i].l == k && tree[i].r == k) {
        tree[i].max = tree[i].min = val;
        tree[i].negate = 0;
        return;
    }
    pushdown(i);
    int mid = (tree[i].l + tree[i].r) >> 1;
    if (k <= mid)
        update(i << 1, k, val);
    else
        update((i << 1) | 1, k, val);
    pushup(i);
}

void nupdate(int i, int l, int r) {
    if (tree[i].l == l && tree[i].r == r) {
        tree[i].max = -tree[i].max;
        tree[i].min = -tree[i].min;
        std::swap(tree[i].max, tree[i].min);
        tree[i].negate ^= 1;
        return;
    }
    pushdown(i);
    int mid = (tree[i].l + tree[i].r) >> 1;
    if (r <= mid)
        nupdate(i << 1, l, r);
    else if (l > mid)
        nupdate((i << 1) | 1, l, r);
    else {
        nupdate(i << 1, l, mid);
        nupdate((i << 1) | 1, mid + 1, r);
    }
    pushup(i);
}

int query(int i, int l, int r) {
    if (tree[i].l == l && tree[i].r == r)
        return tree[i].max;
    pushdown(i);
    int mid = (tree[i].l + tree[i].r) >> 1;
    if (r <= mid)
        return query(i << 1, l, r);
    else if (l > mid)
        return query((i << 1) | 1, l, r);
    else
        return std::max(query(i << 1, l, mid), query((i << 1) | 1, mid + 1, r));
    pushup(i);
}

int find(int x, int y) {
    int f1 = top[x], f2 = top[y], tmp = -100000000;
    while (f1 != f2) {
        if (depth[f1] < depth[f2]) {
            std::swap(f1, f2);
            std::swap(x, y);
        }
        tmp = std::max(tmp, query(1, p[f1], p[x]));
        x = prt[f1];
        f1 = top[x];
    }
    if (x == y)
        return tmp;
    if (depth[x] > depth[y])
        std::swap(x, y);
    return std::max(tmp, query(1, p[son[x]], p[y]));
}

void negate(int x, int y) {
    int f1 = top[x], f2 = top[y];
    while (f1 != f2) {
        if (depth[f1] < depth[f2]) {
            std::swap(f1, f2);
            std::swap(x, y);
        }
        nupdate(1, p[f1], p[x]);
        x = prt[f1];
        f1 = top[x];
    }
    if (x == y)
        return;
    if (depth[x] > depth[y])
        std::swap(x, y);
    return nupdate(1, p[son[x]], p[y]);
}