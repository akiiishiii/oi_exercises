// 3350.cpp
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>

int const Maxn = 50001;
int n, m, pos[Maxn], c[Maxn];
long long s[Maxn], tmp;

struct dat {
    int l, r, id;
    long long a, b;
} ds[Maxn];

struct comp : public std::binary_function<dat, dat, bool> {
    bool operator()(dat const &a, dat const &b) {
        return ((pos[a.l] == pos[b.l]) ? (a.r < b.r) : (pos[a.l] < pos[b.l]));
    }
};

struct comp_by_id : public std::binary_function<dat, dat, bool> {
    bool operator()(dat const &a, dat const &b) { return (a.id < b.id); }
};

long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long sqr(long long x) { return x * x; }
void update(int p, int d);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> c[i];
    int blk = int(sqrt(n));
    for (int i = 1; i <= n; i++)
        pos[i] = (i - 1) / blk + 1;
    for (int i = 1; i <= m; i++) {
        std::cin >> ds[i].l >> ds[i].r;
        ds[i].id = i;
    }
    std::sort(ds + 1, ds + m + 1, comp());
    for (int i = 1, l = 1, r = 0; i <= m; i++) {
        for (; r < ds[i].r; r++)
            update(r + 1, 1);
        for (; r > ds[i].r; r--)
            update(r, -1);
        for (; l < ds[i].l; l++)
            update(l, -1);
        for (; l > ds[i].l; l--)
            update(l - 1, 1);
        if (ds[i].l == ds[i].r)
            ds[i].a = 0, ds[i].b = 1;
        else {
            ds[i].a = tmp - (ds[i].r - ds[i].l + 1);
            ds[i].b = (long long)(ds[i].r - ds[i].l + 1) * (ds[i].r - ds[i].l);
            long long dgcd = gcd(ds[i].a, ds[i].b);
            ds[i].a /= dgcd;
            ds[i].b /= dgcd;
        }
    }
    std::sort(ds + 1, ds + m + 1, comp_by_id());
    for (int i = 1; i <= m; i++)
        std::cout << ds[i].a << '/' << ds[i].b << '\n';
    return 0;
}

void update(int p, int d) {
    tmp -= sqr(s[c[p]]);
    s[c[p]] += d;
    tmp += sqr(s[c[p]]);
}