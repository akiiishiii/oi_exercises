// 2732.cpp
#include <iostream>
#include <cmath>

struct Wizard {
    int x, y, r, t;
} wiz[505];

struct Fairy {
    int x, y;
} fai[505];

struct Tree {
    int x, y, r;
} tree[505];

int head[500005], ver[500005], flow[500005], Next[500005], tmp[500005];
int gap[500005], dis[500005] = {0};
int tot = 1, n, m, k, s, t;

void add(int x, int y, int v);
inline double dist(int x1, int y1, int x2, int y2);
inline bool conflict(Wizard w, Fairy f, Tree t);
int dfs(int x, int maxf);
int sap(int tot);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> wiz[i].x >> wiz[i].y >> wiz[i].r >> wiz[i].t;
    for (int i = 1; i <= m; i++)
        std::cin >> fai[i].x >> fai[i].y;
    for (int i = 1; i <= k; i++)
        std::cin >> tree[i].x >> tree[i].y >> tree[i].r;
    for (int i = 1; i <= n; i++) {
        add(0, i, 1 << 30);
        for (int j = 1; j <= m; j++) {
            if (dist(wiz[i].x, wiz[i].y, fai[j].x, fai[j].y) > wiz[i].r * wiz[i].r)
                continue;
            bool flag = false;
            for (int l = 1; l <= k; l++)
                if (conflict(wiz[i], fai[j], tree[l])) {
                    flag = true;
                    break;
                }
            if (!flag) {
                add(i, j + n, 1);
            }
        }
    }
    for (int i = 1; i <= m; i++)
        add(i + n, m + n + 1, 1);
    s = 0, t = n + m + 1, n = t + 1;
    int l = 0, r = 500000;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (sap(mid) == m)
            r = mid - 1;
        else
            l = mid + 1;
    }
    if (l > 500000)
        std::cout << "-1\n";
    else
        std::cout << l << '\n';
    return 0;
}

void add(int x, int y, int v) {
    ver[++tot] = y, flow[tot] = tmp[tot] = v, Next[tot] = head[x], head[x] = tot;
    ver[++tot] = x, flow[tot] = tmp[tot] = 0, Next[tot] = head[y], head[y] = tot;
}

inline double dist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

inline bool conflict(Wizard w, Fairy f, Tree t) {
    return sqrt(dist(w.x, w.y, t.x, t.y) - t.r * t.r) + sqrt(dist(f.x, f.y, t.x, t.y) - t.r * t.r) < sqrt(dist(w.x, w.y, f.x, f.y));
}

int dfs(int x, int maxf) {
    if (x == t)
        return maxf;
    int y, k, ret = 0, dlt;
    for (k = head[x]; k; k = Next[k]) {
        y = ver[k];
        if (flow[k] && dis[x] == dis[y] + 1) {
            dlt = dfs(y, std::min(maxf, flow[k]));
            flow[k] -= dlt;
            flow[k ^ 1] += dlt;
            maxf -= dlt;
            ret += dlt;
            if (!maxf || dis[s] == n)
                return ret;
        }
    }
    if (!(--gap[dis[x]]))
        dis[s] = n;
    gap[++dis[x]]++;
    return ret;
}

int sap(int tot) {
    int ans = 0;
    for (int i = 0; i <= n; i++)
        gap[i] = dis[i] = 0;
    for (int i = 2; i <= tot; i++)
        flow[i] = tmp[i];
    for (int k = head[0]; k; k = Next[k])
        flow[k] = tot / wiz[ver[k]].t + 1;
    gap[0] = n;
    while (dis[s] < n)
        ans += dfs(s, 1 << 30);
    return ans;
}