// 2737.cpp
#include <cstdio>
#include <iostream>

int const Maxn = 4005, Maxm = 60005;
int head[Maxn], ver[Maxm << 1], flow[Maxm << 1], Next[Maxm << 1], mark[Maxm << 1], tot = 1;
int gap[Maxn], dis[Maxn];
int low[Maxn], dfn[Maxn], stack[Maxn], c[Maxn], sign, cnt, scc;
bool instack[Maxn];
int n, m, s, t;

struct edge {
    int x, y, flow;
    int t1 = 0, t2 = 0;
} w[Maxm];

inline void add(int s, int t, int p, int m);
int dfs(int x, int maxf);
int sap();
void tarjan(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m >> s >> t;
    for (int i = 1, x, y, z; i <= m; i++) {
        std::cin >> x >> y >> z;
        w[i] = (edge){x, y, z};
        add(x, y, z, i);
    }
    sap();
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int x = 1; x <= n; x++)
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i];
            if (!flow[i] && mark[i] && c[x] != c[y]) {
                w[mark[i]].t1 = 1;
                if (c[x] == c[s] && c[y] == c[t])
                    w[mark[i]].t2 = 1;
            }
        }
    for (int i = 1; i <= m; i++)
        std::cout << w[i].t1 << ' ' << w[i].t2 << '\n';
    return 0;
}

inline void add(int s, int t, int p, int m) {
    ver[++tot] = t, flow[tot] = p, mark[tot] = m, Next[tot] = head[s], head[s] = tot;
    ver[++tot] = s, flow[tot] = 0, mark[tot] = 0, Next[tot] = head[t], head[t] = tot;
}

int dfs(int x, int maxf) {
    int ret = 0;
    if (x == t)
        return maxf;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (flow[i] > 0 && dis[x] == dis[y] + 1) {
            int t = dfs(y, std::min(maxf, flow[i]));
            maxf -= t;
            ret += t;
            flow[i] -= t;
            flow[i ^ 1] += t;
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
    int ans = 0;
    gap[0] = n;
    while (dis[s] < n)
        ans += dfs(s, 1 << 30);
    return ans;
}

void tarjan(int x) {
    low[x] = dfn[x] = ++sign;
    stack[++cnt] = x;
    instack[x] = true;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (!flow[i])
            continue;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = std::min(low[x], low[y]);
        } else if (instack[y])
            low[x] = std::min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x]) {
        scc++;
        int t;
        do {
            t = stack[cnt--];
            c[t] = scc;
            instack[t] = false;
        } while (t != x);
    }
}