#include <cstdio>
#include <iostream>
#define rep(i, a, b) for (i = a; i <= b; i++)
using namespace std;
int t, n, i, j;
bool f[1000001];
int main() {
    scanf("%d", &t);
    f[0] = 0;
    rep(i, 1, 1000000) {

        int mxn = 0, mnn = 2147483647, x = i;
        while (x > 0) {
            if (x % 10 != 0) {
                mxn = max(mxn, x % 10);
                mnn = min(mnn, x % 10);
            }
            x /= 10;
        }
        f[i] = !f[i - mxn] || !f[i - mnn];
    }
    rep(i, 1, t) {
        scanf("%d", &n);
        if (f[n])
            printf("YES\n");
        else
            printf("NO\n");
    }
}

#include <cstdio>
#include <iostream>
#define rep(i, a, b) for (i = a; i <= b; i++)
#define q(x) tree[x]
using namespace std;
int n, i;
int a[200001];
int f[200001], tree[4400001];
void change(int p, int l, int r, int d) {
    if (l == r) {
        q(p) = f[i];
        return;
    }
    int mid = (l + r) / 2;
    if (d <= mid)
        change(p * 2, l, mid, d);
    else
        change(p * 2 + 1, mid + 1, r, d);
    q(p) = max(q(p * 2), q(p * 2 + 1));
}
int ask(int p, int x, int y, int l, int r) {
    if (r < 0 || l > 1100000)
        return 0;
    int val = 0;
    if (x == l && y == r)
        return q(p);
    int mid = (x + y) / 2;
    if (r <= mid)
        val = ask(p * 2, x, mid, l, r);
    else if (mid < l)
        val = ask(p * 2 + 1, mid + 1, y, l, r);
    else {
        val = ask(p * 2, x, mid, l, mid);
        val = max(val, ask(p * 2 + 1, mid + 1, y, mid + 1, r));
    }
    return val;
}
int main() {
    scanf("%d", &n);
    rep(i, 1, n) {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }
    rep(i, 1, 2 * n) {
        f[i] = max(ask(1, 0, 1100000, a[i] + 2, 1100000),
                   max(ask(1, 0, 1100000, 0, a[i] - 2),
                       ask(1, 0, 1100000, a[i], a[i]))) +
               1;
        change(1, 0, 1100000, a[i]);
    }
    printf("%d", q(1) / 2);
}

#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 610
using namespace std;
int n, m, x[N], y[N], d[N], p[N], v[N], id[N], fa[N], c[N], bz[N], map[N][N],
    q[N], ql, qr;
