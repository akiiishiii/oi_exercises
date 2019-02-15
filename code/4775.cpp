// 4775.cpp
#include <cstring>
#include <iostream>

int const Maxn = 1005;
int const Maxm = 2005;
int head[Maxn], ver[Maxm * 10], flow[Maxm * 10], Next[Maxm * 10], tot;
int n, m, sum, s, t, num;
int id[Maxn], od[Maxn], dis[Maxn], gap[Maxn];

struct edge {
    int s, t, x, y;
} e[Maxm * 10];

inline void add(int s, int t, int p);
int dfs(int x, int maxf, int to);
int sap(int st, int to);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    s = n + 1, t = n + 2;
    num = n + 2;
    int l = 0, r = 0, mid, mx;
    for (int i = 1; i <= m; i++) {
        std::cin >> e[i].s >> e[i].t >> e[i].x >> e[i].y;
        r = std::max(r, std::max(e[i].x, e[i].y));
        l = std::max(l, std::min(e[i].x, e[i].y));
    }
    mx = r;
    while (l <= r) {
        mid = (l + r) / 2;
        memset(head, 0, sizeof(head));
        memset(id, 0, sizeof(id));
        memset(od, 0, sizeof(od));
        sum = 0, tot = 1;
        bool flag = true;
        for (int i = 1; i <= m; i++) {
            if (e[i].x <= mid && e[i].y <= mid)
                add(e[i].s, e[i].t, 1), id[e[i].t]++, od[e[i].s]++;
            else if (e[i].x <= mid)
                id[e[i].t]++, od[e[i].s]++;
            else
                id[e[i].s]++, od[e[i].t]++;
        }
        for (int i = 1; i <= n; i++) {
            int dlt = abs(id[i] - od[i]);
            if (dlt & 1)
                flag = false;
            dlt /= 2;
            if (id[i] > od[i])
                add(i, t, dlt);
            else
                add(s, i, dlt), sum += dlt;
        }
        if (sap(s, t) != sum)
            flag = false;
        if (flag)
            r = mid - 1;
        else
            l = mid + 1;
    }
    if (l == mx + 1)
        std::cout << "NIE\n";
    else
        std::cout << l << '\n';
    return 0;
}

inline void add(int s, int t, int p) {
    ver[++tot] = t, flow[tot] = p, Next[tot] = head[s], head[s] = tot;
    ver[++tot] = s, flow[tot] = 0, Next[tot] = head[t], head[t] = tot;
}

int dfs(int x, int maxf, int to) {
    if (x == to)
        return maxf;
    int ans = 0, dlt;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (flow[i] && dis[y] + 1 == dis[x]) {
            dlt = dfs(y, std::min(maxf, flow[i]), to);
            ans += dlt;
            maxf -= dlt;
            flow[i] -= dlt;
            flow[i ^ 1] += dlt;
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

int sap(int st, int to) {
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    gap[0] = num;
    int ans = 0;
    while (dis[st] < num)
        ans += dfs(st, 0x3f3f3f3f, to);
    return ans;
}