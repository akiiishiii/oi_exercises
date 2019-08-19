// tree.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("tree.in");
std::ofstream out("tree.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 100010;

struct segment_tree {
    int l, r;
    int sum, add;
} tree[Maxn * 3];

int head[Maxn], Next[Maxn << 1], ver[Maxn << 1];
int top[Maxn], prt[Maxn], dep[Maxn], siz[Maxn], p[Maxn], fp[Maxn], son[Maxn];
int tot, n, q, cnt;
bool found = false;
long long pt[Maxn];

inline void add(int u, int v);
void dfs1(int u, int pre, int d);
void dfs2(int u, int sp);
void build(int v, int l, int r);
void add(int v, int k, int val);
void add(int v, int l, int r, int val);
void pushup(int v, int l, int r);
int query(int v, int l, int r, int add);
int lca(int u, int v);
void dfsadd(int x, int p, int d);
inline long long sum(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int com, x, y;
    in >> n >> q;
    for (int i = 1; i <= n; i++)
        in >> pt[i];
    for (int i = 1; i <= n - 1; i++) {
        in >> x >> y;
        add(x, y), add(y, x);
    }
    dfs1(1, 0, 0);
    /*if (n <= 1000) {
        while (q--) {
            in >> com >> x;
            if (com == 1) {
                in >> y;
                pt[x] += y;
            } else if (com == 2) {
                in >> y;
                dfsadd(x, prt[x], y);
            } else
                out << sum(x) << '\n';
        }
    } else {*/
    dfs2(1, 1);
    build(1, 1, cnt - 1);
    for (int i = 1; i <= n; i++)
        add(1, p[i], pt[i]);
    while (q--) {
        in >> com >> x;
        if (com == 1) {
            in >> y;
            add(1, p[x], y);
        } else if (com == 2) {
            add(1, 1, p[x], y);
        } else {
            found = false;
            out << query(1, 1, p[x], 0) << '\n';
        }
        //}
    }
    return 0;
}

inline void add(int u, int v) {
    ver[++tot] = v, Next[tot] = head[u], head[u] = tot;
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
    tree[v].sum = tree[v].add = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

void add(int v, int k, int val) {
    if (k < tree[v].l || k > tree[v].r)
        return;
    if (k == tree[v].l && k == tree[v].r) {
        tree[v].sum += val;
        return;
    }
    add(v << 1, k, val);
    add((v << 1) | 1, k, val);
    tree[v].sum = tree[v << 1].sum + tree[(v << 1) | 1].sum;
}

void add(int v, int l, int r, int val) {
    if (l > tree[v].r || r < tree[v].l)
        return;
    if (l <= tree[v].l && r >= tree[v].r) {
        tree[v].add += val;
        return;
    }
    add(v << 1, l, r, val);
    add((v << 1) | 1, l, r, val);
    pushup(v, l, r);
}

void pushup(int v, int l, int r) {
    if (r > l)
        tree[v].sum = tree[v << 1].sum + tree[(v << 1) | 1].sum;
    tree[v].sum += tree[v].add * (r - l + 1);
}

int query(int v, int l, int r, int add) {
    if (l > tree[v].r || r < tree[v].l)
        return -(1 << 30);
    if (l <= tree[v].l && r >= tree[v].r)
        return tree[v].sum + add * (r - l + 1);
    return query(v << 1, l, r, add + tree[v].add) +
           query((v << 1) | 1, l, r, add + tree[v].add);
}

int lca(int u, int v) {
    int f1 = top[u], f2 = top[v], tmp = 0;
    while (f1 != f2) {
        if (dep[f1] < dep[f2])
            std::swap(f1, f2), std::swap(u, v);
        tmp = std::max(tmp, query(1, p[f1], p[u], 0));
        u = prt[f1], f1 = top[u];
    }
    if (u == v)
        return tmp;
    if (dep[u] > dep[v])
        std::swap(u, v);
    return std::max(tmp, query(1, p[son[u]], p[v], 0));
}

void dfsadd(int x, int p, int d) {
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        dfsadd(y, x, d);
    }
    pt[x] += d;
}

inline long long sum(int x) {
    long long ret = 0;
    while (x != 1) {
        ret += pt[x];
        x = prt[x];
    }
    return ret + pt[1];
}