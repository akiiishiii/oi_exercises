// 2799.cpp
#include <iostream>
#include <algorithm>

#define MAX 100005
#define MAXQ 30005
using namespace std;
struct edge {
    int next, to;
} a[MAX * 2];
struct question {
    int k, a, b;
} q[MAXQ];
struct segment {
    int l, r, size;
} tr[MAX * 400];
int n, m, head[MAX], root[MAX * 5], val[MAX], tmp[MAX], tot = 0, cnt = 1,
                                                        num = 0, poww[25];
int prt[MAX][25], depth[MAX], in[MAX], out[MAX], all = 0, frt[MAX], rt[MAX];
void add(int x, int y) {
    a[++cnt].next = head[x];
    a[cnt].to = y;
    head[x] = cnt;
}
int lowbit(int x) { return x & (-x); }
int insert(int x, int l, int r, int last, int op) {
    int c = ++all;
    tr[c] = tr[last];
    tr[c].size += op;
    if (l == r)
        return c;
    int mid = (l + r) / 2;
    if (x <= mid)
        tr[c].l = insert(x, l, mid, tr[last].l, op);
    else
        tr[c].r = insert(x, mid + 1, r, tr[last].r, op);
    return c;
}
void update(int pos, int x, int op) {
    for (int i = x; i <= n; i += lowbit(i))
        root[i] = insert(pos, 1, tot, root[i], op);
}
void dfs(int x, int fa, int d) {
    in[x] = ++num;
    depth[x] = d;
    prt[x][0] = fa;
    update(val[x], in[x], 1);
    for (int i = head[x]; i; i = a[i].next) {
        int t = a[i].to;
        if (t == fa)
            continue;
        dfs(t, x, d + 1);
    }
    out[x] = num;
    update(val[x], out[x] + 1, -1);
}
void ST() {
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
        swap(x, y);
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
void getroot(int x, int y, int fa, int gfa) {
    rt[0] = frt[0] = 0;
    for (int i = in [x]; i >= 1; i -= lowbit(i))
        rt[++rt[0]] = root[i];
    for (int i = in [y]; i >= 1; i -= lowbit(i))
        rt[++rt[0]] = root[i];
    for (int i = in [fa]; i >= 1; i -= lowbit(i))
        frt[++frt[0]] = root[i];
    for (int i = in [gfa]; i >= 1; i -= lowbit(i))
        frt[++frt[0]] = root[i];
}
int ask(int l, int r, int k) {
    if (l == r)
        return l;
    int size1 = 0, size2 = 0, size, mid = (l + r) / 2;
    for (int i = 1; i <= rt[0]; i++)
        size1 += tr[tr[rt[i]].r].size;
    for (int i = 1; i <= frt[0]; i++)
        size2 += tr[tr[frt[i]].r].size;
    size = size1 - size2;
    if (size < k) {
        for (int i = 1; i <= rt[0]; i++)
            rt[i] = tr[rt[i]].l;
        for (int i = 1; i <= frt[0]; i++)
            frt[i] = tr[frt[i]].l;
        return ask(l, mid, k - size);
    } else {
        for (int i = 1; i <= rt[0]; i++)
            rt[i] = tr[rt[i]].r;
        for (int i = 1; i <= frt[0]; i++)
            frt[i] = tr[frt[i]].r;
        return ask(mid + 1, r, k);
    }
}
bool ok(int k) {
    int size1 = 0, size2 = 0, size;
    for (int i = 1; i <= rt[0]; i++)
        size1 += tr[rt[i]].size;
    for (int i = 1; i <= frt[0]; i++)
        size2 += tr[frt[i]].size;
    size = size1 - size2;
    if (size < k)
        return false;
    return true;
}
int main() {
    int x, y;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]), tmp[++tot] = val[i];
    for (int i = 1; i <= n - 1; i++)
        scanf("%d%d", &x, &y), add(x, y), add(y, x);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &q[i].k, &q[i].a, &q[i].b);
        if (q[i].k == 0)
            tmp[++tot] = q[i].b;
    }
    sort(tmp + 1, tmp + tot + 1);
    tot = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
    for (int i = 1; i <= n; i++)
        val[i] = lower_bound(tmp + 1, tmp + tot + 1, val[i]) - tmp;
    dfs(1, 0, 1);
    ST();
    for (int i = 1; i <= m; i++) {
        if (q[i].k == 0) {
            int now = q[i].a;
            update(val[now], in[now], -1);
            update(val[now], out[now] + 1, 1);
            val[now] = lower_bound(tmp + 1, tmp + tot + 1, q[i].b) - tmp;
            update(val[now], in[now], 1);
            update(val[now], out[now] + 1, -1);
        } else {
            int fa = lca(q[i].a, q[i].b), gfa = prt[fa][0];
            getroot(q[i].a, q[i].b, fa, gfa);
            if (!ok(q[i].k))
                printf("invalid request!\n");
            else
                printf("%d\n", tmp[ask(1, tot, q[i].k)]);
        }
    }
}