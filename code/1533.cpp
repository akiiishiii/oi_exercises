// 1533.cpp
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
#define maxn 100005 * 20
#define inf 1e9
#define ll long long
using namespace std;

struct Ares {
    int lc, rc;
    int num;
} t[maxn];

struct tree {
    int to, next;
} xm[maxn];

int n, N;
int a[maxn], b[maxn], rt[maxn], ans[maxn], tot = 0;
int h[maxn] = {0}, cnt = 0;
void Addedge(int x, int y) {
    cnt++;
    xm[cnt].next = h[x], xm[cnt].to = y;
    h[x] = cnt;
}
void Pushup(int x) {
    int lc = t[x].lc, rc = t[x].rc;
    t[x].num = t[lc].num + t[rc].num;
}
void Insert(int &x, int l, int r, int helios) {
    if (l > r)
        return;
    x = ++tot;
    if (l == r) {
        t[x].num = 1;
        return;
    }
    int mid = (l + r) / 2;
    if (helios <= mid)
        Insert(t[x].lc, l, mid, helios);
    else
        Insert(t[x].rc, mid + 1, r, helios);
    Pushup(x);
}
int Artemis(int x, int l, int r, int pl, int pr) {
    int ans = 0;
    if (pr < pl)
        return 0;
    if (pl <= l && r <= pr)
        return t[x].num;
    int mid = (l + r) / 2;
    if (pl <= mid)
        ans += Artemis(t[x].lc, l, mid, pl, pr);
    if (pr > mid)
        ans += Artemis(t[x].rc, mid + 1, r, pl, pr);
    return ans;
}
int Merge(int x, int y) {
    if (!x || !y)
        return x | y;
    t[x].lc = Merge(t[x].lc, t[y].lc);
    t[x].rc = Merge(t[x].rc, t[y].rc);
    Pushup(x);
    return x;
}
void dfs(int x) {
    int i, y;
    for (i = h[x]; i; i = xm[i].next) {
        y = xm[i].to;
        dfs(y);
        rt[x] = Merge(rt[x], rt[y]);
    }
    ans[x] = Artemis(rt[x], 1, n, a[x] + 1, N);
}
int main() {
    int i, x;
    n = read();
    for (i = 1; i <= n; i++)
        a[i] = b[i] = read();
    sort(b + 1, b + 1 + n);
    N = unique(b + 1, b + 1 + n) - b - 1;
    for (i = 1; i <= n; i++)
        a[i] = lower_bound(b + 1, b + 1 + N, a[i]) - b;
    for (i = 2; i <= n; i++) {
        scanf("%d", &x);
        Addedge(x, i);
    }
    for (i = 1; i <= n; i++)
        Insert(rt[i], 1, n, a[i]);
    dfs(1);
    for (i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}