int t[N], nx[N], l[N], s[N], sa[N], f[N], id2[N], id3[N], ans = 0, rt, md;
int t2[N], n2[N], l2[N];
int cmp(int x, int y) { return x < y; }
void add(int x, int y, int p, int d) {
    t[++t[0]] = y;
    nx[t[0]] = l[x];
    l[x] = t[0];
    s[t[0]] = p;
    id2[t[0]] = d;
}
void add2(int x, int y) {
    t2[++t2[0]] = y;
    n2[t2[0]] = l2[x];
    l2[x] = t2[0];
}
void qs(int l, int r) {
    int i = l, j = r, m1 = p[(l + r) >> 1], m2 = v[(l + r) >> 1],
        m3 = id[(l + r) >> 1];
    while (i <= j) {
        while (p[i] > m1 || (p[i] == m1 && v[i] > m2) ||
               (p[i] == m1 && v[i] == m2 && id[i] < m3))
            i++;
        while (p[j] < m1 || (p[j] == m1 && v[j] < m2) ||
               (p[j] == m1 && v[j] == m2 && id[j] > m3))
            j--;
        if (i <= j) {
            swap(x[i], x[j]);
            swap(y[i], y[j]);
            swap(p[i], p[j]);
            swap(v[i], v[j]);
            swap(c[id[i]], c[id[j]]);
            swap(id[i], id[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        qs(l, j);
    if (i < r)
        qs(i, r);
}
int get(int x) {
    if (f[x] == x)
        return x;
    return f[x] = get(f[x]);
}
void dg(int x, int y, int z, int di) {
    fa[x] = y;
    d[x] = d[y] + 1;
    sa[x] = z;
    id3[x] = di;
    for (int k = l[x]; k; k = nx[k]) {
        if (t[k] != y)
            dg(t[k], x, s[k], id2[k]);
    }
}
void LCA(int x, int y, int z) {
    if (d[x] < d[y])
        swap(x, y);
    md = 0;
    while (d[x] > d[y]) {
        if (sa[x] == z)
            md = max(md, id3[x]);
        x = fa[x];
    }
    if (x == y)
        return;
    while (x != y) {
        if (sa[x] == z)
            md = max(md, id3[x]);
        if (sa[y] == z)
            md = max(md, id3[y]);
        x = fa[x];
        y = fa[y];
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &x[i], &y[i], &p[i], &v[i]);
        id[i] = i;
        c[i] = i;
    }
    qs(1, m);
    for (int i = 1; i <= max(n, m); i++)
        f[i] = i, bz[i] = 1;
    for (int i = 1; i <= m; i++) {
        int fx = get(x[i]), fy = get(y[i]);
        if (fx != fy) {
            add(x[i], y[i], p[i], id[i]);
            add(y[i], x[i], p[i], id[i]);
            f[fx] = fy;
            f[0]++;
            ans += v[i];
            rt = x[i];
            bz[id[i]] = 2;
        }
        if (f[0] == n - 1)
            break;
    }
    dg(rt, 0, 0, 0);
    printf("%d\n", ans);
    for (int i = 1; i <= m; i++) {
        if (bz[i] != 2) {
            LCA(x[c[i]], y[c[i]], p[c[i]]);
            if (md) {
                bz[i] = 0;
                map[md][0]++;
                map[md][map[md][0]] = i;
            }
        }
    }
    ql = 1;
    qr = 0;
    for (int i = 1; i <= m; i++) {
        if (bz[i]) {
            while (ql <= qr && q[ql] < i) {
                printf("%d ", q[ql]);
                q[ql++] = 0;
            }
            for (int j = 1; j <= map[i][0]; j++)
                q[++qr] = map[i][j];
            if (qr - ql + 1 == 0)
                printf("%d ", i);
            else {
                printf("%d ", i);
                sort(q + 1, q + 1 + qr, cmp);
                while (ql <= qr && q[ql] < i) {
                    printf("%d ", q[ql]);
                    q[ql++] = 0;
                }
            }
        }
    }
    while (ql <= qr)
        printf("%d ", q[ql++]);
    return 0;
}

#include <cstdio>
#define M 80000
#define N 1000010
#define max(a, b) (((a) > (b)) ? (a) : (b))

long a[N], p[M], phi[N], t;
long long ans[N];
bool b[N];

int main() {
    long tot, n, i, j, k, maxx = 0;
    scanf("%ld", &tot);
    for (i = 1; i <= tot; i++) {
        scanf("%ld", &a[i]);
        maxx = max(maxx, a[i]);
    }
    n = maxx;
    phi[1] = 1;
    for (i = 2; i <= n; i++) {
        if (!b[i]) {
            phi[i] = i - 1;
            p[++t] = i;
        }
        for (j = 1; j <= t && i * p[j] <= n; j++) {
            b[i * p[j]] = true;
            if (i % p[j] == 0) {
                phi[i * p[j]] = phi[i] * p[j];
                break;
            } else
                phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
    for (i = 2; i <= n; i++)
        for (j = 1; j <= n / i; j++)
            ans[i * j] += phi[i] * j;
    for (i = 2; i <= n; i++)
        ans[i] += ans[i - 1];
    for (k = 1; k <= tot; k++)
        printf("%lld\n", ans[a[k]]);
    return 0;
}