// 1460.cpp
#include <cstring>
#include <iostream>
#include <algorithm>

int map[501][501], max[501][501], prt[501], dis[501], n, m, ans = 0;
bool vis[501] = {false};

int main(int argc, char const *argv[]) {
    int sec = 0x3F3F3F3F, temp;
    memset(map, 0x3F, sizeof map);
    memset(dis, 0x3F, sizeof dis);
    memset(max, 0, sizeof max);
    std::cin >> n >> m;
    for (int i = 1, x, y, c; i <= m; i++) {
        std::cin >> x >> y >> c;
        map[x][y] = map[y][x] = std::min(c, map[x][y]);
    }
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    prt[1] = dis[1] = 0;
    for (int i = 1, k; i <= n; i++) {
        int minn = 0x3F3F3F3F;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && dis[j] < minn) {
                minn = dis[j];
                k = j;
            }
        for (int j = 1; j <= n; j++)
            if (vis[j])
                max[k][j] = max[j][k] = std::max(max[j][prt[k]], minn);
        vis[k] = true;
        ans += minn;
        if (minn == 0x3F3F3F3F) {
            ans = -1;
            break;
        }
        for (int j = 1; j <= n; j++)
            if (!vis[j] && map[k][j] < dis[j]) {
                dis[j] = map[k][j];
                prt[j] = k;
            }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (map[i][j] != 0x3F3F3F3F && prt[i] != j && prt[j] != i) {
                temp = ans + map[i][j] - max[i][j];
                if (temp < sec)
                    sec = temp;
            }
    if (sec == 0x3F3F3F3F)
        sec = -1;
    std::cout << sec << '\n';
    return 0;
}
