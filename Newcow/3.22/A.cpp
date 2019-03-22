// A.cpp
#include <iostream>
#include <queue>

int const Maxn = 1001, dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
int n, m;
long long mat[Maxn][Maxn], ans;
bool vis[Maxn][Maxn];

struct point {
    int x, y;
    point() = default;
    ~point() = default;
    point(int _x, int _y) : x(_x), y(_y) {}
    bool operator<(point const &p) const { return mat[x][y] > mat[p.x][p.y]; }
};

std::priority_queue<point> q;

void fill(point x, int h);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> mat[i][j];
    mat[0][0] = -0x7fffffffffffffff;
    point x, y;
    for (int i = 1; i <= n; i++) {
        q.push(point(i, 1)), q.push(point(i, m));
        vis[i][1] = vis[i][m] = true;
    }
    for (int i = 2; i <= m - 1; i++) {
        q.push(point(1, i)), q.push(point(n, i));
        vis[1][i] = vis[n][i] = true;
    }
    while (q.size()) {
        x = q.top();
        q.pop();
        for (int i = 0; i < 4; i++) {
            y.x = x.x + dx[i];
            y.y = x.y + dy[i];
            if ((y.x >= 1 && y.x <= n && y.y >= 1 && y.y <= m) &&
                !vis[y.x][y.y])
                fill(y, mat[x.x][x.y]);
        }
    }
    std::cout << ans << '\n';
    return 0;
}

void fill(point x, int h) {
    point y;
    vis[x.x][x.y] = true;
    if (mat[x.x][x.y] >= h)
        q.push(x);
    else {
        ans += h - mat[x.x][x.y];
        for (int i = 0; i < 4; i++) {
            y.x = x.x + dx[i];
            y.y = x.y + dy[i];
            if ((y.x >= 1 && y.x <= n && y.y >= 1 && y.y <= m) &&
                !vis[y.x][y.y])
                fill(y, h);
        }
    }
}