// iiidx.cpp 线段树 + 贪心 这么臭的题还有做的必要吗？(指样例数据
#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("iiidx.in");
std::ofstream out("iiidx.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 500005;
int n;
double k;
int d[Maxn], ans[Maxn], siz[Maxn], prt[Maxn], t[Maxn];

struct segment_tree {
    int minn, x;
} tree[Maxn << 2];

void pushup(int v);
void pushdown(int v);
void build(int v, int l, int r);
int query(int v, int l, int r, int k);
void modify(int v, int l, int r, int ql, int qr, int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> k;
    for (int i = 1; i <= n; i++)
        in >> d[i];
    std::sort(d + 1, d + 1 + n, std::greater<int>());
    for (int i = n - 1; i >= 1; i--)
        if (d[i] == d[i + 1])
            t[i] = t[i + 1] + 1;
        else
            t[i] = 0;
    for (int i = 1; i <= n; i++)
        prt[i] = i / k, siz[i] = 1;
    for (int i = n; i >= 1; i--)
        siz[prt[i]] += siz[i];
    build(1, 1, n);
    for (int i = 1, x; i <= n; i++) {
        if (prt[i] && prt[i] != prt[i - 1])
            modify(1, 1, n, ans[prt[i]], n, siz[prt[i]] - 1);
        x = query(1, 1, n, siz[i]);
        x += t[x];
        t[x]++;
        x -= (t[x] - 1);
        ans[i] = x;
        modify(1, 1, n, x, n, -siz[i]);
    }
    for (int i = 1; i <= n; i++)
        out << d[ans[i]] << ' ';
    out << '\n';
    std::cout << "nmsl\n";
    return 0;
}

void pushup(int v) {
    tree[v].minn = std::min(tree[v << 1].minn, tree[(v << 1) | 1].minn);
}

void pushdown(int v) {
    tree[v << 1].x += tree[v].x;
    tree[v << 1].minn += tree[v].x;
    tree[(v << 1) | 1].x += tree[v].x;
    tree[(v << 1) | 1].minn += tree[v].x;
    tree[v].x = 0;
}

void build(int v, int l, int r) {
    if (l == r) {
        tree[v].minn = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
    pushup(v);
}

int query(int v, int l, int r, int k) {
    if (l == r) {
        if (tree[v].minn >= k)
            return l;
        else
            return l + 1;
    }
    pushdown(v);
    int mid = (l + r) >> 1;
    if (k <= tree[(v << 1) | 1].minn)
        return query(v << 1, l, mid, k);
    else
        return query((v << 1) | 1, mid + 1, r, k);
}

void modify(int v, int l, int r, int ql, int qr, int x) {
    if (ql <= l && r <= qr) {
        tree[v].minn += x;
        tree[v].x += x;
        return;
    }
    pushdown(v);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        modify(v << 1, l, mid, ql, qr, x);
    if (qr > mid)
        modify((v << 1) | 1, mid + 1, r, ql, qr, x);
    pushup(v);
}