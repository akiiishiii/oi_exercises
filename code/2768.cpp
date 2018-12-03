// 2768.cpp
#include <iostream>
#include <algorithm>

int const SIZE = 160010;

struct edge {
    int x, y, w;
} e[SIZE << 1];

struct segment_tree {
    int l, r;
    int maxx;
} tree[SIZE * 3];

int head[SIZE], Next[SIZE << 1], ver[SIZE << 1];
int top[SIZE], prt[SIZE], dep[SIZE], siz[SIZE], p[SIZE], fp[SIZE], son[SIZE];
int tot, n, q, cnt;

inline void add(int u, int v) { ver[++tot] = v, Next[tot] = head[u], head[u] = tot; }
void dfs1(int u, int pre, int d);
void dfs2(int u, int sp);
void build(int v, int l, int r);
void insert(int v, int k, int val);
int query(int v, int l, int r);
int lca(int u, int v);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> q;
    for (int i = 1; i <= n - 1; i++) {
        std::cin >> e[i].x >> e[i].y >> e[i].w;
        add(e[i].x, e[i].y), add(e[i].y, e[i].x);
    }
    dfs1(1, 0, 0);
    dfs2(1, 1);
    build(1, 1, cnt - 1);
    for (int i = 1; i < n; i++) {
        if (dep[e[i].x] < dep[e[i].y])
            std::swap(e[i].x, e[i].y);
        insert(1, p[e[i].x], e[i].w);
    }
    for (int i = 1, k, u, v; i <= q; i++) {
        std::cin >> k >> u >> v;
        if (!k)
            insert(1, p[e[u].x], v);
        if (k == 1)
            std::cout << ((u == v) ? -1 : lca(u, v)) << '\n';
    }
    return 0;
}

void dfs1(int u, int pre, int d) {
    dep[u] = d;
    prt[u] = pre;
    siz[u] = 1;
    for (int i = head[u]; i; i = Next[i]) {
        int v = ver[i];
        if (v != pre) {
            dfs1(v, u, d + 1);
            siz[u] += siz[v];
            if (!son[u] || siz[v] > siz[son[u]])
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
        if (v != son[u] && v != prt[u])
            dfs2(v, v);
    }
}

void build(int v, int l, int r) {
    tree[v].l = l, tree[v].r = r;
    tree[v].maxx = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

void insert(int v, int k, int val) {
    if (k < tree[v].l || k > tree[v].r)
        return;
    if (k == tree[v].l && k == tree[v].r) {
        tree[v].maxx = val;
        return;
    }
    insert(v << 1, k, val);
    insert((v << 1) | 1, k, val);
    tree[v].maxx = std::max(tree[v << 1].maxx, tree[(v << 1) | 1].maxx);
}

int query(int v, int l, int r) {
    if (l > tree[v].r || r < tree[v].l)
        return -(1 << 30);
    if (l <= tree[v].l && r >= tree[v].r)
        return tree[v].maxx;
    return std::max(query(v << 1, l, r), query((v << 1) | 1, l, r));
}

int lca(int u, int v) {
    int f1 = top[u], f2 = top[v], tmp = 0;
    while (f1 != f2) {
        if (dep[f1] < dep[f2])
            std::swap(f1, f2), std::swap(u, v);
        tmp = std::max(tmp, query(1, p[f1], p[u]));
        u = prt[f1], f1 = top[u];
    }
    if (u == v)
        return tmp;
    if (dep[u] > dep[v])
        std::swap(u, v);
    return std::max(tmp, query(1, p[son[u]], p[v]));
}