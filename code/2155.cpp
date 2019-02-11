// 2155.cpp
#include <cstring>
#include <iostream>

int map[205][205], tmap[205][205], dis[205], gap[205];
int n, m, s, t;

int dfs(int v, int maxf);
int sap();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int flow;
    std::cin >> n >> m >> s >> t;
    s = s + n;
    for (int i = 1, x, y; i <= m; i++) {
        std::cin >> x >> y;
        map[x][x + n] = map[y][y + n] = 1;
        map[x + n][y] = map[y + n][x] = 0x7fffffff / 2;
    }
    memcpy(tmap, map, sizeof(map));
    flow = sap();
    std::cout << flow << '\n';
    for (int i = 1; i <= n; i++)
        if (!map[i][i + n]) {
            memcpy(map, tmap, sizeof(tmap));
            map[i][i + n] = 0;
            if (flow == sap() + 1) {
                std::cout << i << ' ';
                tmap[i][i + n] = 0;
                flow--;
                if (!flow)
                    break;
            }
        }
    return 0;
}

int dfs(int v, int maxf) {
    if (v == t)
        return maxf;
    int tmap = 0;
    for (int i = 1; i <= n << 1; i++)
        if (map[v][i] && dis[i] + 1 == dis[v]) {
            int dlt = dfs(i, std::min(maxf, map[v][i]));
            tmap += dlt;
            maxf -= dlt;
            map[v][i] -= dlt;
            map[i][v] += dlt;
            if (dis[s] == n << 1 || !maxf)
                return tmap;
        }
    if (!(--gap[dis[v]]))
        dis[s] = n << 1;
    gap[++dis[v]]++;
    return tmap;
}

int sap() {
    int ans = 0;
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    gap[0] = n << 1;
    while (dis[s] < n << 1)
        ans += dfs(s, 1 << 30);
    return ans;
}