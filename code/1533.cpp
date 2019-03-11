// 1533.cpp
#include <algorithm>
#include <iostream>

int const Maxn = 100005 * 20;
int n, num;
int a[Maxn], b[Maxn], root[Maxn], ans[Maxn], cnt = 0;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1], tot = 0;

struct segment_tree {
    int lc, rc, num;
} t[Maxn];


inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void pushup(int x);
void insert(int &x, int l, int r, int d);
int mesh(int x, int l, int r, int ll, int rr);
int merge(int x, int y);
void dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], b[i] = a[i];
    std::sort(b + 1, b + 1 + n);
    num = std::unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + 1 + num, a[i]) - b;
    for (int i = 2, x; i <= n; i++)
        std::cin >> x, add(x, i);
    for (int i = 1; i <= n; i++)
        insert(root[i], 1, n, a[i]);
    dfs(1);
    for (int i = 1; i <= n; i++)
        std::cout << ans[i] << '\n';
    return 0;
}


void pushup(int x) {
    int lc = t[x].lc, rc = t[x].rc;
    t[x].num = t[lc].num + t[rc].num;
}

void insert(int &x, int l, int r, int d) {
    if (l > r)
        return;
    x = ++cnt;
    if (l == r) {
        t[x].num = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (d <= mid)
        insert(t[x].lc, l, mid, d);
    else
        insert(t[x].rc, mid + 1, r, d);
    pushup(x);
}

int mesh(int x, int l, int r, int ll, int rr) {
    int ans = 0;
    if (rr < ll)
        return 0;
    if (ll <= l && r <= rr)
        return t[x].num;
    int mid = (l + r) >> 1;
    if (ll <= mid)
        ans += mesh(t[x].lc, l, mid, ll, rr);
    if (rr > mid)
        ans += mesh(t[x].rc, mid + 1, r, ll, rr);
    return ans;
}

int merge(int x, int y) {
    if (!x || !y)
        return x | y;
    t[x].lc = merge(t[x].lc, t[y].lc);
    t[x].rc = merge(t[x].rc, t[y].rc);
    pushup(x);
    return x;
}

void dfs(int x) {
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        dfs(y);
        root[x] = merge(root[x], root[y]);
    }
    ans[x] = mesh(root[x], 1, n, a[x] + 1, num);
}