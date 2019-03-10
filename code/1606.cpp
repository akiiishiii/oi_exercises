// 1606.cpp 线段树合并 + 树上差分
#include <algorithm>
#include <iostream>
#include <cmath>

int const Maxn = 100005;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1], tot;
int g[Maxn << 1][20], t[Maxn << 1], d[Maxn << 1], f[Maxn << 1], ans[Maxn * 20];
int n, m, sum;

struct segment_tree {
    int l, r, v;
} tree[Maxn * 80];

struct edges {
    int x, y, z;
    bool operator<(edges const &e) const { return z < e.z; }
} e[Maxn];

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs(int x);
int lca(int x, int y);
void update(int v, int l, int r, int x, int y);
void mesh(int l, int r, int x, int y);
int search(int v, int l, int r);
void merge(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, x, y; i < n; i++)
        std::cin >> x >> y, add(x, y), add(y, x);
    d[1] = 1;
    dfs(1);
    for (int j = 1; j <= log2(n); j++)
        for (int i = 1; i <= n; i++)
            g[i][j] = g[g[i][j - 1]][j - 1];
    for (int i = 1; i <= m; i++)
        std::cin >> e[i].x >> e[i].y >> e[i].z;
    std::sort(e + 1, e + m + 1);
    tot = sum = 0;
    for (int i = 1; i <= m; i++) {
        if (e[i].z != t[tot])
            t[++tot] = e[i].z;
        e[i].z = tot;
    }
    for (int i = 1; i <= m; i++) {
        int llca = lca(e[i].x, e[i].y);
        if (!f[e[i].x]) {
            f[e[i].x] = ++sum;
        }
        update(f[e[i].x], 1, tot, e[i].z, 1);
        if (!f[e[i].y]) {
            f[e[i].y] = ++sum;
        }
        update(f[e[i].y], 1, tot, e[i].z, 1);
        if (!f[llca]) {
            f[llca] = ++sum;
        }
        update(f[llca], 1, tot, e[i].z, -1);
        if (g[llca][0]) {
            if (!f[g[llca][0]])
                f[g[llca][0]] = ++sum;
            update(f[g[llca][0]], 1, tot, e[i].z, -1);
        }
    }
    merge(1);
    for (int i = 1; i <= n; i++) {
        if (!f[i])
            f[i] = ++sum;
        std::cout << t[ans[i]] << '\n';
    }
    return 0;
}

void dfs(int x) {
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y != g[x][0]) {
            d[y] = d[x] + 1;
            g[y][0] = x;
            dfs(y);
        }
    }
    return;
}

int lca(int x, int y) {
    if (d[x] > d[y])
        std::swap(x, y);
    for (int i = log2(n); i >= 0; i--)
        if (d[g[y][i]] > d[x])
            y = g[y][i];
    if (d[y] != d[x])
        y = g[y][0];
    for (int i = log2(n); i >= 0; i--)
        if (g[y][i] != g[x][i])
            y = g[y][i], x = g[x][i];
    if (x != y)
        y = g[y][0];
    return y;
}

void update(int v, int l, int r, int x, int y) {
    if (l == r) {
        tree[v].v += y;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        if (!tree[v].l)
            tree[v].l = ++sum;
        update(tree[v].l, l, mid, x, y);
    } else {
        if (!tree[v].r)
            tree[v].r = ++sum;
        update(tree[v].r, mid + 1, r, x, y);
    }
    tree[v].v = std::max(tree[tree[v].l].v, tree[tree[v].r].v);
}

void mesh(int l, int r, int x, int y) {
    if (l == r) {
        tree[x].v += tree[y].v;
        return;
    }
    int mid = (l + r) >> 1;
    if (tree[y].l) {
        if (!tree[x].l)
            tree[x].l = tree[y].l;
        else
            mesh(l, mid, tree[x].l, tree[y].l);
    }
    if (tree[y].r) {
        if (!tree[x].r)
            tree[x].r = tree[y].r;
        else
            mesh(mid + 1, r, tree[x].r, tree[y].r);
    }
    tree[x].v = std::max(tree[tree[x].l].v, tree[tree[x].r].v);
}

int search(int v, int l, int r) {
    if (l == r)
        return l;
    if (!(tree[tree[v].l].v || tree[tree[v].r].v))
        return 0;
    int mid = (l + r) >> 1;
    if (tree[tree[v].l].v >= tree[tree[v].r].v)
        return search(tree[v].l, l, mid);
    else
        return search(tree[v].r, mid + 1, r);
}

void merge(int x) {
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y != g[x][0]) {
            merge(y);
            if (!f[x])
                f[x] = ++sum;
            if (!f[y])
                f[y] = ++sum;
            mesh(1, tot, f[x], f[y]);
        }
    }
    ans[x] = search(f[x], 1, tot);
}