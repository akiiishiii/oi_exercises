#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define MAX 100005
#define INF 0x3f3f3f
using namespace std;

int n, m, T, val[MAX], tmp[MAX], tot, cnt = 0, head[MAX], fa[MAX][20];
int root[MAX], pow_set[20], ans = 0, siz[MAX], depth[MAX], num = 0, prt[MAX];
struct edge {
    int next, to;
} a[MAX * 4];
struct chairman_tree {
    int l, r, sz;
} tr[MAX * 100];
void add(int x, int y) {
    a[++cnt].next = head[x];
    a[cnt].to = y;
    head[x] = cnt;
}
int insert(int l, int r, int last, int val) {
    int c = ++num;
    tr[c] = tr[last];
    tr[c].sz++;
    if (l == r)
        return c;
    int mid = (l + r) / 2;
    if (val <= mid)
        tr[c].l = insert(l, mid, tr[last].l, val);
    else
        tr[c].r = insert(mid + 1, r, tr[last].r, val);
    return c;
}
void dfs(int x, int f) {
    fa[x][0] = f;
    depth[x] = depth[f] + 1;
    siz[x] = 1;
    for (int j = 1; j < 20; j++)
        fa[x][j] = fa[fa[x][j - 1]][j - 1];
    root[x] = insert(1, tot, root[f], val[x]);
    for (int i = head[x]; i; i = a[i].next) {
        int t = a[i].to;
        if (t == f)
            continue;
        dfs(t, x);
        siz[x] += siz[t];
    }
}
void ST() {
    pow_set[0] = 1;
    for (int i = 1; i < 20; i++)
        pow_set[i] = pow_set[i - 1] * 2;
}
int lca(int x, int y) {
    if (depth[x] < depth[y])
        swap(x, y);
    int t = depth[x] - depth[y];
    for (int i = 19; i >= 0; i--)
        if (t & pow_set[i])
            x = fa[x][i];
    for (int i = 19; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    if (x == y)
        return x;
    return fa[x][0];
}
int ask(int x, int y, int f, int gf, int l, int r, int k) {
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (k <= tr[tr[x].l].sz + tr[tr[y].l].sz - tr[tr[f].l].sz - tr[tr[gf].l].sz)
        return ask(tr[x].l, tr[y].l, tr[f].l, tr[gf].l, l, mid, k);
    else
        return ask(tr[x].r, tr[y].r, tr[f].r, tr[gf].r, mid + 1, r,
                   k - (tr[tr[x].l].sz + tr[tr[y].l].sz - tr[tr[f].l].sz -
                        tr[tr[gf].l].sz));
}
void down(int x, int allsize, int allprt) {
    siz[x] = allsize;
    prt[x] = allprt;
    for (int i = head[x]; i; i = a[i].next) {
        int t = a[i].to;
        if (t == fa[x][0])
            continue;
        down(t, allsize, allprt);
    }
}
void merge(int x, int y) {
    add(x, y);
    add(y, x);
    if (siz[x] > siz[y])
        swap(x, y);
    dfs(x, y);
    down(prt[y], siz[x] + siz[y], prt[y]);
}
int main() {
    int x, y, z;
    char op;
    read();
    std::cin >> n >> m >> T;
    for (int i = 1; i <= n; i++)
        std::cin >> val[i], tmp[i] = val[i];
    sort(tmp + 1, tmp + n + 1);
    tot = unique(tmp + 1, tmp + n + 1) - tmp - 1;
    for (int i = 1; i <= n; i++)
        val[i] = lower_bound(tmp + 1, tmp + tot + 1, val[i]) - tmp;
    for (int i = 1; i <= m; i++)
        std::cin >> x >> y, add(x, y), add(y, x);
    for (int i = 1; i <= n; i++)
        if (!root[i])
            dfs(i, 0), down(i, siz[i], i);
    ST();
    while (T--) {
        op = std::cin.get();
        while (op != 'Q' && op != 'L')
            op = std::cin.get();
        if (op == 'Q') {
            x = read();
            y = read();
            z = read();
            x ^= ans;
            y ^= ans;
            z ^= ans;
            int f = lca(x, y), gf = fa[f][0];
            ans = tmp[ask(root[x], root[y], root[f], root[gf], 1, tot, z)];
            printf("%d\n", ans);
        } else {
            x = read();
            y = read();
            x ^= ans;
            y ^= ans;
            merge(x, y);
        }
    }
    return 0;
}