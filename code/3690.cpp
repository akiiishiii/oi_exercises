// 3690.cpp
#include <algorithm>
#include <iostream>

int const SIZE = 100005;
int head[SIZE], ver[SIZE << 1], Next[SIZE << 1];
int n, m, tot;
int prt[SIZE], size[SIZE], top[SIZE], num[SIZE], son[SIZE], d[SIZE], cnt = -1;

struct segment_tree {
    int l, r;
    int sum, bj;
} tree[SIZE * 20];

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs1(int x, int p, int depth);
void dfs2(int x, int p);
void build(int x, int l, int r);
void push_down(int x, int val);
void insert(int x, int l, int r);
int query(int x, int l, int r);
void plant(int x, int y);
int ask(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, x, y; i <= n - 1; i++) {
        std::cin >> x >> y;
        add(x, y), add(y, x);
    }
    dfs1(1, 1, 1);
    dfs2(1, 1);
    build(1, 1, n - 1);
    char c;
    for (int i = 1, x, y; i <= m; i++) {
        std ::cin >> c >> x >> y;
        if (c == 'P')
            plant(x, y);
        else
            std::cout << ask(x, y) << '\n';
    }
    return 0;
}

void dfs1(int x, int p, int depth) {
    prt[x] = p;
    size[x] = 1;
    d[x] = depth;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        dfs1(y, x, depth + 1);
        size[x] += size[y];
        if (size[y] > size[son[x]])
            son[x] = y;
    }
}

void dfs2(int x, int p) {
    num[x] = ++cnt;
    if (son[prt[x]] != x)
        top[x] = x;
    else
        top[x] = top[prt[x]];
    if (son[x] != 0)
        dfs2(son[x], x);
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p || y == son[x])
            continue;
        dfs2(y, x);
    }
}

void build(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    tree[x].sum = tree[x].bj = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build((x << 1) | 1, mid + 1, r);
}

void push_down(int x, int val) {
    tree[x].sum += (tree[x].r - tree[x].l + 1) * val;
    tree[x].bj += val;
}

void insert(int x, int l, int r) {
    if (tree[x].l > r || tree[x].r < l)
        return;
    if (tree[x].l >= l && tree[x].r <= r) {
        tree[x].sum += tree[x].r - tree[x].l + 1;
        tree[x].bj++;
        return;
    }
    if (tree[x].bj) {
        push_down(x << 1, tree[x].bj);
        push_down((x << 1) + 1, tree[x].bj);
        tree[x].bj = 0;
    }
    insert(x << 1, l, r);
    insert((x << 1) | 1, l, r);
    tree[x].sum = tree[x << 1].sum + tree[(x << 1) | 1].sum;
}

int query(int x, int l, int r) {
    if (tree[x].l > r || tree[x].r < l)
        return 0;
    if (tree[x].l >= l && tree[x].r <= r)
        return tree[x].sum;
    if (tree[x].bj) {
        push_down(x << 1, tree[x].bj);
        push_down((x << 1) | 1, tree[x].bj);
        tree[x].bj = 0;
    }
    return query(x << 1, l, r) + query((x << 1) | 1, l, r);
}

void plant(int x, int y) {
    while (top[x] != top[y]) {
        if (d[top[x]] < d[top[y]])
            std::swap(x, y);

        insert(1, num[top[x]], num[x]);
        x = prt[top[x]];
    }
    if (d[x] > d[y])
        std::swap(x, y);
    insert(1, num[x] + 1, num[y]);
}

int ask(int x, int y) {
    int ret = 0;
    while (top[x] != top[y]) {
        if (d[top[x]] < d[top[y]])
            std::swap(x, y);
        ret += query(1, num[top[x]], num[x]);
        x = prt[top[x]];
    }
    if (d[x] > d[y])
        std::swap(x, y);

    ret += query(1, num[x] + 1, num[y]);
    return ret;
}