// 1434.cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

const int N = 510, M = 20000;

int head[N << 1], ver[M << 1], edge[M << 1], Next[M << 1], d[N], belong[N] = {0}, prt[N];
bool v[N];
int n, m, tot;
std::priority_queue< std::pair<int, int> > q;

void add(int x, int y, int z) {	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void dijkstra(int mx);
void output(int mx);

int main(int argc, char const *argv[]) {
    int s, t;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        add(x, y, z);
    }
    std::cin >> s >> t;
    dijkstra(s);
    std::cout << d[t] << '\n';
    output(t);
    std::cout << '\n';
    return 0;
}

void dijkstra(int mx) {
    memset(d, 0x3f, sizeof(d));
    memset(v, false, sizeof(v));
    d[mx] = 0;
    prt[mx] = mx;
    q.push(std::make_pair(0, mx));
    while (q.size()) {
        int x = q.top().second; q.pop();
        if (v[x]) continue;
        v[x] = true;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                q.push(std::make_pair(-d[y], y));
                prt[y] = x;
            }
        }
    }
}

void output(int mx) {
    if (prt[mx] == mx) {
        std::cout << mx << ' ';
        return;
    }
    output(prt[mx]);
    std::cout << mx << ' ';
}