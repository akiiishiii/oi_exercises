// 3864.cpp
#include <cstring>
#include <iostream>

int const Maxn = 510, Maxm = 20010;
int head[Maxn], ver[Maxm << 1], flow[Maxm << 1], Next[Maxm << 1];
int dis[Maxn], gap[Maxn];
bool vis[Maxn], f1[Maxn], f2[Maxn];
int n, m, s, t, tot = 1;

struct edge {
    int x, y;
} e[Maxm];

inline void add(int s, int t, int p);
int dfs(int x, int maxf);
int sap();
void dfs1(int u, int s);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    tot = 0, s = n, t = n + 1;
    memset(head, 0, sizeof(head));
    for (int i = 1, x, y, c; i <= m; i++) {
        std::cin >> x >> y >> c;
        if (!x)
            x = s;
        if (!y)
            y = s;
        if (x == n - 1)
            x = t;
        if (y == n - 1)
            y = t;
        add(x, y, c);
        e[i].x = x, e[i].y = y;
    }
    sap();
    dfs1(s, 1);
    memset(vis, false, sizeof vis);
    dfs1(t, 2);
    int ans = 0;
    for (int i = 1; i <= m; i++)
        if (f1[e[i].x] && f2[e[i].y])
            ans++;
    std::cout << ans << '\n';
    return 0;
}

inline void add(int s, int t, int p) {
    ver[++tot] = t, flow[tot] = p, Next[tot] = head[s], head[s] = tot;
    ver[++tot] = s, flow[tot] = 0, Next[tot] = head[t], head[t] = tot;
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

void dfs1(int u, int s) {
    if (s == 1)
        f1[u] = true;
    else
        f2[u] = true;
    vis[u] = true;
    for (int i = head[u]; i; i = Next[i])
        if (!vis[ver[i]] && ((s == 1 && flow[i] > 0) || (s == 2 && flow[i ^ 1] > 0)))
            dfs1(ver[i], s);
}