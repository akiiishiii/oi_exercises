// 2923.cpp
#include <algorithm>
#include <iostream>

int const Maxn = 40005, Maxm = 200005;
double const eps = 1e-7;
double sum = 0, ans = 1e80, ret = 0, val[Maxn], edge[Maxm], f[Maxn];
int n, m, tot = 0, cnt = 0, head[Maxn], prt[Maxn], son[Maxn], ver[Maxm], Next[Maxm];

struct edges {
    int u, v;
    double w;
    bool operator<(edges const &p) const { return w - p.w < eps; }
} e[Maxm];

inline void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
int search(int x) { return prt[x] == x ? x : prt[x] = search(prt[x]); }
void kruskal();
void dfs(int x, int p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
        std::cin >> e[i].u >> e[i].v >> e[i].w;
    kruskal();
    dfs(1, 0);
    std::cout << ret << '\n';
    return 0;
}

void kruskal() {
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    std::sort(e + 1, e + m + 1);
    for (int i = 1; i <= m; i++) {
        int f1 = search(e[i].u), f2 = search(e[i].v);
        if (f1 == f2)
            continue;
        prt[f1] = f2, cnt++;
        add(e[i].u, e[i].v, e[i].w);
        add(e[i].v, e[i].u, e[i].w);
        son[e[i].u]++, son[e[i].v]++;
        sum += e[i].w;
        if (cnt == n - 1)
            break;
    }
}

void dfs(int x, int p) {
    f[x] = 0;
    double avg = sum / (1.0 * son[x]), temp = 0;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i], z = edge[i];
        if (y == p)
            continue;
        dfs(y, x);
        val[x] += (z + f[y] - avg) * (z + f[y] - avg);
        f[x] += (z + f[y]);
        temp += (z + f[y]);
    }
    if (std::abs(sum - temp) > eps)
        val[x] += (sum - temp - avg) * (sum - temp - avg);
    if (son[x] != 1 && (val[x] - ans < eps || (val[x] == ans && x < ret)))
        ans = val[x], ret = x;
    return;
}