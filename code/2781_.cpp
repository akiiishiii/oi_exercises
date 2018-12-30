// 2781_.cpp
#include <algorithm>
#include <iostream>

int const Maxn = 400010;
int n, m;
int a[Maxn], b[Maxn], c[Maxn], rt[Maxn], tot = 0, cnt = 0;
int a1[Maxn], a2[Maxn];

struct query {
    int l, r, k;
    char s[3];
} q[Maxn];

struct segment_tree {
    int lc, rc, sum;
} tree[Maxn * 10];

inline int lowbit(int x) { return x & (-x); }
int insert(int x, int l, int r, int last, int op);
void add(int r, int x, int op);
int query(int l, int r, int k);
int ask(int t1, int t2, int k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], b[i] = a[i];
    tot = n;
    for (int i = 1; i <= m; i++) {
        std::cin >> q[i].s;
        if (q[i].s[0] == 'Q')
            std::cin >> q[i].l >> q[i].r >> q[i].k;
        else {
            tot++;
            std::cin >> q[i].l >> q[i].k;
            b[tot] = q[i].k;
        }
    }
    std::sort(b + 1, b + tot + 1);
    tot = std::unique(b + 1, b + tot + 1) - b - 1;
    for (int i = 1; i <= n; i++)
        c[i] = std::lower_bound(b + 1, b + tot + 1, a[i]) - b;
    for (int i = 1; i <= n; i++)
        add(c[i], i, 1);
    for (int i = 1; i <= m; i++) {
        if (q[i].s[0] == 'Q')
            std::cout << b[ask(q[i].l - 1, q[i].r, q[i].k)] << '\n';
        else {
            add(c[q[i].l], q[i].l, -1);
            c[q[i].l] = std::lower_bound(b + 1, b + tot + 1, q[i].k) - b;
            add(c[q[i].l], q[i].l, 1);
        }
    }
    return 0;
}

int insert(int x, int l, int r, int last, int op) {
    tree[++cnt] = tree[last];
    tree[cnt].sum += op;
    int cc = cnt;
    if (l == r)
        return cc;
    if (x <= (l + r) / 2)
        tree[cc].lc = insert(x, l, (l + r) / 2, tree[last].lc, op);
    else
        tree[cc].rc = insert(x, (l + r) / 2 + 1, r, tree[last].rc, op);
    return cc;
}

void add(int r, int x, int op) {
    for (int i = x; i <= tot; i += lowbit(i))
        rt[i] = insert(r, 1, tot, rt[i], op);
}

int query(int l, int r, int k) {
    if (l == r)
        return l;
    int tmp1 = 0, tmp2 = 0;
    for (int i = 1; i <= a1[0]; i++)
        tmp1 += tree[tree[a1[i]].lc].sum;
    for (int i = 1; i <= a2[0]; i++)
        tmp2 += tree[tree[a2[i]].lc].sum;
    int tmp = tmp2 - tmp1;
    if (k <= tmp) {
        for (int i = 1; i <= a1[0]; i++)
            a1[i] = tree[a1[i]].lc;
        for (int i = 1; i <= a2[0]; i++)
            a2[i] = tree[a2[i]].lc;
        return query(l, (l + r) / 2, k);
    } else {
        for (int i = 1; i <= a1[0]; i++)
            a1[i] = tree[a1[i]].rc;
        for (int i = 1; i <= a2[0]; i++)
            a2[i] = tree[a2[i]].rc;
        return query((l + r) / 2 + 1, r, k - tmp);
    }
}

int ask(int t1, int t2, int k) {
    a1[0] = a2[0] = 0;
    for (int i = t1; i; i -= lowbit(i))
        a1[0]++, a1[a1[0]] = rt[i];
    for (int i = t2; i; i -= lowbit(i))
        a2[0]++, a2[a2[0]] = rt[i];
    return query(1, tot, k);
}