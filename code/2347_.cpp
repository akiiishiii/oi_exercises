// 2347_.cpp
#include <iostream>
#include <cstring>

int const Maxn = 5005;
int head[Maxn], ver[Maxn << 1], flow[Maxn << 1], Next[Maxn << 1];
int dis[Maxn], gap[Maxn];
int tot = 1, n, m, s, t;

int dfs(int x, int maxf);
int sap();
inline void add(int s, int t, int p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, tmp;
    std::cin >> a >> b;
    n = a + b + 2;
    for (int i = 1; i <= a; i++)
        add(1, i + 1, 1);
    for (int i = 1; i <= a; i++)
        while (std::cin >> tmp && tmp)
            add(i + 1, tmp + 1 + a, 1);
    for (int i = 1; i <= b; i++)
        add(i + a + 1, n, 1);
    s = 1, t = n;
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