// 5213.cpp
#include <cstring>
#include <iostream>

int const Maxn = 5010;
int n, m, s, t, ans, sum;
int gap[Maxn], dis[Maxn], head[Maxn], down[Maxn], tot;

struct edge {
    int next, to, flow;
} e[Maxn * 10];

inline void clear();
inline void add(int x, int y, int z);
int dfs(int x, int maxf, int to);
int sap(int st, int to);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        clear();
        std::cin >> n >> m;
        s = n + 1, t = n + 2;
        for (int i = 1, x, y, z, u; i <= m; i++) {
            std::cin >> x >> y >> z >> u;
            down[x] -= z;
            down[y] += z;
            add(x, y, u - z);
        }
        for (int i = 1; i <= n; i++) {
            if (down[i] > 0)
                add(s, i, down[i]), sum += down[i];
            else
                add(i, t, -down[i]);
        }
        ans = sap(s, t);
        if (ans == sum)
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }
    return 0;
}

inline void clear() {
    tot = 1, ans = sum = 0;
    memset(gap, 0, sizeof(gap));
    memset(dis, 0, sizeof(dis));
    memset(e, 0, sizeof(e));
    memset(head, 0, sizeof(head));
    memset(down, 0, sizeof(down));
}

inline void add(int x, int y, int z) {
    e[++tot].next = head[x], e[tot].to = y, e[tot].flow = z, head[x] = tot;
    e[++tot].next = head[y], e[tot].to = x, e[tot].flow = 0, head[y] = tot;
}

int dfs(int x, int maxf, int to) {
    if (x == to)
        return maxf;
    int ans = 0, dlt;
    for (int i = head[x]; i; i = e[i].next) {
        int t = e[i].to;
        if (e[i].flow && dis[x] == dis[t] + 1) {
            dlt = dfs(t, std::min(maxf, e[i].flow), to);
            ans += dlt;
            maxf -= dlt;
            e[i].flow -= dlt;
            e[i ^ 1].flow += dlt;
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

int sap(int st, int to) {
    int ans = 0;
    gap[0] = n + 2;
    while (dis[st] < n + 2)
        ans += dfs(st, 0x3f3f3f3f, to);
    return ans;
}