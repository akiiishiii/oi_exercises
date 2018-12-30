// 3865.cpp
#include <iostream>
#include <algorithm>

int const Maxn = 100010;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1], prt[Maxn][25], root[Maxn], d[Maxn], n, m;
int val[Maxn], tmp[Maxn], poww[25];
int tot, ans = 0, cnt = 1, num = 0;

struct segment_tree {
    int l, r;
    int size;
} tree[Maxn * 60];

void add(int x, int y) { ver[++cnt] = y, Next[cnt] = head[x], head[x] = cnt; }
int insert(int l, int r, int last, int x);
void dfs(int x, int p, int depth);
void st();
int lca(int x, int y);
int ask(int p, int g, int x, int y, int l, int r, int k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    poww[0] = 1;
    for (int i = 1; i <= 20; i++)
        poww[i] = poww[i - 1] * 2;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> val[i], tmp[i] = val[i];
    std::sort(tmp + 1, tmp + n + 1);
    tot = std::unique(tmp + 1, tmp + n + 1) - tmp - 1;
    for (int i = 1; i <= n; i++)
        val[i] = std::lower_bound(tmp + 1, tmp + tot + 1, val[i]) - tmp;
    for (int i = 1, x, y; i <= n - 1; i++)
        std::cin >> x >> y, add(x, y), add(y, x);
    dfs(1, 0, 1);
    st();
    for (int i = 1, x, y, z; i <= m; i++) {
        std::cin >> x >> y >> z;
        x ^= ans;
        int p = lca(x, y), g = prt[p][0];
        ans = tmp[ask(root[p], root[g], root[x], root[y], 1, tot, z)];
        std::cout << ans << '\n';
    }
    return 0;
}

int insert(int l, int r, int last, int x) {
    int c = ++num;
    tree[c] = tree[last];
    tree[c].size++;
    if (l == r)
        return c;
    int mid = (l + r) >> 1;
    if (x <= mid)
        tree[c].l = insert(l, mid, tree[last].l, x);
    else
        tree[c].r = insert(mid + 1, r, tree[last].r, x);
    return c;
}

void dfs(int x, int p, int depth) {
    d[x] = depth;
    prt[x][0] = p;
    root[x] = insert(1, tot, root[p], val[x]);
    for (int i = head[x]; i; i = Next[i]) {
        int t = ver[i];
        if (t == p)
            continue;
        dfs(t, x, depth + 1);
    }
}

void st() {
    for (int j = 1; j <= 20; j++)
        for (int i = 1; i <= n; i++)
            if (d[i] >= poww[j])
                prt[i][j] = prt[prt[i][j - 1]][j - 1];
}

int lca(int x, int y) {
    if (d[x] < d[y])
        std::swap(x, y);
    int t = d[x] - d[y];
    for (int i = 0; poww[i] <= t; i++)
        if (t & poww[i])
            x = prt[x][i];
    for (int i = 20; i >= 0; i--)
        if (prt[x][i] != prt[y][i])
            x = prt[x][i], y = prt[y][i];
    if (x == y)
        return y;
    return prt[x][0];
}

int ask(int p, int g, int x, int y, int l, int r, int k) {
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    int size = tree[tree[x].l].size + tree[tree[y].l].size - tree[tree[p].l].size -
               tree[tree[g].l].size;
    if (size >= k)
        return ask(tree[p].l, tree[g].l, tree[x].l, tree[y].l, l, mid, k);
    else
        return ask(tree[p].r, tree[g].r, tree[x].r, tree[y].r, mid + 1, r, k - size);
}