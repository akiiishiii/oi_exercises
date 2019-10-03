// forest.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("forest.in");
std::ofstream out("forest.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 1e3 + 5, Mod = 1e9 + 7;
int n, tot;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1];
int a[Maxn], b[Maxn], x[Maxn], y[Maxn], prt[Maxn], aa[Maxn], ans[Maxn];
int pprt[Maxn], dep[Maxn], top[Maxn], siz[Maxn], son[Maxn], h[Maxn];
std::pair<int, int> p[Maxn];

int power(int a, int b);
void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
int search(int x) { return x == prt[x] ? x : prt[x] = search(prt[x]); }
void dfs1(int x, int p, int depth);
void dfs2(int x, int t);
inline int lca(int x, int y);
inline int calc(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n;
    ans[0] = 1;
    for (int i = 1; i <= n; i++) {
        in >> a[i];
        aa[i] = a[i];
        p[i] = std::make_pair(i, i);
        prt[i] = i;
        ans[0] = 1ll * a[i] * ans[0] % Mod;
    }
    for (int i = 1; i < n; i++) {
        in >> x[i] >> y[i];
        add(x[i], y[i]), add(y[i], x[i]);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    for (int i = n - 1; i; i--)
        in >> b[i];
    for (int i = 1; i < n; i++) {
        int p1 = search(x[b[i]]), p2 = search(y[b[i]]);
        int a1 = aa[p1], a2 = aa[p2];
        int x1 = p[p1].first, y1 = p[p1].second, x2 = p[p2].first,
            y2 = p[p2].second;
        int a3 = calc(x1, x2), a4 = calc(x1, y2), a5 = calc(y1, x2),
            a6 = calc(y1, y2);
        aa[p1] = std::max(std::max(std::max(a3, a4), a1),
                          std::max(std::max(a5, a6), a2));
        prt[p2] = p1;
        if (aa[p1] == a1)
            p[p1] = std::make_pair(x1, y1);
        else if (aa[p1] == a2)
            p[p1] = std::make_pair(x2, y2);
        else if (aa[p1] == a3)
            p[p1] = std::make_pair(x1, x2);
        else if (aa[p1] == a4)
            p[p1] = std::make_pair(x1, y2);
        else if (aa[p1] == a5)
            p[p1] = std::make_pair(y1, x2);
        else if (aa[p1] == a6)
            p[p1] = std::make_pair(y1, y2);
        ans[i] = 1ll * ans[i - 1] * power(a1, Mod - 2) % Mod *
                 power(a2, Mod - 2) % Mod * aa[p1] % Mod;
    }
    for (int i = n - 1; i >= 0; i--)
        out << ans[i] << '\n';
    return 0;
}

int power(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1)
            ret = 1ll * ret * a % Mod;
        a = 1ll * a * a % Mod;
        b >>= 1;
    }
    return ret;
}

void dfs1(int x, int p, int depth) {
    dep[x] = depth;
    pprt[x] = p;
    siz[x] = 1;
    h[x] = h[p] + a[x];
    for (int i = head[x]; i; i = Next[i]) {
        if (ver[i] == p)
            continue;
        dfs1(ver[i], x, depth + 1);
        siz[x] += siz[ver[i]];
        if (siz[ver[i]] > siz[son[x]])
            son[x] = ver[i];
    }
}

void dfs2(int x, int t) {
    top[x] = t;
    if (son[x])
        dfs2(son[x], t);
    for (int i = head[x]; i; i = Next[i])
        if (ver[i] ^ pprt[x] && ver[i] ^ son[x])
            dfs2(ver[i], ver[i]);
}

inline int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            std::swap(x, y);
        x = pprt[top[x]];
    }
    if (dep[x] > dep[y])
        std::swap(x, y);
    return x;
}

inline int calc(int x, int y) {
    int tmp = lca(x, y);
    return h[x] - h[pprt[tmp]] + h[y] - h[pprt[tmp]] - a[tmp];
}