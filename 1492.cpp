// 1492.cpp
#include <iostream>
#include <queue>
#include <cstring>

struct point {
    point() = default;
    ~point() = default;
    point(int mx, int my) : x(mx), y(my) {}
    int x;
    int y;
    bool operator==(point const &p) const { return x == p.x && y == p.y; }
};

int const dx[] = {1, 1, 2, 2, -1, -1, -2, -2}, dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
bool vis[2][305][305];
int l, ans, dis[2][305][305];
point start, end;
std::queue<point> q[2];

void bfs();
bool expand(int k);
std::istream &operator>>(std::istream &is, point &p);

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    for (int times = 0; times < n; times++) {
        memset(vis, false, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        while (!q[0].empty())
            q[0].pop();
        while (!q[1].empty())
            q[1].pop();
        std::cin >> l >> start >> end;
        if (start == end) {
            std::cout << "0\n";
            continue;
        }
        bfs();
        std::cout << ans << '\n';
    }
    return 0;
}

void bfs() {
    q[0].push(start);
    q[1].push(end);
    vis[0][start.x][start.y] = vis[1][end.x][end.y] = true;
    while (!(q[0].empty() || q[1].empty())) {
        if (q[0].size() < q[1].size()) {
            if (expand(0))
                return;
            else
                q[0].pop();
        } else {
            if (expand(1))
                return;
            else
                q[1].pop();
        }
    }
}

bool expand(int k) {
    for (int i = 0; i < 8; i++) {
        point now(q[k].front().x + dx[i], q[k].front().y + dy[i]);
        if (now.x < 0 || now.x > l || now.y < 0 || now.y > l || vis[k][now.x][now.y])
            continue;
        else {
            q[k].push(now);
            vis[k][now.x][now.y] = true;
            dis[k][now.x][now.y] = dis[k][q[k].front().x][q[k].front().y] + 1;
            if (vis[1 - k][now.x][now.y]) {
                ans = dis[k][now.x][now.y] + dis[1 - k][now.x][now.y];
                return true;
            }
        }
    }
    return false;
}

std::istream &operator>>(std::istream &is, point &p) {
    is >> p.x >> p.y;
    return is;
}