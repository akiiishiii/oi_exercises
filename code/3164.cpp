// 3164.cpp
#include <iostream>

struct heap {
    int key;
    int l, r, prt;
} a[100010];

int search(int x) { return (a[x].prt == x) ? a[x].prt : a[x].prt = search(a[x].prt); }
int merge(int x, int y);
int del(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].key;
        a[i].prt = i;
        a[i].l = a[i].r = 0;
    }
    std::cin >> m;
    for (int i = 1, x, y, fx, fy, tmp; i <= m; i++) {
        std::cin >> x >> y;
        x = search(x), y = search(y);
        if (x == y) {
            std::cout << "-1\n";
            continue;
        }
        fx = del(x), fy = del(y);
        tmp = merge(fx, fy);
        tmp = merge(tmp, x), tmp = merge(tmp, y);
        a[tmp].prt = a[x].prt = a[y].prt = tmp;
        std::cout << a[tmp].key << '\n';
    }
    return 0;
}

int merge(int x, int y) {
    if (!x || !y)
        return x + y;
    if (a[x].key < a[y].key)
        std::swap(x, y);
    a[x].r = merge(a[x].r, y);
    std::swap(a[x].l, a[x].r);
    return x;
}

int del(int x) {
    a[x].key >>= 1;
    int ret = merge(a[x].l, a[x].r);
    a[x].l = a[x].r = 0;
    return ret;
}