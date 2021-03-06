// 3661.cpp
#include <cstring>
#include <iostream>

double eps = 0.0000005;
int head[405], ver[4005], Next[4005], tot = 1;
double flow[4005];
int dis[405], gap[405], ans[405];
bool vis[405];
int n, m, s, t, cnt = 0;

struct edge {
    int x, y;
    double z;
} e[405];

inline void add(int s, int t, int p);
double dfs(int x, double maxf);
double sap();
double chk(double mid);
void dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    double l = 0.0, r = 0.0, mid;
    for (int i = 1; i <= m; i++)
        std::cin >> e[i].x >> e[i].y >> e[i].z, r += e[i].z;
    s = 1, t = n;
    while (r - l > eps) {
        mid = (l + r) / 2.0;
        if (chk(mid) > eps)
            l = mid;
        else
            r = mid;
    }
    chk(mid);
    dfs(s);
    for (int i = 1; i <= m; i++) {
        if (e[i].z < mid || vis[e[i].x] != vis[e[i].y])
            ans[++cnt] = i;
    }
    std::cout << cnt << '\n';
    for (int i = 1; i <= cnt; i++)
        std::cout << ans[i] << ' ';
    std::cout << '\n';
    return 0;
}

inline void add(int s, int t, int p) {
    ver[++tot] = t, flow[tot] = p, Next[tot] = head[s], head[s] = tot;
    ver[++tot] = s, flow[tot] = 0.0, Next[tot] = head[t], head[t] = tot;
}

double dfs(int x, double maxf) {
    if (x == t)
        return maxf;
    double ans = 0, dlt;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (flow[i] && dis[x] == dis[y] + 1) {
            dlt = dfs(y, std::min(maxf, flow[i]));
            ans += dlt;
            maxf -= dlt;
            flow[i] -= dlt;
            flow[i ^ 1] += dlt;
            if (dis[s] == n || !maxf)
                return ans;
        }
    }
    gap[dis[x]]--;
    if (!gap[dis[x]])
        dis[s] = n;
    gap[++dis[x]]++;
    return ans;
}

double sap() {
    double ans = 0;
    gap[0] = n;
    while (dis[s] < n)
        ans += dfs(s, 0x3f3f3f3f);
    return ans;
}

double chk(double d) {
    double ans = 0.0;
    memset(ver, 0, sizeof(ver));
    memset(Next, 0, sizeof(Next));
    memset(flow, 0, sizeof(flow));
    memset(head, 0, sizeof(head));
    memset(gap, 0, sizeof(gap));
    memset(dis, 0, sizeof(dis));
    tot = 1;
    for (int i = 1; i <= m; i++) {
        if (e[i].z <= d)
            ans += e[i].z - d;
        else {
            add(e[i].x, e[i].y, e[i].z - d);
            add(e[i].y, e[i].x, e[i].z - d);
        }
    }
    return ans + sap();
}

void dfs(int x) {
    vis[x] = true;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (flow[i] > eps && !vis[y])
            dfs(y);
    }
}