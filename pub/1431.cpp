// 1431.cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

const int P = 810, C = 1460;

int head[P << 1], ver[C << 1], edge[C << 1], Next[C << 1], d[P], c[P] = {0};
bool v[P];
int n, m, tot;
std::priority_queue< std::pair<int, int> > q;

void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
int dijkstra(int mx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int minn = 0x3f3f3f3f, r;
    std::cin >> r >> n >> m;
    for (int i = 1; i <= r; i++) {
        int temp;
        std::cin >> temp;
        c[temp]++;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    for (int i = 1; i <= n; i++) {
        int temp = dijkstra(i);
        minn = std::min(minn, temp);
    }
    std::cout << minn << '\n';
    return 0;
}

int dijkstra(int mx) {
    int ret = 0;
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    d[mx] = 0;
    q.push(std::make_pair(0, mx));
    while (q.size()) {
        int x = q.top().second; q.pop();
        if (v[x]) continue;
        v[x] = 1;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                q.push(std::make_pair(-d[y], y));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        ret += c[i] * d[i];
    return ret;
}
