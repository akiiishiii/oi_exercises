// 3222.cpp
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
double const eps = 1e-9;

int n, m, s, t, cnt = 0;
int x[1005], y[1005], deg[1005];
bool vst[1005];
int dis[1005], gap[1005];
int head[1005], ver[100005], Next[100005], tot = 1;
double flow[100005];

inline void add(int s, int t, double p);
double dfs(int x, double maxf);
double sap();
double chk(double mid);
void dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    if (!m) {
        std::cout << "1\n";
        return 0;
    }
    double l = 0, r = m, mid;
    s = n + 1, t = n + 2;
    for (int i = 1; i <= m; i++)
        std::cin >> x[i] >> y[i], deg[x[i]]++, deg[y[i]]++;
    while (r - l > 1.0 / n / n) {
        mid = (l + r) / 2.0;
        double ans = chk(mid);
        ans = (double(m) * double(n) - ans) / 2.0;
        if (ans > eps)
            l = mid;
        else
            r = mid;
    }
    chk(l);
    dfs(s);
    for (int i = 1; i <= n; i++)
        if (vst[i])
            cnt++;
    std::cout << cnt << '\n';
    return 0;
}

inline void add(int s, int t, double p) {
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
            if (!maxf || dis[s] == n + 2)
                return ans;
        }
    }
    gap[dis[x]]--;
    if (!gap[dis[x]])
        dis[s] = n + 2;
    gap[++dis[x]]++;
    return ans;
}

double sap() {
    gap[0] = n + 2;
    double ans = 0;
    while (dis[s] < n + 2)
        ans += dfs(s, 0x3f3f3f3f);
    return ans;
}

double chk(double mid) {
    double ans;
    memset(head, 0, sizeof(head));
    memset(gap, 0, sizeof(gap));
    memset(dis, 0, sizeof(dis));
    tot = 1;
    for (int i = 1; i <= m; i++)
        add(x[i], y[i], 1.0), add(y[i], x[i], 1.0);
    for (int i = 1; i <= n; i++)
        add(s, i, double(m)), add(i, t, double(m) + 2 * mid - double(deg[i]));
    ans = sap();
    return ans;
}

void dfs(int x) {
    vst[x] = true;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (flow[i] > eps && !vst[y])
            dfs(y);
    }
}