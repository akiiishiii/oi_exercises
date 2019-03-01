// 3402.cpp
#include <iostream>
#include <cstring>

int const Maxn = 2005, Maxm = 9005;
int head[Maxn], ver[Maxm << 1], flow[Maxm << 1], Next[Maxm << 1];
int dis[Maxn], gap[Maxn], indeg[Maxn] = {0}, outdeg[Maxn] = {0};
int tot = 1, n, m, s, t;

int dfs(int x, int maxf);
int sap();
inline void add(int s, int t, int p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    s = 2 * n + 1, t = 2 * n + 2;
    for (int i = 1, x; i <= n; i++)
        std::cin >> x, add(i, i + n, x);
    for (int i = 1, x, y; i <= m; i++)
        std::cin >> x >> y, add(x + n, y, 0x7fffffff), indeg[y]++, outdeg[x]++;
    for (int i = 1; i <= n; i++) {
        if (!indeg[i])
            add(s, i, 0x7fffffff);
        if (!outdeg[i])
            add(i + n, t, 0x7fffffff);
    }
    n = t;
    std::cout << sap() << '\n';
    return 0;
}

int dfs(int x, int maxf) {
    if (x == t || !maxf)
        return maxf;
    int ret = 0;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (flow[i] && dis[x] == dis[y] + 1) {
            int dlt = dfs(y, std::min(maxf, flow[i]));
            flow[i] -= dlt;
            flow[i ^ 1] += dlt;
            ret += dlt;
            maxf -= dlt;
            if (dis[s] == n || !maxf)
                return ret;
        }
    }
    if (!(--gap[dis[x]]))
        dis[s] = n;
    gap[++dis[x]]++;
    return ret;
}

int sap() {
    int ret = 0;
    memset(dis, 0, sizeof dis);
    memset(gap, 0, sizeof gap);
    gap[0] = n;
    while (dis[s] < n)
        ret += dfs(s, 1 << 30);
    return ret;
}

inline void add(int s, int t, int p) {
    ver[++tot] = t, flow[tot] = p, Next[tot] = head[s], head[s] = tot;
    ver[++tot] = s, flow[tot] = 0, Next[tot] = head[t], head[t] = tot;
}