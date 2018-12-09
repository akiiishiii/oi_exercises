// 4207.cpp
#include <cstdio>
#include <cstring>
#include <iostream>

int const SIZE = 50005;
int head[SIZE], node[SIZE], Next[SIZE << 1], ver[SIZE << 1];
int dep[SIZE], prt[SIZE], size[SIZE], son[SIZE];
int seg[SIZE], top[SIZE], sum[SIZE];
int tot, n, m, p;

template <typename T>
inline T lowbit(T const &x) { return x & (-x); }
void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }

void dfs1(int x, int p) {
    dep[x] = dep[p] + 1;
    size[x] = 1;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        prt[y] = x;
        dfs1(y, x);
        size[x] += size[y];
        if (size[son[x]] < size[y])
            son[x] = y;
    }
}

void dfs2(int x, int t) {
    seg[x] = ++seg[0];
    top[x] = t;
    if (son[x])
        dfs2(son[x], top[x]);
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (top[y])
            continue;
        dfs2(y, y);
    }
}

int ask(int x) {
    int ret = 0;
    while (x) {
        ret += sum[x];
        x -= lowbit(x);
    }
    return ret;
}

void update(int x, int y) {
    while (x <= seg[0]) {
        sum[x] += y;
        x += lowbit(x);
    }
}

void UpRange(int x, int y, int z) {
    int fx = top[x], fy = top[y];
    while (fx != fy) {
        if (dep[fx] < dep[fy]) {
            std::swap(x, y);
            std::swap(fx, fy);
        }
        update(seg[fx], z);
        update(seg[x] + 1, -z);
        x = prt[fx];
        fx = top[x];
    }
    if (dep[x] > dep[y])
        std::swap(x, y);
    update(seg[x], z);
    update(seg[y] + 1, -z);
}

int main() {
    while (~scanf("%d%d%d", &n, &m, &p)) {
        memset(sum, 0, sizeof sum);
        memset(head, 0, sizeof head);
        tot = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &node[i]);
        for (int i = 1; i <= m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b);
            add(b, a);
        }
        dfs1(1, 1);
        dfs2(1, 1);
        for (int i = 1; i <= n; i++) {
            update(seg[i], node[i]);
            update(seg[i] + 1, -node[i]);
        }
        for (int i = 1; i <= p; i++) {
            char ch[10];
            int x, y, z;
            scanf("%s%d", ch, &x);
            if (ch[0] == 'I') {
                scanf("%d%d", &y, &z);
                UpRange(x, y, z);
            } else if (ch[0] == 'D') {
                scanf("%d%d", &y, &z);
                UpRange(x, y, -z);
            } else {
                printf("%d\n", ask(seg[x]));
            }
        }
    }
    return 0;
}
