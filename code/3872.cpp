// 3872.cpp
#include <iostream>

int const Maxn = 1000010;

struct heap {
    int bj;
    int key;
    int l, r;
    int prt, id;
} a[Maxn];

int search(int x) { return (a[x].prt == a[x].id) ? a[x].prt : a[x].prt = search(a[x].prt); }
int merge(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::string op;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].key;
        a[i].id = a[i].prt = i;
        a[i].l = a[i].r = 0;
        a[i].bj = false;
    }
    std::cin >> m;
    for (int i = 1, x, y, fx, fy; i <= m; i++) {
        std::cin >> op;
        if (op[0] == 'M') {
            std::cin >> x >> y;
            if (a[x].bj || a[y].bj)
                continue;
            fx = search(x), fy = search(y);
            if (fx == fy)
                continue;
            a[fx].prt = a[fy].prt = merge(fx, fy);
        } else {
            std::cin >> x;
            if (a[x].bj) {
                std::cout << "0\n";
                continue;
            }
            fx = search(x);
            a[fx].bj = true;
            std::cout << a[fx].key << "\n";
            a[fx].prt = merge(a[fx].l, a[fx].r);
            a[a[fx].prt].prt = a[fx].prt;
        }
    }
    return 0;
}

int merge(int x, int y) {
    if (!(x && y))
        return x + y;
    if (a[x].key > a[y].key)
        std::swap(x, y);
    a[x].r = merge(a[x].r, y);
    std::swap(a[x].l, a[x].r);
    return x;
}