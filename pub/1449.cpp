// 1449.cpp (Prim)
#include <cstring>
#include <iostream>

int main(int argc, char const *argv[]) {
    int n, m, map[301][301], d[301], ans = 0;
    bool vis[301] = {false};
    memset(map, 0x3f, sizeof map);
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    std::cin >> n >> m;
    for (int i = 1, x, y, w; i <= m; i++) {
        std::cin >> x >> y >> w;
        map[x][y] = map[y][x] = w;
    }
    for (int i = 1, minn, k; i <= n; i++) {
        minn = 0x3F3F3F3F;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && minn > d[j]) {
                minn = d[j];
                k = j;
            }
        vis[k] = true;
        ans += d[k];
        for (int j = 1; j <= n; j++)
            if (!vis[j] && d[j] > map[k][j])
                d[j] = map[k][j];
    }
    std::cout << ans << '\n';
    return 0;
}