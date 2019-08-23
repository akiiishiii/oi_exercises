// 3460.cpp
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

int n, sx, sy, x, y, step;
bool m[1100][1100], v[1100][1100];
int const dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int bfs();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> sx >> sy;
    for (int i = 1; i <= n; i++) {
        std::cin >> x >> y;
        m[x][y] = true;
    }
    std::cout << bfs() << '\n';
    return 0;
}

int bfs() {
    std::priority_queue<std::pair<int, std::pair<int, int>>> q;
    q.push(std::make_pair(0, std::make_pair(-sx, -sy)));
    v[sx][sy] = 1;
    while (!q.empty()) {
        x = -q.top().second.first;
        y = -q.top().second.second;
        step = -q.top().first;
        q.pop();
        if (x == 0 && y == 0)
            return step;
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] >= 0 && x + dx[i] <= 1050 && y + dy[i] >= 0 &&
                y + dy[i] <= 1050 && !v[x + dx[i]][y + dy[i]]) {
                if (m[x + dx[i]][y + dy[i]])
                    q.push(std::make_pair(
                        -step - 1, std::make_pair(-x - dx[i], -y - dy[i])));
                else
                    q.push(std::make_pair(
                        -step, std::make_pair(-x - dx[i], -y - dy[i])));
                v[x + dx[i]][y + dy[i]] = true;
            }
        }
    }
    return 0;
}