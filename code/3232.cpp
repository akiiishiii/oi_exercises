// 3232.cpp
#include <algorithm>
#include <cstring>
#include <iostream>

int const Maxn = 100010, Maxm = 300010, Maxk = 22;
int Next[Maxm << 1], head[Maxn], ver[Maxm << 1], edge[Maxm << 1];
int n, m, dlt = 0x7fffffff, tot;
long long ans;
int p[Maxn][Maxk], max1[Maxn][Maxk], max2[Maxn][Maxk], dep[Maxn], prt[Maxn];
bool mark[Maxm];

struct edges {
    int x, y, v;
    bool operator<(edges const &w) const { return v < w.v; }
    edges() = default;
    ~edges() = default;
    edges(int u, int v, int w) : x(u), y(v), v(w) {}
} e[Maxm];

inline void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
int search(int x) { return prt[x] == x ? x : prt[x] = search(prt[x]); }
void dfs(int x);
void kruskal();
int lca(int x, int y);
void query(int x, int u, int v);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, x, y, z; i <= m; i++)
        std::cin >> x >> y >> z, e[i] = edges(x, y, z);
    kruskal(), dfs(1);
    for (int i = 1; i <= m; i++)
        if (!mark[i]) {
            int x = e[i].x, y = e[i].y, v = e[i].v, u = lca(x, y);
            query(x, u, v), query(y, u, v);
            //std::cout << dlt << '\n';
        }
    //std::cout << ans << '\n';
    std::cout << ans + dlt << '\n';
    return 0;
}

void dfs(int x) {
    for (int i = 1; i <= 18; i++) {
        p[x][i] = p[p[x][i - 1]][i - 1];
        int tmp1 = max1[x][i - 1], tmp2 = max1[p[x][i - 1]][i - 1];
        max1[x][i] = std::max(tmp1, tmp2);
        max2[x][i] = std::max(max2[x][i - 1], max2[p[x][i - 1]][i - 1]);
        if (tmp1 != tmp2)
            max2[x][i] = std::max(max2[x][i], std::min(tmp1, tmp2));
    }
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i], z = edge[i];
        if (y != p[x][0]) {
            dep[y] = dep[x] + 1, p[y][0] = x;
            max1[y][0] = z, dfs(y);
        }
    }
}

void kruskal() {
    std::sort(e + 1, e + 1 + m);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    for (int i = 1; i <= m && cnt < n - 1; i++) {
        int x = e[i].x, y = e[i].y, v = e[i].v;
        if (search(x) == search(y))
            continue;
        cnt++, prt[search(x)] = search(y), ans += v, mark[i] = true;
        add(x, y, v), add(y, x, v);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y])
        std::swap(x, y);
    for (int h = dep[x] - dep[y], i = 18; i >= 0 && h; i--)
        if (h & (1 << i))
            x = p[x][i];
    if (x == y)
        return x;
    for (int i = 18; i >= 0; i--)
        if (p[x][i] != p[y][i])
            x = p[x][i], y = p[y][i];
    return p[x][0];
}

void query(int x, int y, int z) {
    int maxx = 0, maxs = 0;
    for (int i = 18, h = dep[x] - dep[y]; i >= 0; i--)
        if (h & (1 << i)) {
            if (max1[x][i] > maxx)
                maxs = maxx, maxx = max1[x][i];
            maxs = std::max(maxs, max2[x][i]), h -= (1 << i);
        }
    if (z == maxx)
        dlt = std::min(dlt, z - maxs);
    else
        dlt = std::min(dlt, z - maxx);
}