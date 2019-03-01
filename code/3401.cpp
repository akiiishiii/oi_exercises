// 3401.cpp
#include <algorithm>
#include <cstring>
#include <iostream>

int const Maxn = 30010;

long long root[Maxn], n, m, tmp[Maxn * 3], tot = 0, cnt = 0;
struct node {
    long long p, q;
} a[Maxn];

struct que {
    long long l, r, b, u, k;
} b[Maxn];

struct chairman_tree {
    long long lc, rc, sum;
} tr[Maxn * 40];

long long insert(long long last, long long l, long long r, long long pos, long long val);
long long query(long long ll, long long rr, long long l, long long r, long long pos);
long long ask(long long ll, long long rr, long long l, long long r, long long k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (long long i = 1; i <= n; i++)
        std::cin >> a[i].p >> a[i].q, tmp[++tot] = a[i].p;
    std::cin >> m;
    for (long long i = 1; i <= m; i++) {
        std::cin >> b[i].l >> b[i].r >> b[i].b >> b[i].u >> b[i].k;
        tmp[++tot] = b[i].b, tmp[++tot] = b[i].u;
    }
    std::sort(tmp + 1, tmp + tot + 1);
    tot = std::unique(tmp + 1, tmp + tot + 1) - tmp - 1;
    for (long long i = 1; i <= n; i++) {
        a[i].p = std::lower_bound(tmp + 1, tmp + tot + 1, a[i].p) - tmp;
        root[i] = insert(root[i - 1], 1, tot, a[i].p, a[i].q);
    }
    for (long long i = 1; i <= m; i++) {
        b[i].b = std::lower_bound(tmp + 1, tmp + tot + 1, b[i].b) - tmp;
        b[i].u = std::lower_bound(tmp + 1, tmp + tot + 1, b[i].u) - tmp;
        long long dlt;
        if (b[i].b == 1)
            dlt = 0;
        else
            dlt = query(root[b[i].l - 1], root[b[i].r], 1, tot, b[i].b - 1);
        long long k = dlt + b[i].k, mx = query(root[b[i].l - 1], root[b[i].r], 1, tot, b[i].u);
        if (mx < k)
            std::cout << "-1\n";
        else
            std::cout << tmp[ask(root[b[i].l - 1], root[b[i].r], 1, tot, k)] << '\n';
    }
    return 0;
}

long long insert(long long last, long long l, long long r, long long pos, long long val) {
    long long c = ++cnt;
    tr[c] = tr[last];
    tr[c].sum += val;
    if (l == r)
        return c;
    long long mid = (l + r) >> 1;
    if (pos <= mid)
        tr[c].lc = insert(tr[last].lc, l, mid, pos, val);
    else
        tr[c].rc = insert(tr[last].rc, mid + 1, r, pos, val);
    return c;
}

long long query(long long ll, long long rr, long long l, long long r, long long pos) {
    if (l == r)
        return tr[rr].sum - tr[ll].sum;
    long long mid = (l + r) >> 1;
    if (pos <= mid)
        return query(tr[ll].lc, tr[rr].lc, l, mid, pos);
    else
        return query(tr[ll].rc, tr[rr].rc, mid + 1, r, pos) +
               (tr[tr[rr].lc].sum - tr[tr[ll].lc].sum);
}

long long ask(long long ll, long long rr, long long l, long long r, long long k) {
    long long mid = (l + r) >> 1;
    long long lk = tr[tr[rr].lc].sum - tr[tr[ll].lc].sum;
    if (l == r)
        return l;
    if (k <= lk)
        return ask(tr[ll].lc, tr[rr].lc, l, mid, k);
    else
        return ask(tr[ll].rc, tr[rr].rc, mid + 1, r, k - lk);
}