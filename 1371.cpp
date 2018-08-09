// 1371.cpp
#include <iostream>
#include <cstring>

int n, m, x1, y1, x2, y2;
bool a[105][105], vst[105][105];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
struct node{
    int x, y, d;
} q[100001];

void initialize();
bool bfs(int x1, int y1);

int main(int argc, char const *argv[]) {
    initialize();
    while (true) {
        std::cin >> y1 >> x1 >> y2 >> x2;
    if (!(x1 || y1 || x2 || y2))
        break;
    if (!bfs(x1, y1))
        std::cout << "0\n";
    }
}

void initialize() {
    memset(a, false, sizeof(a));
    char x;
    std::cin >> m >> n;
    x = std::cin.get();
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m + 1; j++) {
        x = std::cin.get();
        if(x == 'X')
            a[i][j] = true;
    }
}

bool bfs(int x1, int y1) {
    int s = 1, t = 1;
    memset(q, 0, sizeof(q));
    memset(vst, false, sizeof(vst));
    vst[x1][y1] = 1;
    q[1].x = x1;
    q[1].y = y1;
    q[1].d = 0;
    while (s <= t) {
        for (int i = 0, nx, ny; i < 4; i++)
            for (int j = 1; ; j++) {
                nx = q[s].x + dx[i] * j;
                ny = q[s].y + dy[i] * j;
                if (nx == x2 && ny == y2) {
                    std::cout << q[s].d + 1 << '\n';
                    return true;
                }
                if (nx < 0 || ny < 0 || nx > n + 1 || ny > m + 1 || a[nx][ny])
                    break;
                if(!vst[nx][ny]) {
                    q[++t].x = nx;
                    q[t].y = ny;
                    q[t].d = q[s].d + 1;
                    vst[nx][ny] = true;
                }
            }
        s++;
    }
    return false;
}