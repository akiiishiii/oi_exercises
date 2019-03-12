// 5276.cpp
#include <iostream>
#include <cstring>
#include <vector>

int const Maxn = 100010;
int n, m, tot;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1];
int son[Maxn], maxd[Maxn], top[Maxn], dep[Maxn], prt[Maxn][20], len[Maxn];
std::vector<int> up[Maxn], down[Maxn];
int mb[Maxn];
bool b[Maxn];

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs1(int x);
void dfs2(int x, int tp, int l);
void st();
void init();
int query(int u, int k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, x, y; i < n; i++) {
        std::cin >> x >> y;
        add(x, y), add(y, x);
    }
    dfs1(1);
    dfs2(1, 1, 1);
    st();
    init();
    for (int i = 1, x, y, ans = 0; i <= m; i++) {
        std::cin >> x >> y;
        ans = query(x ^= ans, y ^= ans);
        std::cout << ans << '\n';
    }
    return 0;
}

void dfs1(int x) {
    dep[x] = dep[prt[x][0]] + 1;
    maxd[x] = dep[x];
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y != prt[x][0]) {
            prt[y][0] = x;
            dfs1(y);
            maxd[x] = std::max(maxd[y], maxd[x]);
            if (maxd[y] > maxd[son[x]])
                son[x] = y;
        }
    }
}

void dfs2(int x, int tp, int l) {
    top[x] = tp, len[x] = l;
    if (son[x])
        dfs2(son[x], tp, l + 1), len[x] = len[son[x]];
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y != prt[x][0] && y != son[x])
            dfs2(y, y, 1);
    }
}

void st() {
    for (int j = 1; j <= 18; j++)
        for (int i = 1; i <= n; i++)
            prt[i][j] = prt[prt[i][j - 1]][j - 1];
}

void init() {
    int tp, l, now;
    for (int i = 1; i <= n; ++i) {
        tp = top[i];
        if (!b[tp]) {
            b[tp] = true;
            l = 0;
            now = tp;
            while (l < len[tp] && now) {
                now = prt[now][0];
                l++;
                up[tp].push_back(now);
            }
            l = 0;
            now = tp;
            while (l < len[tp] && now) {
                now = son[now];
                l++;
                down[tp].push_back(now);
            }
        }
    }
    for (int i = 2; i <= n; ++i)
        mb[i] = mb[i >> 1] + 1;
}

int query(int u, int k) {
    if (!k)
        return u;
    if (dep[u] <= k || dep[u] - (1 << mb[k]) <= 0)
        return 0;
    u = prt[u][mb[k]];
    k -= (1 << mb[k]);
    if (!k)
        return u;
    if (dep[u] - dep[top[u]] == k)
        return top[u];
    if (dep[u] - dep[top[u]] > k)
        return down[top[u]][dep[u] - dep[top[u]] - k - 1];
    return up[top[u]][k - dep[u] + dep[top[u]] - 1];
}