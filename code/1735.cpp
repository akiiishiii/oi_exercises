// 1735.cpp
#include <cmath>
#include <iostream>
#include <algorithm>

int const Maxn = 100005, Maxm = 1000005;
struct node {
    int l, r, x, y, id;
    bool operator<(node const &x) const;
} q[Maxm];
int n, m, blk;
int b[Maxn], l[Maxn], r[Maxn], a[Maxm], ans[Maxm], c[Maxn], bnum[Maxn];

int query(int x, int y);
void add(int x);
void del(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    blk = int(sqrt(n));
    for (int i = 1; i <= n; i++)
        b[i] = (i - 1) / blk + 1;
    for (int i = 1; i <= n; i++) {
        r[b[i]] = i;
        if (!l[b[i]])
            l[b[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= m; i++) {
        std::cin >> q[i].l >> q[i].r >> q[i].x >> q[i].y;
        q[i].id = i;
    }
    std::sort(q + 1, q + m + 1);
    for (int i = 1, l = 1, r = 0; i <= m; i++) {
        while (l < q[i].l)
            del(a[l]), l++;
        while (r > q[i].r)
            del(a[r]), r--;
        while (l > q[i].l)
            l--, add(a[l]);
        while (r < q[i].r)
            r++, add(a[r]);
        ans[q[i].id] = query(q[i].x, q[i].y);
    }
    for (int i = 1; i <= m; i++)
        std::cout << ans[i] << "\n";
    return 0;
}

bool node::operator<(node const &x) const {
    if (b[l] != b[x.l])
        return l < x.l;
    return r < x.r;
}

int query(int x, int y) {
    int tmp = 0, ll = b[x], rr = b[y];
    for (int i = ll + 1; i < rr; i++)
        tmp += bnum[i];
    if (ll == rr)
        for (int i = x; i <= y; i++) {
            if (c[i])
                tmp++;
        }
    else {
        for (int i = x; i <= r[ll]; i++)
            if (c[i])
                tmp++;
        for (int i = l[rr]; i <= y; i++)
            if (c[i])
                tmp++;
    }
    return tmp;
}

void add(int x) {
    c[x]++;
    if (c[x] == 1)
        bnum[b[x]]++;
}

void del(int x) {
    c[x]--;
    if (!c[x])
        bnum[b[x]]--;
}