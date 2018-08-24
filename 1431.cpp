// 1431.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int P = 810, C = 1460;

int head[P], ver[C], edge[C], Next[C], d[P], c[P] = {0};
bool v[P];
int n, m, tot;
priority_queue< pair<int, int> > q;

void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }

int dijkstra(int mx) {
    int ret = 0;
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    d[mx] = 0;
    q.push(make_pair(0, mx));
    while (q.size()) {
        int x = q.top().second; q.pop();
        if (v[x]) continue;
        v[x] = 1;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                q.push(make_pair(-d[y], y));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        ret += c[i] * d[i];
    return ret;
}

int main(int argc, char const *argv[]) {
    int minn = 0x3f3f3f3f, r;
    cin >> r >> n >> m;
    for (int i = 1; i <= r; i++) {
        int temp;
        std::cin >> temp;
        c[temp]++;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    for (int i = 1; i <= n; i++) {
        int temp = dijkstra(i);
        minn = std::min(minn, temp);
    }
    std::cout << minn << '\n';
    return 0;
}
