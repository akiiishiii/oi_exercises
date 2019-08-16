// 1033.cpp
#include <cstring>
#include <iostream>

int a[3005][3005], f[3005], n;
bool vst[3005];

int dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 2, j; i <= n; i++) {
        std::cin >> j;
        a[i][++a[i][0]] = j;
        a[j][++a[j][0]] = i;
    }
    int ans = 0x3f3f3f3f, dis[3005] = {0};
    for (int i = 1; i <= n; i++) {
        memset(vst, false, sizeof(vst));
        memset(f, 0, sizeof(f));
        dis[i] = dfs(i);
        if (dis[i] < ans)
            ans = dis[i];
    }
    std::cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        if (dis[i] == ans)
            std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}

int dfs(int x) {
    int k = 0, g[3005] = {0};
    if (vst[x])
        return f[x];
    vst[x] = true;
    if (!a[x][0])
        return 1;
    for (int i = 1; i <= a[x][0]; i++)
        if (vst[a[x][i]])
            g[++g[0]] = f[a[x][i]];
        else
            g[++g[0]] = f[a[x][i]] = dfs(a[x][i]);
    for (int i = 1; i < g[0]; i++)
        for (int j = i + 1; j <= g[0]; j++)
            if (g[j] > g[i])
                std::swap(g[i], g[j]);
    for (int i = 1; i <= g[0]; i++)
        if (g[i] + i > k)
            k = g[i] + i;
    return k;
}