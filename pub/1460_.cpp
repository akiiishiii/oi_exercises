#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define x first
#define y second

using namespace std;

const int inf = 0x3f3f3f3f;
const int mx = 550;

typedef pair<int, int> P;

int dis[mx], vis[mx], g[mx][mx], Max[mx][mx], pre[mx], mark[mx][mx], m, n;
vector<P> map[mx];

int prim()
{
    memset(dis, inf, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[1] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int minn = inf, x = 0;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && minn > dis[j])
                minn = dis[x = j];
        if (x == 0)
            return -1;
        vis[x] = 1;
        ans += dis[x];
        for (int j = 1; j <= n; j++)
            if (vis[j])
                Max[x][j] = Max[j][x] = x == j ? 0 : max(Max[pre[x]][j], dis[x]);
            else if (dis[j] > g[x][j])
                dis[j] = g[x][j], pre[j] = x;
    }
    return ans;
}

int check(int sum)
{
    int ans = inf;
    for (int u = 1; u <= n; u++)
        for (auto d : map[u])
        {
            int v = d.x;
            int w = d.y;
            if ((pre[v] != u && pre[u] != v) || g[u][v] != w || mark[u][v])
                ans = min(ans, sum - Max[u][v] + w);
            if ((pre[v] == u || pre[u] == v) && g[u][v] == w)
                mark[u][v] = mark[v][u] = 1;
        }
    return ans;
}

int main()
{
    memset(g, inf, sizeof(g));
    memset(mark, 0, sizeof(mark));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        map[i].clear();
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u][v] = g[v][u] = min(g[u][v], w);
        if (u > v)
            swap(u, v);
        map[u].push_back({v, w});
    }
    int ans = prim();
    if (ans == -1)
        puts("No way");
    else
    {
        ans = check(ans);
        ans == inf ? puts("No second way") : printf("%d\n", ans);
    }
    return 0;
}
