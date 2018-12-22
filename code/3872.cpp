// 3872.cpp
#include <iostream>

struct heap {
    int bj, key, l, r, prt, id;
} a[1000010];

int findprt(int x) {
    if (a[x].prt == a[x].id)
        return a[x].id;
    a[x].prt = findprt(a[x].prt);
    return a[x].prt;
}

int merge(int x, int y) {
    if (!x || !y)
        return x + y;
    if (a[x].key > a[y].key)
        std::swap(x, y);
    a[x].r = merge(a[x].r, y);
    std::swap(a[x].l, a[x].r);
    return x;
}

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].key);
        a[i].id = a[i].prt = i;
        a[i].l = a[i].r = a[i].bj = 0;
    }
    char order[5];
    scanf("%d", &m);
    for (int i = 1, x, y, fx, fy; i <= m; i++) {
        scanf("%s", order);
        if (order[0] == 'M') {
            scanf("%d%d", &x, &y);
            if (a[x].bj || a[y].bj)
                continue;
            fx = findprt(x);
            fy = findprt(y);
            if (fx == fy)
                continue;
            a[fx].prt = a[fy].prt = merge(fx, fy);
        } else {
            scanf("%d", &x);
            if (a[x].bj) {
                printf("0\n");
                continue;
            }
            fx = findprt(x);
            a[fx].bj = 1;
            printf("%d\n", a[fx].key);
            a[fx].prt = merge(a[fx].l, a[fx].r);
            a[a[fx].prt].prt = a[fx].prt;
        }
    }
    return 0;
}