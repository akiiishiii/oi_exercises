// 4553.cpp
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>

int const Maxn = 50001;
int n, m, k, pos[Maxn], c[Maxn];
long long s[Maxn], tmp;

struct query {
    int l, r, id;
    long long ans;
} qs[Maxn];

struct comp : public std::binary_function<query, query, bool> {
    bool operator()(query const &a, query const &b) {
        return ((pos[a.l] == pos[b.l]) ? (a.r < b.r) : (pos[a.l] < pos[b.l]));
    }
};

struct comp_by_id : public std::binary_function<query, query, bool> {
    bool operator()(query const &a, query const &b) { return (a.id < b.id); }
};

inline long long sqr(long long x) { return x * x; }
void update(int p, int d);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> c[i];
    int blk = int(sqrt(n));
    for (int i = 1; i <= n; i++)
        pos[i] = (i - 1) / blk + 1;
    for (int i = 1; i <= m; i++) {
        std::cin >> qs[i].l >> qs[i].r;
        qs[i].id = i;
    }
    std::sort(qs + 1, qs + m + 1, comp());
    for (int i = 1, l = 1, r = 0; i <= m; i++) {
        for (; r < qs[i].r; r++)
            update(r + 1, 1);
        for (; r > qs[i].r; r--)
            update(r, -1);
        for (; l < qs[i].l; l++)
            update(l, -1);
        for (; l > qs[i].l; l--)
            update(l - 1, 1);
        qs[i].ans = tmp;
    }
    std::sort(qs + 1, qs + m + 1, comp_by_id());
    for (int i = 1; i <= m; i++)
        std::cout << qs[i].ans << '\n';
    return 0;
}

void update(int p, int d) {
    tmp -= sqr(s[c[p]]);
    s[c[p]] += d;
    tmp += sqr(s[c[p]]);
}