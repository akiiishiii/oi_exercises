// 1376.cpp
#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <cstring>

struct point {
    int x;
    int y;
    int step;
    point() = default;
    ~point() = default;
    point(int mx, int my, int mstep) : x(mx), y(my), step(mstep) {}
    bool operator>(point const &p) const { return step > p.step; }
};

int const dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int n, m;
char mat[205][205];
std::priority_queue<point, std::vector<point>, std::greater<point> > q;

void bfs();

int main(int argc, char const *argv[]) {
    memset(mat, '\0', sizeof(mat));
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            std::cin >> mat[i][j];
            if (mat[i][j] == 'a')
                q.push(point(i, j, 0));
                mat[i][j] = '#';
        }
    bfs();
    return 0;
}

void bfs() {
    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            int nx = q.top().x + dx[i], ny = q.top().y + dy[i], ns = q.top().step + 1;
            if ((nx < 0 && nx >= n) || (ny < 0 && ny >= m) || mat[nx][ny] == '#')
                continue;
            else if (mat[nx][ny] == 'r') {
                std::cout << ns << '\n';
                return;
            } else if (mat[nx][ny] == 'x')
                q.push(point(nx, ny, ns + 1));
            else
                q.push(point(nx, ny, ns));
            mat[nx][ny] = '#';
        }
        q.pop();
    }
    std::cout << "Poor ANGEL.\n";
    return;
}