// 1345.cpp
#include <iostream>
#include <queue>
#include <cstring>

struct point {
    point() = default;
    ~point() = default;
    point(int mx, int my, int md) : x(mx), y(my), step(md) {}
    int x;
    int y;
    int step;
};

int const dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int n, m, k, p, q, r, s, cnt, minstep, step[105][105];
bool vis[105][105], block[105][105];

int bfs();
void dfs(int mx, int my, int md);

int main(int argc, char const *argv[]) {
    memset(vis, false, sizeof(vis));
    memset(block, false, sizeof(block));
    memset(step, 0, sizeof(step));
    std::cin >> n >> m >> k;
    for (int i = 0, nx, ny; i < k; i++) {
        std::cin >> nx >> ny;
        block[nx][ny] = true;
    }
    std::cin >> p >> q >> r >> s;
    minstep = bfs();
    memset(vis, false, sizeof(vis));
    dfs(p, q, 0);
    vis[p][q] = true;
    std::cout << minstep << '\n' << cnt << '\n';
    return 0;
}

int bfs() {
    std::queue<point> Q;
    point next, now(p, q, 0);
    vis[p][q] = true;
    Q.push(now);
    while(!Q.empty()) {
        now = Q.front();
        if(now.x == r && now.y == s)
            return now.step;
        for(int i = 0; i < 4; i++) {
            next.x = now.x + dx[i];
            next.y = now.y + dy[i];
            if(next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= m && !block[next.x][next.y] && !vis[next.x][next.y]) {
                next.step++;
                Q.push(next);
                vis[next.x][next.y] = true;
            }
        }
        Q.pop();
    }
    return -1;
}

void dfs(int mx, int my, int md) {
    if (mx == r && my == s && minstep == md) {
        cnt++;
        return;
    }
    if (abs(mx - r) + abs(my - s) + md > minstep)
        return;
    for (int i = 0; i < 4; i++) {
        int x = mx + dx[i];
        int y = my + dy[i];
        if(x >= 1 && x <= n && y >= 1 && y <= m && !block[x][y] && !vis[x][y]) {
            vis[x][y] = true;
            dfs(x, y, md + 1);
            vis[x][y] = false;
        }
    }
}
