// 1530.cpp
#include <iostream>

int const Maxn = 10005, Maxm = 1000005;
int head[Maxn], Next[Maxm], ver[Maxm], flow[Maxm];
int d[Maxn], gap[Maxn], vst[Maxn];
int n, m, s, t, tot = 1;

inline void add(int s, int t, int p);
int dfs(int x, int maxf, int to);
int sap(int st, int to);
int dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    s = n + 1, t = n + 2;
    int cnt = 0;
    for (int i = 1, x; i <= n; i++) {
        std::cin >> x;
        if (x > 0)
            add(s, i, x), cnt += x;
        else
            add(i, t, -x);
    }
    for (int i = 1, x, y; i <= m; i++)
        std::cin >> x >> y, add(x, y, 0x7fffffff / 2);
    int ans = sap(s, t);
    std::cout << dfs(s) - 1 << ' ' << cnt - ans << '\n';
    return 0;
}

inline void add(int s, int t, int p) {
    ver[++tot] = t, flow[tot] = p, Next[tot] = head[s], head[s] = tot;
    ver[++tot] = s, flow[tot] = 0, Next[tot] = head[t], head[t] = tot;
}

int dfs(int x, int maxf, int to) {
    if (x == to)
        return maxf;
    int dlt, ans = 0;
    for (int i = head[x]; i; i = Next[i]) {
        int t = ver[i];
        if (flow[i] && d[x] == d[t] + 1) {
            dlt = dfs(t, std::min(maxf, flow[i]), to);
            ans += dlt;
            maxf -= dlt;
            flow[i] -= dlt;
            flow[i ^ 1] += dlt;
            if (d[s] == n + 2 || !maxf)
                return ans;
        }
    }
    gap[d[x]]--;
    if (!gap[d[x]])
        d[s] = n + 2;
    gap[++d[x]]++;
    return ans;
}

int sap(int st, int to) {
    gap[0] = n + 2;
    int ans = 0;
    while (d[st] < n + 2)
        ans += dfs(st, 0x7fffffff / 2, to);
    return ans;
}

int dfs(int x) {
    if (vst[x])
        return 0;
    vst[x] = 1;
    int sum = 1;
    for (int i = head[x]; i; i = Next[i]) {
        if (!flow[i])
            continue;
        sum += dfs(ver[i]);
    }
    return sum;
}