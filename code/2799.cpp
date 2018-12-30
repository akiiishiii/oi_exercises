// 2799.cpp
#include <iostream>
#include <algorithm>

int const Maxn = 100010;
int const Maxq = 30010;
int n, m, tot = 0, cnt = 1, num = 0, all = 0;
int head[Maxn], Next[Maxn << 1], ver[Maxn << 1];
int root[Maxn * 5], val[Maxn], tmp[Maxn], poww[25];
int prt[Maxn][25], depth[Maxn], in[Maxn], out[Maxn], frt[Maxn], rt[Maxn];

struct question {
    int k, a, b;
} q[Maxq];

struct segment_tree {
    int l, r;
    int size;
} tree[Maxn * 400];

inline void add(int x, int y) { ver[++cnt] = y, Next[cnt] = head[x], head[x] = cnt; }
inline int lowbit(int x) { return x & (-x); }
int insert(int x, int l, int r, int last, int op);
void update(int pos, int x, int op);
void dfs(int x, int p, int d);
void st();
int lca(int x, int y);
void getr(int x, int y, int p, int g);
int query(int l, int r, int k);
bool ojbk(int k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> val[i], tmp[++tot] = val[i];
    for (int i = 1, x, y; i <= n - 1; i++)
        std::cin >> x >> y, add(x, y), add(y, x);
    for (int i = 1; i <= m; i++) {
        std::cin >> q[i].k >> q[i].a >> q[i].b;
        if (!q[i].k)
            tmp[++tot] = q[i].b;
    }
    std::sort(tmp + 1, tmp + tot + 1);
    tot = std::unique(tmp + 1, tmp + tot + 1) - tmp - 1;
    for (int i = 1; i <= n; i++)
        val[i] = std::lower_bound(tmp + 1, tmp + tot + 1, val[i]) - tmp;
    dfs(1, 0, 1);
    st();
    for (int i = 1; i <= m; i++) {
        if (!q[i].k) {
            int now = q[i].a;
            update(val[now], in[now], -1);
            update(val[now], out[now] + 1, 1);
            val[now] = std::lower_bound(tmp + 1, tmp + tot + 1, q[i].b) - tmp;
            update(val[now], in[now], 1);
            update(val[now], out[now] + 1, -1);
        } else {
            int p = lca(q[i].a, q[i].b), g = prt[p][0];
            getr(q[i].a, q[i].b, p, g);
            if (!ojbk(q[i].k))
                std::cout << "invalid request!\n";
            else
                std::cout << tmp[query(1, tot, q[i].k)] << '\n';
        }
    }
    return 0;
}

int insert(int x, int l, int r, int last, int op) {
    int c = ++all;
    tree[c] = tree[last];
    tree[c].size += op;
    if (l == r)
        return c;
    int mid = (l + r) >> 1;
    if (x <= mid)
        tree[c].l = insert(x, l, mid, tree[last].l, op);
    else
        tree[c].r = insert(x, mid + 1, r, tree[last].r, op);
    return c;
}

void update(int pos, int x, int op) {
    for (int i = x; i <= n; i += lowbit(i))
        root[i] = insert(pos, 1, tot, root[i], op);
}

void dfs(int x, int p, int d) {
    in[x] = ++num;
    depth[x] = d;
    prt[x][0] = p;
    update(val[x], in[x], 1);
    for (int i = head[x]; i; i = Next[i]) {
        int t = ver[i];
        if (t == p)
            continue;
        dfs(t, x, d + 1);
    }
    out[x] = num;
    update(val[x], out[x] + 1, -1);
}

void st() {
    poww[0] = 1;
    for (int i = 1; i <= 20; i++)
        poww[i] = poww[i - 1] * 2;
    for (int j = 1; j <= 20; j++)
        for (int i = 1; i <= n; i++)
            if (prt[i][j - 1])
                prt[i][j] = prt[prt[i][j - 1]][j - 1];
}

int lca(int x, int y) {
    if (depth[x] < depth[y])
        std::swap(x, y);
    int t = depth[x] - depth[y];
    for (int i = 0; poww[i] <= t; i++)
        if (t & poww[i])
            x = prt[x][i];
    if (x == y)
        return y;
    for (int i = 20; i >= 0; i--)
        if (prt[x][i] != prt[y][i])
            x = prt[x][i], y = prt[y][i];
    return prt[x][0];
}

void getr(int x, int y, int p, int g) {
    rt[0] = frt[0] = 0;
    for (int i = in[x]; i >= 1; i -= lowbit(i))
        rt[++rt[0]] = root[i];
    for (int i = in[y]; i >= 1; i -= lowbit(i))
        rt[++rt[0]] = root[i];
    for (int i = in[p]; i >= 1; i -= lowbit(i))
        frt[++frt[0]] = root[i];
    for (int i = in[g]; i >= 1; i -= lowbit(i))
        frt[++frt[0]] = root[i];
}

int query(int l, int r, int k) {
    if (l == r)
        return l;
    int size1 = 0, size2 = 0, size, mid = (l + r) >> 1;
    for (int i = 1; i <= rt[0]; i++)
        size1 += tree[tree[rt[i]].r].size;
    for (int i = 1; i <= frt[0]; i++)
        size2 += tree[tree[frt[i]].r].size;
    size = size1 - size2;
    if (size < k) {
        for (int i = 1; i <= rt[0]; i++)
            rt[i] = tree[rt[i]].l;
        for (int i = 1; i <= frt[0]; i++)
            frt[i] = tree[frt[i]].l;
        return query(l, mid, k - size);
    } else {
        for (int i = 1; i <= rt[0]; i++)
            rt[i] = tree[rt[i]].r;
        for (int i = 1; i <= frt[0]; i++)
            frt[i] = tree[frt[i]].r;
        return query(mid + 1, r, k);
    }
}

bool ojbk(int k) {
    int size1 = 0, size2 = 0, size;
    for (int i = 1; i <= rt[0]; i++)
        size1 += tree[rt[i]].size;
    for (int i = 1; i <= frt[0]; i++)
        size2 += tree[frt[i]].size;
    size = size1 - size2;
    if (size < k)
        return false;
    return true;
}