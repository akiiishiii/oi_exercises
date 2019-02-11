// 2244.cpp
#include <cstring>
#include <iostream>

int const Maxn = 80005;
int head[Maxn], ver[Maxn * 4], flow[Maxn * 4], Next[Maxn * 4];
int gap[Maxn], dis[Maxn], v[Maxn], c[Maxn];
int tot = 1, n, m, s, t, sum = 0;

inline void add(int s, int t, int p);
int dfs(int x, int maxf);
int sap();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> c[i];
    for (int i = 1, a, b, d; i <= m; i++) {
        std::cin >> a >> b >> d;
        sum += d;
        v[i] = d;
        add(i, a + m, 1 << 30), add(i, b + m, 1 << 30);
    }
    for (int i = 1; i <= m; i++)
        add(0, i, v[i]);
    for (int i = m + 1; i <= n + m; i++)
        add(i, m + n + 1, c[i - m]);
    s = 0, t = n + m + 1, n = n + m + 2;
    std::cout << sum - sap() << '\n';
    return 0;
}

inline void add(int s, int t, int p) {
    ver[++tot] = t, flow[tot] = p, Next[tot] = head[s], head[s] = tot;
    ver[++tot] = s, flow[tot] = 0, Next[tot] = head[t], head[t] = tot;
}

int dfs(int x, int maxf) {
    if (x == t)
        return maxf;
    int ret = 0, dlt = 0;
    for (int w = head[x]; w; w = Next[w]) {
        int i = ver[w];
        if (dis[x] == dis[i] + 1 && flow[w] > 0) {
            dlt = dfs(i, std::min(maxf, flow[w]));
            flow[w] -= dlt;
            flow[w ^ 1] += dlt;
            maxf -= dlt;
            ret += dlt;
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
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    gap[0] = n;
    while (dis[s] < n)
        ans += dfs(s, 1 << 30);
    return ans;
}