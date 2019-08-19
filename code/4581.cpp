// 4581.cpp
#include <iostream>

int const Maxn = 200005;
struct Edge {
    int to, next;
} w[Maxn << 1];
int cnt = 0, h[Maxn], sign = 0;
int n, m, prt[Maxn], son[Maxn], d[Maxn], sz[Maxn], top[Maxn], p[Maxn], ed[Maxn];
int l[Maxn << 2], r[Maxn << 2];
long long sm[Maxn << 2], a[Maxn << 2], ad[Maxn << 2];

void AddEdge(int x, int y) {
    w[++cnt] = (Edge){y, h[x]};
    h[x] = cnt;
}

void DFS1(int x, int dep, int fa) {
    int j, y;
    sz[x] = 1;
    prt[x] = fa;
    d[x] = dep;
    for (j = h[x]; j; j = w[j].next) {
        y = w[j].to;
        if (y == fa)
            continue;
        DFS1(y, dep + 1, x);
        sz[x] += sz[y];
        if (!son[x] || sz[y] > sz[son[x]])
            son[x] = y;
    }
}

void DFS2(int x, int tp) {
    int j, y;
    p[x] = ++sign;
    top[x] = tp;
    if (son[x])
        DFS2(son[x], tp);
    for (j = h[x]; j; j = w[j].next) {
        y = w[j].to;
        if (y != prt[x] && y != son[x])
            DFS2(y, y);
    }
    ed[x] = sign;
}

void Pushdown(int x) {
    int ls = x << 1, rs = x << 1 | 1;
    if (ad[x]) {
        ad[ls] += ad[x];
        sm[ls] += (r[ls] - l[ls] + 1) * ad[x];
        ad[rs] += ad[x];
        sm[rs] += (r[rs] - l[rs] + 1) * ad[x];
        ad[x] = 0;
    }
}

void Pushup(int x) { sm[x] = sm[x << 1] + sm[x << 1 | 1]; }

void build(int x, int L, int R) {
    l[x] = L;
    r[x] = R;
    sm[x] = 0;
    int mid = L + R >> 1;
    if (L == R)
        return;
    build(x << 1, L, mid);
    build(x << 1 | 1, mid + 1, R);
    Pushup(x);
}

void Add(int x, int L, int R, long long v) {
    if (l[x] > R || r[x] < L)
        return;
    if (L <= l[x] && r[x] <= R) {
        sm[x] += v * (r[x] - l[x] + 1);
        ad[x] += v;
        return;
    }
    Pushdown(x);
    Add(x << 1, L, R, v);
    Add(x << 1 | 1, L, R, v);
    Pushup(x);
}

long long Ask(int x, int L, int R) {
    if (l[x] > R || r[x] < L)
        return 0;
    if (L <= l[x] && r[x] <= R)
        return sm[x];
    Pushdown(x);
    long long ls = Ask(x << 1, L, R), rs = Ask(x << 1 | 1, L, R);
    Pushup(x);
    return ls + rs;
}

long long Que(int x) {
    long long sm = 0;
    while (x) {
        sm += Ask(1, p[top[x]], p[x]);
        x = prt[top[x]];
    }
    return sm;
}

int main() {
    int i, x, y;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        AddEdge(x, y);
        AddEdge(y, x);
    }
    DFS1(1, 1, 0);
    DFS2(1, 1);
    build(1, 1, n);
    for (i = 1; i <= n; i++)
        Add(1, p[i], p[i], a[i]);
    int i, k, x;
    long long y;
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &k, &x);
        if (k == 3)
            printf("%lld\n", Que(x));
        if (k == 1) {
            scanf("%lld", &y);
            Add(1, p[x], p[x], y);
        }
        if (k == 2) {
            scanf("%lld", &y);
            Add(1, p[x], ed[x], y);
        }
    }
    return 0;
}