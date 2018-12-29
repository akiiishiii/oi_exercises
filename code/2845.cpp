// 2845.cpp
#include <iostream>
#include <algorithm>

int const Maxn = 100010;
int n, m;
int c[Maxn], rs[Maxn], lb[Maxn], pos[Maxn];
long long ans[Maxn];

struct insert {
    int t, x, y;
} a[Maxn], tmp[Maxn];

inline int lowbit(int const x) { return x & (-x); }
void add(int x, int v);
int sum(int x);
void cdq(int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i].y, a[i].x = i, pos[a[i].y] = i;
    int t, cnt = n;
    for (int i = 1; i <= m; i++)
        std::cin >> t, a[pos[t]].t = cnt--;
    for (int i = 1; i <= n; i++)
        if (!a[i].t)
            a[i].t = cnt--;
    cdq(1, n);
    for (int i = 1; i <= n; i++)
        ans[i] = ans[i - 1] + rs[i] + lb[i];
    for (int i = n; i >= n - m + 1; i--)
        std::cout << ans[i] << '\n';
    return 0;
}

void add(int x, int d) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += d;
}

int sum(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ret += c[i];
    return ret;
}

void cdq(int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    int l1 = l, l2 = mid + 1;
    for (int i = l; i <= r; i++)
        if (a[i].t <= mid)
            tmp[l1++] = a[i];
        else
            tmp[l2++] = a[i];
    for (int i = l; i <= r; i++)
        a[i] = tmp[i];
    l1 = l;
    for (int i = mid + 1; i <= r; i++) {
        while (l1 <= mid && tmp[l1].x < tmp[i].x)
            add(tmp[l1++].y, 1);
        lb[tmp[i].t] += (l1 - l) - sum(tmp[i].y);
    }
    for (int i = l; i <= l1 - 1; i++)
        add(tmp[i].y, -1);
    l1 = mid;
    for (int i = r; i >= mid + 1; i--) {
        while (l1 >= l && tmp[l1].x > tmp[i].x)
            add(tmp[l1--].y, 1);
        rs[tmp[i].t] += sum(tmp[i].y - 1);
    }
    for (int i = l1 + 1; i <= mid; i++)
        add(tmp[i].y, -1);
    cdq(l, mid), cdq(mid + 1, r);
}