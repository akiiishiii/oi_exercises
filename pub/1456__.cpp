#include <cstring>
#include <iostream>
#include <algorithm>

struct node {
    int u, v, wt;
    bool operator<(node const &x) const { return wt < x.wt; }
} edge[44860];

int n, m, fa[310], ans;

int search(int x) { return fa[x] = (fa[x] != x) ? search(fa[x]) : x; }
int kruskal(int s);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    ans = 2147483647;
    std::cin >> n >> m;
    for (int i = 1, u, v, wt; i <= m; i++) {
        std::cin >> u >> v >> wt;
        edge[i].u = u, edge[i].v = v, edge[i].wt = wt;
    }
    std::sort(edge + 1, edge + m + 1);
    if (!n)
        return 0;
    for (int i = 1, t; i <= m; i++) {
        t = kruskal(i);
        if (t == -1)
            break;
        if (t < ans)
            ans = t;
        if (!ans)
            break;
    }
    if (ans == 2147483647)
        std::cout << "-1\n";
    else
        std::cout << ans << '\n';
    return 0;
}

int kruskal(int s) {
    int maxn = -2147483648, minn = 2147483647, cnt = 1;
    for (int i = 0; i < n; i++)
        fa[i] = i;
    for (int i = s, u, v, wt; i <= m; i++) {
        u = edge[i].u, v = edge[i].v, wt = edge[i].wt;
        if (search(u) == search(v))
            continue;
        fa[fa[u]] = fa[v];
        maxn = std::max(wt, maxn);
        minn = std::min(wt, minn);
        cnt++;
        if (cnt == n)
            break;
    }
    if (cnt < n)
        return -1;
    return maxn - minn;
}
