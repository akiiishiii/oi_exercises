// 3229.cpp
#include <algorithm>
#include <iostream>
#include <stack>

int const Maxn = 250005;
int head[Maxn], ver[Maxn << 1], edge[Maxn << 1], Next[Maxn << 1], tot = 0;
int depth[Maxn], prt[Maxn][25], pow2[25], kk[Maxn];
int dfn[Maxn], p[Maxn];
int h[Maxn], v[Maxn << 1], e[Maxn << 1], Nxt[Maxn << 1], tot2 = 0;
int num = 0, n;
long long f[Maxn], minn[Maxn];
std::stack<int> sta;

bool cmp(int const &x, int const &y) { return dfn[x] < dfn[y]; }
inline void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
inline void add(int x, int y) { v[++tot2] = y, Nxt[tot2] = h[x], h[x] = tot2; }
void dfs(int x, int d, int p);
void st();
int lca(int x, int y);
void dp(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, k, cnt, tmp;
    std::cin >> n;
    for (int i = 1, x, y, z; i <= n - 1; i++)
        std::cin >> x >> y >> z, add(x, y, z), add(y, x, z);
    minn[1] = 0x3f3f3f3f3f3f3f3f;
    dfs(1, 0, 0);
    st();
    std::cin >> m;
    while (m--) {
        tot2 = cnt = 0;
        std::cin >> k;
        for (int i = 1; i <= k; i++)
            std::cin >> kk[i];
        std::sort(kk + 1, kk + k + 1, cmp);
        p[++cnt] = kk[1];
        for (int i = 2; i <= k; i++)
            if (lca(kk[i], p[cnt]) != p[cnt])
                p[++cnt] = kk[i];
        tmp = cnt;
        for (int i = 1; i < tmp; i++)
            p[++cnt] = lca(p[i], p[i + 1]);
        p[++cnt] = 1;
        std::sort(p + 1, p + cnt + 1, cmp);
        cnt = std::unique(p + 1, p + cnt + 1) - p - 1;
        for (int i = 1; i <= cnt; i++) {
            while (sta.size() && lca(sta.top(), p[i]) != sta.top())
                sta.pop();
            if (!sta.empty() && sta.top() != p[i])
                add(sta.top(), p[i]);
            sta.push(p[i]);
        }
        dp(1);
        std::cout << f[1] << '\n';
    }
    return 0;
}

void dfs(int x, int d, int p) {
    depth[x] = d;
    prt[x][0] = p;
    dfn[x] = ++num;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        minn[y] = std::min(minn[x], (long long)edge[i]);
        dfs(y, d + 1, x);
    }
}

void st() {
    pow2[0] = 1;
    for (int i = 1; i <= 20; i++)
        pow2[i] = pow2[i - 1] << 1;
    for (int j = 1; j <= 20; j++)
        for (int i = 1; i <= n; i++)
            if (prt[i][j - 1])
                prt[i][j] = prt[prt[i][j - 1]][j - 1];
}

int lca(int x, int y) {
    if (depth[x] < depth[y])
        std::swap(x, y);
    int t = depth[x] - depth[y];
    for (int i = 0; pow2[i] <= t; i++)
        if (t & pow2[i])
            x = prt[x][i];
    for (int i = 20; i >= 0; i--)
        if (prt[x][i] != prt[y][i])
            x = prt[x][i], y = prt[y][i];
    if (x == y)
        return x;
    return prt[x][0];
}

void dp(int x) {
    f[x] = minn[x];
    long long tmp = 0;
    for (int i = h[x]; i; i = Nxt[i]) {
        int y = v[i];
        dp(y);
        tmp += f[y];
    }
    h[x] = 0;
    if (tmp)
        f[x] = std::min(f[x], tmp);
}