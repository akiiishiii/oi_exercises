// 1334.cpp
#include <iostream>
#include <algorithm>

struct query {
    int l, r, ans;
} q[10010];

int n, m, t;
int a[20010], prt[20010], d[20010];

int search(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        char str[5];
        std::cin >> q[i].l >> q[i].r >> str;
        q[i].ans = (str[0] == 'o' ? 1 : 0);
        a[++t] = q[i].l - 1;
        a[++t] = q[i].r;
    }
    std::sort(a + 1, a + t + 1);
    n = std::unique(a + 1, a + t + 1) - a - 1;
    for (int i = 1; i <= n; i++) prt[i] = i;
    for (int i = 1; i <= m; i++) {
        int x = std::lower_bound(a + 1, a + n + 1, q[i].l - 1) - a;
        int y = std::lower_bound(a + 1, a + n + 1, q[i].r) - a;
        int p1 = search(x), p2 = search(y);
        if (p1 == p2) {
            if ((d[x] ^ d[y]) != q[i].ans) {
                std::cout << i - 1 << '\n';
                return 0;
            }
        } else {
            prt[p1] = p2;
            d[p1] = d[x] ^ d[y] ^ q[i].ans;
        }
    }
    std::cout << m << '\n';
    return 0;
}

int search(int x) {
    if (x == prt[x])
		return x;
    int root = search(prt[x]);
    d[x] ^= d[prt[x]];
    return prt[x] = root;
}
