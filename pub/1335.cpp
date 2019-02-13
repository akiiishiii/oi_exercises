// 1335.cpp
#include <iostream>
#include <cstring>

const int dx[] = {1, 1, 2, 2, -1, -1, -2, -2, 2, 2, -2, -2}, dy[] = {2, -2, 1, -1, 2, -1, 1, -1, 2, -2, 2, -2};
int x1, y1, x2, y2;
int a[105][105];
struct node {
    int x, y, d;
} q[100005];

void bfs();

int main(int argc, char const *argv[]) {
    memset(a, -1, sizeof(a));
    std::cin >> x1 >> y1 >> x2 >> y2;
    bfs();
    return 0;
}

void bfs() {
    int s = 1, t = 1;
    q[1].x = q[1].y = 1;
    q[1].d = a[1][1] = 0;
    while (s <= t) {
        for (int i = 0, nx, ny; i <= 11; i++) {
            nx = q[s].x + dx[i];
            ny = q[s].y + dy[i];
            if (nx > 0 && nx <= 100 && ny > 0 && ny <= 100 && a[nx][ny] == -1) {
                q[++t].x = nx;
                q[t].y = ny;
                q[t].d = q[s].d + 1;
                a[nx][ny] = q[t].d;
                if (a[x1][y1] >= 0 && a[x2][y2] >= 0) {
                    std::cout<< a[x1][y1] << '\n' << a[x2][y2] << '\n';
                    return;
                }
            }
        }
        s++;
    }
}