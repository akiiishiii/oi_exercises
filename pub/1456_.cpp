#include <algorithm>
#include <iostream>

struct node {
    int l, r, o;
    bool operator<(node const &p) const { return o < p.o; }
} a[44851];

int f[301], n, m, s;

int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

void kus(int k);

int main(int argc, const char * argv[]) {
    std::cin >> n >> m;
    s = 10000000;
    for (int i = 1; i <= m; i++)
        std::cin >> a[i].l >> a[i].r >> a[i].o;
    if (m >= n - 1) {
        std::sort(a + 1, a + 1 + m);
        for (int i = 1; m - i + 1 >= n - 1; i++)
            kus(i);
    }
    if (s == 10000000)
        s = -1;
    std::cout << s << '\n';
}

void kus(int k) {
    int x, y, p, h = 0;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = k; i <= m && h < n - 1; i++) {
        x = find(a[i].l);
        y = find(a[i].r);
        if (x != y)
            f[y] = x, p = a[i].o - a[k].o, h++;
    }
    if (h >= n - 1)
        s = std::min(s, p);
}
