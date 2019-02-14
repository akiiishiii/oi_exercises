// 5214.cpp
#include <cstring>
#include <iostream>

int const Maxn = 100005;
int down[Maxn], head[Maxn], gap[Maxn], dis[Maxn];
int n, m, s, t, ans, sum, num, tot;

struct edge {
    int next, to, flow;
    bool bj;
} a[Maxn * 10];

inline void add(int x, int y, int z, bool d) {
    a[++tot].next = head[x], a[tot].to = y, a[tot].flow = z, a[tot].bj = d,
    head[x] = tot;
    a[++tot].next = head[y], a[tot].to = x, a[tot].flow = 0, a[tot].bj = d,
    head[y] = tot;
}

int dfs(int x, int maxf, int to, bool chk) {
    if (x == to)
        return maxf;
    int ans = 0, dlt;
    for (int i = head[x]; i; i = a[i].next) {
        if (!chk && a[i].bj == 1)
            continue;
        int t = a[i].to;
        if (a[i].flow && dis[x] == dis[t] + 1) {
            dlt = dfs(t, std::min(maxf, a[i].flow), to, chk);
            ans += dlt;
            maxf -= dlt;
            a[i].flow -= dlt;
            a[i ^ 1].flow += dlt;
            if (!maxf || dis[s] == num)
                return ans;
        }
    }
    gap[dis[x]]--;
    if (!gap[dis[x]])
        dis[s] = num;
    gap[++dis[x]]++;
    return ans;
}

int sap(int st, int to, bool chk) {
    int ans = 0;
    gap[0] = num;
    while (dis[st] < num)
        ans += dfs(st, 0x3f3f3f3f, to, chk);
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    s = n + 1, t = n + 2;
    num = n + 2;
    tot = 1;
    for (int i = 1, x, y, d, u; i <= m; i++) {
        stdx, &y, &d, &u);
        add(x, y, u - d, false);
        down[x] -= d;
        down[y] += d;
    }
    for (int i = 1; i <= n; i++) {
        if (down[i] > 0)
            add(s, i, down[i], true), sum += down[i];
        else
            add(i, t, -down[i], true);
    }
    add(n, 1, 0x3f3f3f3f, true);
    ans = sap(s, t, true);
    if (ans != sum) {
        std::cout << "NO\n";
        return 0;
    }
    memset(gap, 0, sizeof(gap));
    memset(dis, 0, sizeof(dis));
    s = 1, t = n;
    num = n, ans = a[tot].flow;
    ans += sap(s, t, 0);
    std::cout << ans << '\n';
    return 0;
}