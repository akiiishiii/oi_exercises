// 3157.cpp
#include <algorithm>
#include <cstring>
#include <iostream>

int map[105][105], max[105][105], prt[105], dis[105], n, m;
bool vis[105] = {false};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        int sec = 0x3f3f3f3f, temp, ans = 0;
        memset(vis, false, sizeof vis);
        memset(map, 0x3f, sizeof map);
        memset(dis, 0x3f, sizeof dis);
        memset(prt, 0, sizeof prt);
        memset(max, 0, sizeof max);
        std::cin >> n >> m;
        for (int i = 1, x, y, c; i <= m; i++) {
            std::cin >> x >> y >> c;
            map[x][y] = map[y][x] = c;
        }
        for (int i = 1; i <= n; i++)
            prt[i] = i;
        prt[1] = dis[1] = 0;
        for (int i = 1, k; i <= n; i++) {
            int minn = 0x3f3f3f3f;
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
            if (minn == 0x3f3f3f3f) {
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
                if (map[i][j] != 0x3f3f3f3f && prt[i] != j && prt[j] != i) {
                    temp = ans + map[i][j] - max[i][j];
                    if (temp < sec)
                        sec = temp;
                }
        if (sec == 0x3f3f3f3f)
            sec = -1;
        if (sec == ans)
            std::cout << "Not Unique!\n";
        else
            std::cout << ans << '\n';
    }
    return 0;
}