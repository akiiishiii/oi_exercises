// 3677.cpp
#include <iostream>
#include <algorithm>

int const Maxn = 100010;
int n, m, T, cnt, tot, ans, num;
int val[Maxn], tmp[Maxn], f[Maxn][20];
int head[Maxn], ver[Maxn << 2], Next[Maxn << 2];
int root[Maxn], pows[20], siz[Maxn], depth[Maxn], prt[Maxn];

struct chairman_tree {
    int l, r, sz;
} tree[Maxn * 100];

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
int insert(int l, int r, int last, int d);
void dfs(int x, int p);
void st();
int lca(int x, int y);
int ask(int x, int y, int d, int gd, int l, int r, int k);
void pushdown(int x, int s, int p);
void merge(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, y, z;
    char op;
    std::cin >> x;
    std::cin >> n >> m >> T;
    for (int i = 1; i <= n; i++)
        std::cin >> val[i], tmp[i] = val[i];
    std::sort(tmp + 1, tmp + n + 1);
    cnt = std::unique(tmp + 1, tmp + n + 1) - tmp - 1;
    for (int i = 1; i <= n; i++)
        val[i] = std::lower_bound(tmp + 1, tmp + cnt + 1, val[i]) - tmp;
    for (int i = 1; i <= m; i++)
        std::cin >> x >> y, add(x, y), add(y, x);
    for (int i = 1; i <= n; i++)
        if (!root[i])
            dfs(i, 0), pushdown(i, siz[i], i);
    st();
    while (T--) {
        std::cin >> op;
        if (op == 'Q') {
            std::cin >> x >> y >> z;
            x ^= ans, y ^= ans, z ^= ans;
            int d = lca(x, y), gd = f[d][0];
            ans = tmp[ask(root[x], root[y], root[d], root[gd], 1, cnt, z)];
            std::cout << ans << '\n';
        } else {
            std::cin >> x >> y;
            x ^= ans, y ^= ans;
            merge(x, y);
        }
    }
    return 0;
}

int insert(int l, int r, int last, int d) {
    int c = ++num;
    tree[c] = tree[last];
    tree[c].sz++;
    if (l == r)
        return c;
    int mid = (l + r) >> 1;
    if (d <= mid)
        tree[c].l = insert(l, mid, tree[last].l, d);
    else
        tree[c].r = insert(mid + 1, r, tree[last].r, d);
    return c;
}

void dfs(int x, int p) {
    f[x][0] = p;
    depth[x] = depth[p] + 1;
    siz[x] = 1;
    for (int j = 1; j < 20; j++)
        f[x][j] = f[f[x][j - 1]][j - 1];
    root[x] = insert(1, cnt, root[p], val[x]);
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        dfs(y, x);
        siz[x] += siz[y];
    }
}

void st() {
    pows[0] = 1;
    for (int i = 1; i < 20; i++)
        pows[i] = pows[i - 1] * 2;
}

int lca(int x, int y) {
    if (depth[x] < depth[y])
        std::swap(x, y);
    int t = depth[x] - depth[y];
    for (int i = 19; i >= 0; i--)
        if (t & pows[i])
            x = f[x][i];
    for (int i = 19; i >= 0; i--)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    if (x == y)
        return x;
    return f[x][0];
}

int ask(int x, int y, int d, int gd, int l, int r, int k) {
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    if (k <= tree[tree[x].l].sz + tree[tree[y].l].sz - tree[tree[d].l].sz - tree[tree[gd].l].sz)
        return ask(tree[x].l, tree[y].l, tree[d].l, tree[gd].l, l, mid, k);
    else
        return ask(tree[x].r, tree[y].r, tree[d].r, tree[gd].r, mid + 1, r, k - (tree[tree[x].l].sz + tree[tree[y].l].sz - tree[tree[d].l].sz - tree[tree[gd].l].sz));
}

void pushdown(int x, int s, int p) {
    siz[x] = s, prt[x] = p;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == f[x][0])
            continue;
        pushdown(y, s, p);
    }
}

void merge(int x, int y) {
    add(x, y), add(y, x);
    if (siz[x] > siz[y])
        std::swap(x, y);
    dfs(x, y);
    pushdown(prt[y], siz[x] + siz[y], prt[y]);
}