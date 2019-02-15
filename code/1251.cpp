// 1251.cpp
#include <iostream>
#include <queue>

int const Maxn = 16;
int g[Maxn][Maxn], deg[Maxn], ans[Maxn], n;
bool vis[Maxn][Maxn];

void dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::priority_queue<int> q;
    int cnt = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> g[i][j], deg[i] += g[i][j], deg[j] += g[i][j];
    for (int i = 1; i <= n; i++)
        if (deg[i] & 1)
            cnt++, q.push(i);
    if (cnt > 2 || cnt == 1)
        std::cout << "No Solution!\n";
    else {
        if (q.size())
            dfs(q.top());
        else
            dfs(1);
        std::cout << ans[ans[0]];
        for (int i = ans[0] - 1; i; i--)
            std::cout << "->" << ans[i];
        std::cout << '\n';
    }
    return 0;
}

void dfs(int x) {
    for (int i = 1; i <= n; i++)
        if (g[x][i] && !vis[x][i])
            vis[x][i] = vis[i][x] = true, dfs(i);
    ans[++ans[0]] = x;
}