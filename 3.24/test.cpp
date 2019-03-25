#include <iostream>
#include <set>
#include <utility>

int const Maxn = 100005, Inf = 2147483646;
int n, m;
std::set<std::pair<int, int>> s[Maxn];

struct segment_tree {
    int l, r, s, f;
} tree[Maxn * 10];

inline void pushup(int v) { tree[v].s = tree[v << 1].s + tree[(v << 1) | 1].s; }
void update(int v, int x);
void pushdown(int v);
void build(int v, int l, int r);
void modify(int v, int l, int r, int ql, int qr, int val);
int query(int v, int l, int r, int ql, int qr);
void add(int l, int r, int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
        s[i].insert(std::make_pair(Inf, Inf));
    while (m--) {
        int opt;
        std::cin >> opt;
        if (opt == 1) {
            int xi, val, ki;
            std::cin >> xi >> val >> ki;
            int l = std::max(1, xi - ki), r = std::min(n, xi + ki);
            add(l, r, val);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}

void update(int v, int x) {
    if (x == 1)
        tree[v].s = tree[v].r - tree[v].l + 1;
    else
        tree[v].s = 0;
    tree[v].f = x;
}

void pushdown(int v) {
    if (tree[v].f == -1)
        return;
    update(v << 1, tree[v].f);
    update((v << 1) | 1, tree[v].f);
    tree[v].f = -1;
}

void build(int v, int l, int r) {
    tree[v].l = l, tree[v].r = r;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

void modify(int v, int l, int r, int ql, int qr, int val) {
    if (ql > qr)
        return;
    if (ql <= l && r <= qr) {
        update(v, val);
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(v);
    if (ql <= mid)
        modify(v << 1, l, mid, ql, qr, val);
    if (qr > mid)
        modify((v << 1) | 1, mid + 1, r, ql, qr, val);
    pushup(v);
}

int query(int v, int l, int r, int ql, int qr) {
    if (ql > qr)
        return 0;
    if (ql <= l && r <= qr)
        return tree[v].s;
    int ans = 0, mid = (l + r) >> 1;
    pushdown(v);
    if (ql <= mid)
        ans += query(v << 1, l, mid, ql, qr);
    if (qr > mid)
        ans += query((v << 1) | 1, mid + 1, r, ql, qr);

    return ans;
}

void add(int l, int r, int x) {
    int pl = l, pr = r;
    std::set<std::pair<int, int>> &ss = s[x];
    std::set<std::pair<int, int>>::iterator it =
        ss.lower_bound(std::make_pair(l, r));
    modify(1, 1, n, l, r, 1);
    if (it != ss.begin()) {
        it--;
        if (it->second > r) {
            modify(1, 1, n, std::max(pl, it->first), std::min(pr, it->second), 0);
        }
        if (it->second >= l) {
            l = std::min(l, it->first), r = std::max(r, it->second);
            modify(1, 1, n, std::max(pl, it->first), std::min(pr, it->second), 0);
            ss.erase(it++);
        }
    }
    it = ss.lower_bound(std::make_pair(l, r));
    while ((it->second >= l && it->second <= r) ||
           (it->first >= l && it->first <= r)) {
        l = std::min(l, it->first), r = std::max(r, it->second);
        modify(1, 1, n, std::max(pl, it->first), std::min(pr, it->second), 0);
        ss.erase(it++);
    }
    ss.insert(std::make_pair(l, r));
}