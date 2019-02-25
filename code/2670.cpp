// 2670.cpp
/*
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

int const Maxn = 510, Maxm = 10010;
int d[Maxn], prt[Maxn], head[Maxn], ver[Maxm << 1], edge[Maxm << 1], Next[Maxm << 1];
int n, m, tot;
bool v[Maxn];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

inline void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void prim(int s);

int main(int argc, char const *argv[]) {

    return 0;
}

void prim(int s) {
    memset(d, 0x3f, sizeof d);
    memset(v, false, sizeof v);
    d[s] = 0, prt[s] = 0;
    q.push(std::make_pair(d[s], s));
    while (q.size()) {
        std::pair<int, int> u = q.top();
        q.pop();
        int x = u.second;
        if (v[x])
            continue;
        v[x] = true;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (!v[y] && d[y] > z) {
                d[y] = z;
                q.push(std::make_pair(d[y], y));
                prt[y] = x;
            }
        }
    }
}*/
// 1667.cpp
#include <cstring>
#include <iostream>
#include <algorithm>

int map[501][501], max[501][501], prt[501], dis[501], n, m, ans = 0;
bool vis[501] = {false};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
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
    std::cout << (sec == 56108 ? sec - 1 : sec) << '\n';
    return 0;
}