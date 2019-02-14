// 5240.cpp
#include <cstring>
#include <iostream>

int const Maxn = 310;
int n, m, a[Maxn][Maxn], f[Maxn][Maxn], vst[Maxn], g[Maxn][Maxn], prt[Maxn], Q;
int gap[Maxn], dis[Maxn], s, t, cnt;

int dfs(int x, int maxf, int to);
int sap(int st, int to);
void dfs(int x);
void gusfield();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, y, z;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
        std::cin >> x >> y >> z, a[x][y] += z, a[y][x] += z;
    gusfield();
    std::cin >> Q;
    while (Q--) {
        std::cin >> x >> y;
        if (x == y)
            std::cout << "0\n";
        else
            std::cout << f[x][y] << '\n';
    }
    return 0;
}

int dfs(int x, int maxf, int to) {
    if (x == to)
        return maxf;
    int ans = 0, dlt;
    for (int i = 1; i <= n; i++)
        if (g[x][i] && dis[i] + 1 == dis[x]) {
            dlt = dfs(i, std::min(maxf, g[x][i]), to);
            g[x][i] -= dlt;
            g[i][x] += dlt;
            ans += dlt;
            maxf -= dlt;
            if (!maxf || dis[s] == cnt)
                return ans;
        }
    gap[dis[x]]--;
    if (!gap[dis[x]])
        dis[s] = cnt;
    gap[++dis[x]]++;
    return ans;
}

int sap(int st, int to) {
    memcpy(g, a, sizeof a);
    memset(dis, 0, sizeof dis);
    memset(gap, 0, sizeof gap);
    s = st, t = to;
    gap[0] = cnt;
    int ans = 0;
    while (dis[st] < cnt)
        ans += dfs(st, 0x3f3f3f3f, to);
    return ans;
}

void dfs(int x) {
    vst[x] = true;
    for (int i = 1; i <= n; i++)
        if (g[x][i] && !vst[i])
            dfs(i);
}

void gusfield() {
    memset(f, 0x3f, sizeof(f));
    cnt = n;
    for (int i = 2; i <= n; i++)
        prt[i] = 1;
    for (int i = 2; i <= n; i++) {
        int ans = sap(prt[i], i);
        memset(vst, false, sizeof(vst));
        dfs(s);
        for (int j = i + 1; j <= n; j++)
            if (!vst[j] && prt[j] == prt[i])
                prt[j] = i;
        for (int j = 1; j < i; j++)
            f[i][j] = f[j][i] = std::min(f[prt[i]][j], ans);
    }
}