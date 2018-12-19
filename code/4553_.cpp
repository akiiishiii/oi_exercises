#include <cmath>
#include <iostream>
#include <algorithm>

int const Maxn = 50005;
int a[Maxn], tmp[Maxn], pos[Maxn], res[Maxn], c[Maxn];
int n, m, blk;

struct query {
    int l, r, id;
    bool operator<(query const &x) const;
} qs[Maxn];

template <typename T> inline T lowbit(T const x) { return x & (-x); }
void add(int x, int d);
int sum(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], tmp[i] = a[i];
    std::sort(tmp + 1, tmp + n + 1);
    int tot = std::unique(tmp + 1, tmp + n + 1) - tmp - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(tmp + 1, tmp + tot + 1, a[i]) - tmp;
    std::cin >> m;
    for (int i = 1; i <= m; i++)
        std::cin >> qs[i].l >> qs[i].r, qs[i].id = i;
    blk = (int)sqrt(n);
    for (int i = 1; i <= n; i++)
        pos[i] = (i - 1) / blk + 1;
    std::sort(qs + 1, qs + m + 1);
    int l = qs[1].l, r = qs[1].r, tmp = 0;
    for (int i = r; i >= l; i--)
        tmp += sum(a[i]), add(a[i], 1);
    res[qs[1].id] = tmp;
    for (int i = 2; i <= m; i++) {
        while (l < qs[i].l)
            add(a[l], -1), tmp -= sum(a[l++] - 1);
        while (r > qs[i].r)
            add(a[r], -1), tmp -= r - l - sum(a[r]), r--;
        while (l > qs[i].l)
            tmp += sum(a[--l] - 1), add(a[l], 1);
        while (r < qs[i].r)
            r++, tmp += r - l - sum(a[r]), add(a[r], 1);
        res[qs[i].id] = tmp;
    }
    for (int i = 1; i <= m; i++)
        std::cout << res[i] << '\n';
    return 0;
}

bool query::operator<(query const &x) const {
    if (pos[l] == pos[x.l])
        return r < x.r;
    return pos[l] < pos[x.l];
}

void add(int x, int d) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += d;
}

int sum(int x) {
    int ret = 0;
    for (int i = x; i; i -= lowbit(i))
        ret += c[i];
    return ret;
}