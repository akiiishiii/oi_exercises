// 1529.cpp
#include <cstring>
#include <iostream>

int const Maxn = 810, Maxm = 20010;
int head[Maxn], ver[Maxm << 1], flow[Maxm << 1], Next[Maxm << 1];
int dis[Maxn], gap[Maxn];
bool vis[Maxn];
int tot = 1, n, m, s, t, cnt = 0;

int dfs(int x, int maxf);
void dfs1(int a);
void dfs2(int a);
int sap();
inline void add(int s, int t, int p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m >> s >> t;
    for (int i = 1, x, y, z; i <= m; i++)
        std::cin >> x >> y >> z, add(x, y, z);
    sap();
    dfs1(s), dfs2(t);
    std::cout << (cnt == n ? "UNIQUE\n" : "AMBIGUOUS\n");
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

void dfs1(int a) {
    vis[a] = true;
    cnt++;
    for (int i = head[a]; i; i = Next[i]) {
        int j = ver[i];
        if (flow[i] && !vis[j])
            dfs1(j);
    }
}

void dfs2(int a) {
    vis[a] = true;
    cnt++;
    for (int i = head[a]; i; i = Next[i]) {
        int j = ver[i];
        if (flow[i ^ 1] && !vis[j])
            dfs2(j);
    }
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
    ver[++tot] = s, flow[tot] = p, Next[tot] = head[t], head[t] = tot;
}