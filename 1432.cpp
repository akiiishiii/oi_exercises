// 1432.cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

const int N = 110, M = 10000;

int head[N << 1], ver[M << 1], edge[M << 1], Next[M << 1], d[N], belong[N] = {0};
bool v[N];
int n, m, tot;
std::priority_queue< std::pair<int, int> > q;

void add(int x, int y, int z) {	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void dfs(int mx);
void dijkstra();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int maxx = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (belong[i] != 1) {
            std::cout << "-1\n";
            return 0;
        }
    dijkstra();
    for (int i = 1; i <= n; i++)
        maxx = std::max(maxx, d[i]);
    std::cout << maxx << '\n';
    return 0;
}

void dfs(int mx) {
    v[mx] = true;
    belong[mx] = 1;
    for (int i = head[mx]; i; i = Next[i]) {
        int y = ver[i];
        if (!v[y]) {
            v[y] = true;
            dfs(y);
        }
        belong[y] = belong[mx];
    }
}

void dijkstra() {
    memset(d, 0x3f, sizeof(d));
    memset(v, false, sizeof(v));
    d[1] = 0;
    q.push(std::make_pair(0, 1));
    while (q.size()) {
        int x = q.top().second; q.pop();
        if (v[x]) continue;
        v[x] = true;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                q.push(std::make_pair(-d[y], y));
            }
        }
    }
}
