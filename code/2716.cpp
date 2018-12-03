// 1716.cpp
#include <algorithm>
#include <iostream>
#include <string>

int const SIZE = 30010;

struct segment_tree {
    int l, r;
    int sum;
    int maxx;
} tree[SIZE * 3];

int head[SIZE], Next[SIZE << 1], ver[SIZE << 1];
int top[SIZE], fa[SIZE], deep[SIZE], num[SIZE], p[SIZE], fp[SIZE], son[SIZE],
    s[SIZE];
int tot, cnt;

inline void add(int u, int v) {
    ver[++tot] = v, Next[tot] = head[u], head[u] = tot;
}
void dfs1(int u, int pre, int d);
void dfs2(int u, int sp);
void pushup(int i);
void build(int i, int l, int r);
void update(int i, int k, int val);
int query_max(int i, int l, int r);
int query_sum(int i, int l, int r);
int find_max(int u, int v);
int find_sum(int u, int v);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, q, u, v;
    std::string op;
    std::cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        std::cin >> u >> v;
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= n; i++)
        std::cin >> s[i];
    dfs1(1, 0, 0);
    dfs2(1, 1);
    build(1, 0, cnt - 1);
    std::cin >> q;
    for (int i = 1; i <= q; i++) {
        std::cin >> op >> u >> v;
        if (op[0] == 'C')
            update(1, p[u], v);
        else if (op == "QMAX")
            std::cout << find_max(u, v) << '\n';
        else
            std::cout << find_sum(u, v) << '\n';
    }
    return 0;
}

void dfs1(int u, int pre, int d) {
    deep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for (int i = head[u]; i; i = Next[i]) {
        int v = ver[i];
        if (v != pre) {
            dfs1(v, u, d + 1);
            num[u] += num[v];
            if (son[u] == -1 || num[v] > num[son[u]])
                son[u] = v;
        }
    }
}

void dfs2(int u, int sp) {
    top[u] = sp;
    p[u] = cnt++;
    fp[p[u]] = u;
    if (son[u])
        dfs2(son[u], sp);
    for (int i = head[u]; i; i = Next[i]) {
        int v = ver[i];
        if (v != son[u] && v != fa[u])
            dfs2(v, v);
    }
}

void pushup(int i) {
    tree[i].sum = tree[i << 1].sum + tree[(i << 1) | 1].sum;
    tree[i].maxx = std::max(tree[i << 1].maxx, tree[(i << 1) | 1].maxx);
}

void build(int i, int l, int r) {
    tree[i].l = l;
    tree[i].r = r;
    if (l == r) {
        tree[i].sum = tree[i].maxx = s[fp[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build((i << 1) | 1, mid + 1, r);
    pushup(i);
}

void update(int i, int k, int val) {
    if (tree[i].l == k && tree[i].r == k) {
        tree[i].sum = tree[i].maxx = val;
        return;
    }
    int mid = (tree[i].l + tree[i].r) >> 1;
    if (k <= mid)
        update(i << 1, k, val);
    else
        update((i << 1) | 1, k, val);
    pushup(i);
}

int query_max(int i, int l, int r) {
    if (tree[i].l == l && tree[i].r == r)
        return tree[i].maxx;
    int mid = (tree[i].l + tree[i].r) >> 1;
    if (r <= mid)
        return query_max(i << 1, l, r);
    else if (l > mid)
        return query_max((i << 1) | 1, l, r);
    else
        return std::max(query_max(i << 1, l, mid),
                        query_max((i << 1) | 1, mid + 1, r));
}

int query_sum(int i, int l, int r) {
    if (tree[i].l == l && tree[i].r == r)
        return tree[i].sum;
    int mid = (tree[i].l + tree[i].r) >> 1;
    if (r <= mid)
        return query_sum(i << 1, l, r);
    else if (l > mid)
        return query_sum((i << 1) | 1, l, r);
    else
        return query_sum(i << 1, l, mid) + query_sum((i << 1) | 1, mid + 1, r);
}

int find_max(int u, int v) {
    int f1 = top[u], f2 = top[v];
    int tmp = -1000000000;
    while (f1 != f2) {
        if (deep[f1] < deep[f2]) {
            std::swap(f1, f2), std::swap(u, v);
        }
        tmp = std::max(tmp, query_max(1, p[f1], p[u]));
        u = fa[f1];
        f1 = top[u];
    }
    if (deep[u] > deep[v])
        std::swap(u, v);
    return std::max(tmp, query_max(1, p[u], p[v]));
}

int find_sum(int u, int v) {
    int f1 = top[u], f2 = top[v];
    int tmp = 0;
    while (f1 != f2) {
        if (deep[f1] < deep[f2]) {
            std::swap(f1, f2);
            std::swap(u, v);
        }
        tmp += query_sum(1, p[f1], p[u]);
        u = fa[f1];
        f1 = top[u];
    }
    if (deep[u] > deep[v])
        std::swap(u, v);
    return tmp + query_sum(1, p[u], p[v]);
}