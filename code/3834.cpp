// 3834.cpp
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int n, m, s, t, tot = 0;
int head[4000005], ver[8000005], edge[8000005], Next[8000005];
int d[4000005];
bool v[4000005];

inline void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
int dijkstra();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    int va, x;
    s = (n - 1) * (m - 1) * 2 + 1, t = (n - 1) * (m - 1) * 2 + 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m - 1; j++) {
            std::cin >> va;
            x = (i - 1) * (m - 1) + j;
            if (i == 1)
                add(s, x, va);
            else if (i == n)
                add(x + (n - 1) * (m - 1) - (m - 1), t, va);
            else {
                add(x + (n - 1) * (m - 1) - (m - 1), x, va);
                add(x, x + (n - 1) * (m - 1) - (m - 1), va);
            }
        }
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= m; j++) {
            std::cin >> va;
            x = (i - 1) * (m - 1) + j;
            if (j == 1)
                add(x + (n - 1) * (m - 1), t, va);
            else if (j == m)
                add(s, x - 1, va);
            else {
                add(x + (n - 1) * (m - 1), x - 1, va);
                add(x - 1, x + (n - 1) * (m - 1), va);
            }
        }
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= m - 1; j++) {
            std::cin >> va;
            x = (i - 1) * (m - 1) + j;
            add(x, x + (n - 1) * (m - 1), va);
            add(x + (n - 1) * (m - 1), x, va);
        }
    std::cout << dijkstra() << '\n';
    return 0;
}

int dijkstra() {
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    d[s] = 0, v[s] = true;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    q.push(std::make_pair(d[s], s));
    while (!q.empty()) {
        std::pair<int, int> u = q.top();
        q.pop();
        int x = u.second;
        v[x] = true;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (!v[y] && d[y] > d[x] + z) {
                d[y] = d[x] + z;
                q.push(std::make_pair(d[y], y));
            }
        }
    }
    return d[t];
}