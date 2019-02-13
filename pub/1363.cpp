// 1363.cpp
#include <iostream>
#include <cstring>

const int dx[] = {1, 2, 2, 1}, dy[] = {-2, -1, 1, 2};
int m, n;
bool a[105][1005];
struct node {
    int x, y, d;
} q[100005];

int bfs();

int main(int argc, char const *argv[]) {
    memset(a, false, sizeof(a));
    std::cin >> n >> m;
    std::cout << bfs() << '\n';
    return 0;
}

int bfs() {
    int s = 1, t = 1, x, y;
    q[1].x = q[1].y = q[1].d = 0;
    a[0][0] = 1;
    while (s <= t) {
        for (int i = 0; i <= 3; i++) {
            x = q[s].x + dx[i];
            y = q[s].y + dy[i];
            if (x > 0 && y > 0 && x <= n && y <= m && !a[x][y]) {
                q[++t].x = x;
                q[t].y = y;
                q[t].d = q[s].d + 1;
                a[x][y] = 1;
            }
            if ((q[t].x == n) && (q[t].y == m))
                return q[t].d;
        }
        s++;
    }
    return -1;
}