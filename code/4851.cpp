// 4851.cpp
#include <iostream>

int const Maxn = 100010;
int n, m, tot;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1];
int son[Maxn], maxd[Maxn], top[Maxn], dep[Maxn], prt[Maxn];

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs1(int x);
void dfs2(int x, int tp);
int lca(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, x, y; i < n; i++) {
        std::cin >> x >> y;
        add(x, y), add(y, x);
    }
    dfs1(1);
    dfs2(1, 1);
    for (int i = 1, x, y; i <= m; i++) {
        std::cin >> x >> y;
        std::cout << lca(x, y) << '\n';
    }
    return 0;
}

void dfs1(int x) {
    dep[x] = dep[prt[x]] + 1;
    maxd[x] = dep[x];
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y != prt[x]) {
            prt[y] = x;
            dfs1(y);
            maxd[x] = std::max(maxd[y], maxd[x]);
            if (maxd[y] > maxd[son[x]])
                son[x] = y;
        }
    }
}

void dfs2(int x, int tp) {
    top[x] = tp;
    if (son[x])
        dfs2(son[x], tp);
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y != prt[x] && y != son[x])
            dfs2(y, y);
    }
}

int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            std::swap(x, y);
        x = prt[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}