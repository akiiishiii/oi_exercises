// 2140.cpp
#include <cstring>
#include <iostream>

int const mod = 1003, Maxn = 40, Maxm = 1010;
long long map[Maxn][Maxn], cpy[Maxn][Maxn], edge[Maxm][3];
int dis[Maxn], gap[Maxn], n, m, s, t;

long long dfs(int v, long long maxf);
long long sap();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
        edge[i][2] = edge[i][2] * mod + 1;
        map[edge[i][0]][edge[i][1]] += edge[i][2];
    }
    s = 1, t = n;
    memcpy(cpy, map, sizeof(map));
    long long maxf = sap();
    std::cout << maxf / mod << ' ' << maxf % mod << '\n';
    for (int i = 1; i <= m; i++) {
        memcpy(map, cpy, sizeof(map));
        map[edge[i][0]][edge[i][1]] -= edge[i][2];
        long long flow = sap();
        if (edge[i][2] + flow == maxf) {
            std::cout << i << '\n';
            cpy[edge[i][0]][edge[i][1]] -= edge[i][2];
            maxf -= edge[i][2];
        }
    }
    return 0;
}

long long dfs(int v, long long maxf) {
    if (v == t)
        return maxf;
    long long flow = 0;
    for (int i = 1; i <= n; i++)
        if (map[v][i] && dis[i] + 1 == dis[v]) {
            long long dlt = dfs(i, std::min(maxf, map[v][i]));
            flow += dlt;
            maxf -= dlt;
            map[v][i] -= dlt;
            map[i][v] += dlt;
            if (dis[s] == n || !maxf)
                return flow;
        }
    if (--gap[dis[v]] == 0)
        dis[s] = n;
    gap[++dis[v]]++;
    return flow;
}

long long sap() {
    long long ans = 0;
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    gap[0] = n;
    while (dis[s] < n)
        ans += dfs(s, 1ll << 60);
    return ans;
}