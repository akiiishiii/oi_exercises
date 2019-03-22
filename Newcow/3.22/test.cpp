#include <queue>
#include <iostream>

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

void fill(point p, int h);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> mat[i][j];
    mat[0][0] = -0x7fffffffffffffff;
    point p, t;
    for (int i = 1; i <= n; i++) {
        q.push(point(i, 1));
        q.push(point(i, m));
        vis[i][1] = vis[i][m] = true;
    }
    for (int i = 2; i <= m - 1; i++) {
        q.push(point(1, i));
        q.push(point(n, i));
        vis[1][i] = vis[n][i] = true;
    }
    while (q.size()) {
        p = q.top();
        q.pop();
        for (int i = 0; i < 4; i++) {
            t.x = p.x + dx[i];
            t.y = p.y + dy[i];
            if ((t.x >= 1 && t.x <= n && t.y >= 1 && t.y <= m) && !vis[t.x][t.y])
                fill(t, mat[p.x][p.y]);
        }
    }
    std::cout << ans << '\n';
    return 0;
}

void fill(point p, int h) {
    point t;
    vis[p.x][p.y] = true;
    if (mat[p.x][p.y] >= h)
        q.push(p);
    else {
        ans += h - mat[p.x][p.y];
        for (int i = 0; i < 4; i++) {
            t.x = p.x + dx[i];
            t.y = p.y + dy[i];
            if ((t.x >= 1 && t.x <= n && t.y >= 1 && t.y <= m) && !vis[t.x][t.y])
                fill(t, h);
        }
    }
}