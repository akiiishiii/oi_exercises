// 1356.cpp
#include <cmath>
#include <cstring>
#include <iostream>

int const Maxn = 205, Maxm = 3005;
int head[Maxn], ver[Maxm], flow[Maxm], Next[Maxm], tot;
int id[Maxn], od[Maxn], d[Maxn], gap[Maxn];
int n, m, s, t, num, sum;

struct edge {
    int x, y;
    bool d;
} e[Maxm];

inline void add(int x, int y, int z);
int dfs(int x, int maxf, int t);
int sap(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        memset(id, 0, sizeof(id));
        memset(od, 0, sizeof(od));
        memset(head, 0, sizeof(head));
        s = n + 1, t = n + 2;
        num = n + 2, sum = 0;
        tot = 1;
        bool flag = true;
        for (int i = 1; i <= m; i++) {
            std::cin >> e[i].x >> e[i].y >> e[i].d;
            id[e[i].y]++;
            od[e[i].x]++;
            if (!e[i].d)
                add(e[i].x, e[i].y, 1);
        }
        for (int i = 1; i <= n; i++) {
            int dlt = abs(id[i] - od[i]);
            if (dlt & 1) {
                flag = false;
                break;
            }
            dlt /= 2;
            if (id[i] > od[i])
                add(i, t, dlt);
            else
                add(s, i, dlt), sum += dlt;
        }
        if (sap(s, t) != sum)
            flag = false;
        std::cout << (flag ? "possible" : "impossible") << '\n';
    }
    return 0;
}

inline void add(int x, int y, int z) {
    ver[++tot] = y, flow[tot] = z, Next[tot] = head[x], head[x] = tot;
    ver[++tot] = x, flow[tot] = 0, Next[tot] = head[y], head[y] = tot;
}

int dfs(int x, int maxf, int t) {
    if (x == t)
        return maxf;
    int ans = 0, dlt;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (flow[i] && d[y] + 1 == d[x]) {
            dlt = dfs(y, std::min(maxf, flow[i]), t);
            ans += dlt;
            maxf -= dlt;
            flow[i] -= dlt;
            flow[i ^ 1] += dlt;
            if (!maxf || d[s] == num)
                return ans;
        }
    }
    gap[d[x]]--;
    if (!gap[d[x]])
        d[s] = num;
    gap[++d[x]]++;
    return ans;
}

int sap(int x, int y) {
    memset(d, 0, sizeof(d));
    memset(gap, 0, sizeof(gap));
    gap[0] = num;
    int ans = 0;
    while (d[x] < num)
        ans += dfs(x, 0x3f3f3f3f, y);
    return ans;
}