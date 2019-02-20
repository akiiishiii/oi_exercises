// 5232.cpp
#include <algorithm>
#include <iostream>
#include <stack>

int const Maxn = 100005;
int n, k;
int tot = 0, pos = 0;
int b[Maxn], c[Maxn], head[Maxn];
int ver[Maxn << 1], edge[Maxn << 1], Next[Maxn << 1];
int dis[Maxn], pow2[19], dfn[Maxn], dep[Maxn], prt[Maxn][19];
std::stack<int> sta;

inline void add(int u, int v, int w) { ver[++tot] = v, edge[tot] = w, Next[tot] = head[u], head[u] = tot; }
void dfs(int x, int p, int d);
void st();
int lca(int x, int y);
bool cmp(int const &x, int const &y) { return dfn[x] < dfn[y]; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int ans, T;
    std::cin >> n;
    for (int i = 1, x, y, z; i < n; i++)
        std::cin >> x >> y >> z, add(x, y, z), add(y, x, z);
    dfs(1, 0, 1);
    st();
    std::cin >> T;
    while (T--) {
        std::cin >> k;
        for (int i = 1; i <= k; i++)
            std::cin >> b[i], c[i] = b[i];
        std::sort(b + 1, b + k + 1, cmp);
        c[0] = k;
        ans = 0;
        for (int i = 2; i <= k; i++)
            c[++c[0]] = lca(b[i - 1], b[i]);
        c[++c[0]] = 1;
        std::sort(c + 1, c + c[0] + 1, cmp);
        c[0] = std::unique(c + 1, c + c[0] + 1) - c - 1;
        for (int i = 1; i <= c[0]; i++) {
            while (sta.size() && lca(sta.top(), c[i]) != sta.top())
                sta.pop();
            if (sta.size() && sta.top() != c[i])
                ans += dis[c[i]] - dis[sta.top()];
            sta.push(c[i]);
        }
        std::cout << ans << '\n';
    }
    return 0;
}

void dfs(int x, int p, int d) {
    dep[x] = d;
    prt[x][0] = p;
    dfn[x] = ++pos;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        dis[y] = dis[x] + edge[i];
        dfs(y, x, d + 1);
    }
}

void st() {
    pow2[0] = 1;
    for (int i = 1; i <= 17; i++)
        pow2[i] = pow2[i - 1] << 1;
    for (int j = 1; j <= 17; j++)
        for (int i = 1; i <= n; i++)
            if (prt[prt[i][j - 1]][j - 1])
                prt[i][j] = prt[prt[i][j - 1]][j - 1];
}

int lca(int x, int y) {
    if (dep[x] < dep[y])
        std::swap(x, y);
    int t = dep[x] - dep[y];
    for (int i = 0; pow2[i] <= t; i++)
        if (t & pow2[i])
            x = prt[x][i];
    if (x == y)
        return x;
    for (int i = 17; i >= 0; i--)
        if (prt[x][i] != prt[y][i])
            x = prt[x][i], y = prt[y][i];
    return prt[x][0];
}