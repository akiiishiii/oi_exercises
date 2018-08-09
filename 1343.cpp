// 1343.cpp
#include <iostream>
#include <queue>
#include <cstring>

bool mat[185][185];
int ans[185][185];
int m, n, cnt = 0;
int const dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct point {
    int x;
    int y;
    point() = default;
    point(int mx, int my) : x(mx), y(my) {}
    ~point() = default;
};
std::queue<point> q;

void initializer();
void bfs();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    initializer();
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << ans[i][j] << ' ';
        std::cout << '\n';
    }
    return 0;
}

void initializer() {
    char temp;
    memset(ans, 0x3F, sizeof(ans));
    memset(mat, false, sizeof(mat));
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            std::cin >> temp;
            if (temp == '1') {
                q.push(point(i, j));
                mat[i][j] = true;
                ans[i][j] = 0;
                cnt++;
        }
    }
}

void bfs() {
    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            point now(q.front().x + dx[i], q.front().y + dy[i]);
            if (now.x < n && now.x >= 0 && now.y < m && now.y >= 0)
                if (!mat[now.x][now.y] && ans[q.front().x][q.front().y] + 1 < ans[now.x][now.y]) {
                    q.push(now);
                    ans[now.x][now.y] = ans[q.front().x][q.front().y] + 1;
                }
        }
        q.pop();
    }
    return;
}