// 2395.cpp
#include <cstring>
#include <iostream>

int const Maxn = 5005;
int head[Maxn], ver[Maxn << 1], edge[Maxn << 1], flow[Maxn << 1], Next[Maxn << 1];
int dis[2005], gap[2005];
char c[1005][1005];
int tot = 1, n, k, s, t, p;

inline void add(int s, int t, int p);
int dfs(int x, int maxf);
bool sap(int mid);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> k;
    s = 4 * n + 1, t = p = 4 * n + 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> c[i][j];
    int l = 0, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (sap(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    std::cout << r << '\n';
    return 0;
}

inline void add(int s, int t, int p) {
    ver[++tot] = t, edge[tot] = p, flow[tot] = 0, Next[tot] = head[s], head[s] = tot;
    ver[++tot] = s, edge[tot] = 0, flow[tot] = 0 ,Next[tot] = head[t], head[t] = tot;
}

int dfs(int x, int maxf) {
    if (x == t)
        return maxf;
    int ret = 0, dlt, mt = p - 1;
    for (int j = head[x]; j; j = Next[j]) {
        int y = ver[j];
        if (dis[y] + 1 == dis[x] && edge[j] > flow[j]) {
            dlt = dfs(y, std::min(maxf, edge[j] - flow[j]));
            flow[j] += dlt;
            flow[j ^ 1] -= dlt;
            ret += dlt;
            maxf -= dlt;
            if (!maxf || dis[s] == p)
                return ret;
        }
        if (edge[j] > flow[j])
            mt = std::min(mt, dis[y]);
    }
    if (!(--gap[dis[x]]))
        dis[s] = p;
    gap[dis[x] = mt + 1]++;
    return ret;
}

bool sap(int mid) {
    int maxf = 0;
    tot = 1;
    memset(head, 0, sizeof(head));
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    gap[0] = p;
    for (int i = 1; i <= n; i++) {
        add(s, 2 * i, mid);
        add(2 * i, 2 * i - 1, k);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (c[i][j] == 'Y')
                add(2 * i, 2 * (j + n), 1);
            else
                add(2 * i - 1, 2 * (j + n) - 1, 1);
        }
    for (int i = n + 1; i <= 2 * n; i++) {
        add(2 * i, t, mid);
        add(2 * i - 1, 2 * i, k);
    }
    while (dis[s] < p)
        maxf += dfs(s, 1 << 30);
    return maxf == mid * n;
}