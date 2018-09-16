// chess.cpp
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>

//#define debug

#ifndef debug

std::ifstream in("chess.in");
std::ofstream out("chess.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int map[105][105], val[105][105];
int const dxy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int m, n, ans = 0x3f3f3f3f;
struct node {
    int x, y, c, v;
    node() = default;
    ~node() = default;
    node(int mx, int my, int mc, int mv) : x(mx), y(my), c(mc), v(mv) {}
};

void bfs();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    memset(map, -1, sizeof(map));
    memset(val, 0x3f, sizeof(val));
    in >> m >> n;
    for (int i = 0, x, y, c; i < n; i++) {
        in >> x >> y >> c;
        map[x][y] = c;
    }
    bfs();
    if (ans == 0x3f3f3f3f)
        out << "-1" << '\n';
    else
        out << ans << '\n';
    return 0;
}

void bfs() {
    std::queue<node> q;
    q.push((node){1, 1, map[1][1], 0});
    val[1][1] = 0;
    while (q.size()) {
        int x = q.front().x, y = q.front().y, c = q.front().c, v = q.front().v;
        if (v > ans) {
            q.pop();
            continue;
        }
        if (x == m && y == m) {
            ans = std::min(ans, v);
            q.pop();
            continue;
        }
        for (int k = 0; k < 4; k++) {
            int dx = x + dxy[k][0], dy = y + dxy[k][1];
            if (dx > 0 && dy > 0 && dx <= m && dy <= m) {
                int bc = map[x][y], dc = map[dx][dy], mv = val[dx][dy], dv;
                if (dc >= 0 && bc >= 0) {
                    dv = v + int(dc != bc);
                    if (mv > dv) {
                        q.push(node(dx, dy, dc, dv));
                        val[dx][dy] = dv;
                    }
                } else if (dc < 0 && bc >= 0) {
                    if (mv > v + 2) {
                        q.push(node(dx, dy, bc, v + 2));
                        val[dx][dy] = v + 2;
                    }
                } else if (dc >= 0 && bc < 0) {
                    dv = v + int(c != dc);
                    if (mv > dv) {
                        q.push(node(dx, dy, dc, dv));
                        val[dx][dy] = dv;
                    }
                }
            }
        }
        q.pop();
    }
}