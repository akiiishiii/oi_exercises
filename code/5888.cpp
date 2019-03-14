// 5888.cpp
#include <iostream>
#include <utility>

int const Maxn = 1000010;
long long q, m;
std::pair<long long, long long> qs[Maxn];

struct segment_tree {
    long long l, r, v;
} tree[Maxn << 1];

void build(long long v, long long l, long long r);
void update(long long v, long long l, long long r, long long d);
void query(long long v, long long k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> q >> m;
        build(1, 1, q);
        for (long long i = 1, op, x; i <= q; i++) {
            std::cin >> op >> x;
            if (op == 1)
                qs[i] = std::make_pair(i, x);
            else {
                update(1, qs[x].first, i - 1, qs[x].second);
                qs[x] = std::make_pair(0, 0);
            }
        }
        for (long long i = 1; i <= q; i++)
            if (qs[i].first)
                update(1, qs[i].first, q, qs[i].second);
        for (long long i = 1; i <= q; i++)
            qs[i] = std::make_pair(0, 0);
        query(1, 1);
    }
    return 0;
}

void build(long long v, long long l, long long r) {
    tree[v].l = l, tree[v].r = r, tree[v].v = 1;
    if (l == r)
        return;
    long long mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

void update(long long v, long long l, long long r, long long d) {
    if (tree[v].l > r || tree[v].r < l)
        return;
    if (l <= tree[v].l && tree[v].r <= r) {
        tree[v].v = tree[v].v * d % m;
        return;
    }
    update(v << 1, l, r, d);
    update((v << 1) | 1, l, r, d);
}

void query(long long v, long long k) {
    k = k * tree[v].v % m;
    if (tree[v].l == tree[v].r) {
        std::cout << k << '\n';
        return;
    }
    query(v << 1, k);
    query((v << 1) | 1, k);
}