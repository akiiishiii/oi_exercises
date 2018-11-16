#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

struct treee {
    int a, b, h;
} tree[80000 * 4 + 1], a[80000 * 4 + 1];
int b[80000 * 4 + 1];
long long ans;

bool cmp(const treee &a, const treee &b) { return a.h < b.h; }
void build(int v, int l, int r) {
    tree[v].a = l;
    tree[v].b = r;
    tree[v].h = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) + 1, mid + 1, r);
}
void insert(int v, int l, int r, int x) {
    if (l > tree[v].b || r < tree[v].a)
        return;
    if (l <= tree[v].a && r >= tree[v].b) {
        tree[v].h = x;
        return;
    }
    if (tree[v].h > 0) {
        tree[v << 1].h = tree[(v << 1) + 1].h = tree[v].h;
        tree[v].h = -1;
    } //标记下传
    insert(v << 1, l, r, x);
    insert((v << 1) + 1, l, r, x);
    if (tree[v << 1].h == tree[(v << 1) + 1].h)
        tree[v].h = tree[v << 1].h; //标记上传,合并
}
void calc(int v) {
    if (tree[v].h > 0) {
        ans += tree[v].h * (long long)(b[tree[v].b + 1] - b[tree[v].a]);
        return;
    }
    if (tree[v].a == tree[v].b)
        return;
    calc(v << 1);
    calc((v << 1) + 1);
}
int main() {
    int n, tot;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].h);
        b[i] = a[i].a;
        b[i + n] = a[i].b;
    }
    sort(b + 1, b + (n << 1) + 1);
    tot = unique(b + 1, b + (n << 1) + 1) - b - 1;
    build(1, 1, tot);
    for (int i = 1; i <= n; i++) {
        a[i].a = lower_bound(b + 1, b + tot + 1, a[i].a) - b;
        a[i].b = lower_bound(b + 1, b + tot + 1, a[i].b) - b;
    } //离散化
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        insert(1, a[i].a, a[i].b - 1, a[i].h); //记住转点
    calc(1);
    printf("%lld", ans);
    return 0;
}