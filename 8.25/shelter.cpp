// shelter.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("shelter.in");
std::ofstream out("shelter.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

long long const Maxn = 100100;
long long head[Maxn], ver[Maxn << 1], edge[Maxn << 1], Next[Maxn << 1];
long long n, m, a, b, c, tot = 0;
long long f[Maxn][2], son[Maxn], dep[Maxn], fa[Maxn][21], st[Maxn][21], g[Maxn],
    val[Maxn];

void add(long long x, long long y, long long z);
void dfs1(long long x, long long p);
void dfs2(long long x, long long p, long long len);
void pre();
long long get_lca(long long x, long long y);
long long get_low(long long x, long long d, long long lca, long long q);
long long get_high(long long x, long long d, long long lca, long long q);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m >> a >> b >> c;
    for (long long i = 1; i < n; ++i) {
        long long u, v, w;
        in >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    for (long long i = 1; i <= n; ++i)
        val[i] = (std::max(g[i], f[i][0]) + a) * b % c;
    pre();
    while (m--) {
        long long u, v, q;
        in >> u >> v >> q;
        long long lca = get_lca(u, v);
        long long ans = -1;
        if (val[u] >= q)
            ans = u;
        if (ans == -1) {
            long long d = 0;
            while ((1 << d) <= dep[u])
                d++;
            d--;
            ans = get_low(u, d, lca, q);
        }
        if (ans == -1) {
            long long d = 0;
            while ((1 << d) <= dep[v])
                d++;
            d--;
            ans = get_high(v, d, lca, q);
        }
        if (ans == -1 && val[v] >= q)
            ans = v;
        out << ans << '\n';
    }
    return 0;
}

void add(long long x, long long y, long long z) {
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void dfs1(long long x, long long p) {
    fa[x][0] = p;
    for (long long i = head[x]; i; i = Next[i]) {
        long long y = ver[i], z = edge[i];
        if (y == p)
            continue;
        dep[y] = dep[x] + 1;
        dfs1(y, x);
        if (f[y][0] + z > f[x][0]) {
            f[x][1] = f[x][0];
            f[x][0] = f[y][0] + z;
            son[x] = y;
        } else if (f[y][0] + z > f[x][1])
            f[x][1] = f[y][0] + z;
    }
}

void dfs2(long long x, long long p, long long len) {
    if (x != son[p])
        g[x] = std::max(g[x], f[p][0]);
    else
        g[x] = std::max(g[x], f[p][1]);
    g[x] = std::max(g[x], g[p]) + len;
    for (long long i = head[x]; i; i = Next[i]) {
        long long y = ver[i], z = edge[i];
        if (y == p)
            continue;
        dfs2(y, x, z);
    }
}

void pre() {
    for (long long i = 1; i <= n; ++i)
        st[i][0] = val[fa[i][0]];
    for (long long i = 1; i <= 20; ++i) {
        for (long long j = 1; j <= n; ++j) {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
            st[j][i] = std::max(st[fa[j][i - 1]][i - 1], st[j][i - 1]);
        }
    }
}

long long get_lca(long long x, long long y) {
    if (dep[x] < dep[y])
        std::swap(x, y);
    for (long long i = 20; i >= 0; i--)
        if (dep[x] - (1 << i) >= dep[y])
            x = fa[x][i];
    if (x == y)
        return x;
    for (long long i = 20; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

long long get_low(long long x, long long d, long long lca, long long q) {
    if (dep[x] <= dep[lca])
        return -1;
    while ((dep[fa[x][d]] < dep[lca]) && d)
        d--;
    if (st[x][d] < q)
        return get_low(fa[x][d], d - 1, lca, q);
    for (long long i = d - 1; i >= 0; i--)
        if (st[x][i] < q)
            x = fa[x][i];
    return fa[x][0];
}

long long get_high(long long x, long long d, long long lca, long long q) {
    if (dep[x] <= dep[lca])
        return -1;
    while ((dep[fa[x][d]] < dep[lca]) && d)
        d--;
    long long ret = get_high(fa[x][d], d - 1, lca, q);
    if (~ret)
        return ret;
    if (st[x][d] < q)
        return -1;
    for (long long i = d - 1; i >= 0; i--)
        if (st[fa[x][i]][i] >= q)
            x = fa[x][i];
    return fa[x][0];
}