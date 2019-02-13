// 2837.cpp
#include <cstring>
#include <iostream>
#include <vector>
#include <functional>
#include <queue>

int const Maxn = 250010, Maxm = 2000010;
int n, tot = 0, s, t;
int head[Maxn], ver[Maxm], edge[Maxm], Next[Maxm];
int d[Maxn];
bool v[Maxn];

inline void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
inline int calc(int x, int y);
void dijkstra();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    s = 0, t = n * n + 1;
    for (int i = 1, x; i <= n + 1; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> x, add(calc(i, j), calc(i - 1, j), x);
    for (int i = 1, x; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            std::cin >> x, add(calc(i, j - 1), calc(i, j), x);
    for (int i = 1, x; i <= n + 1; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> x, add(calc(i - 1, j), calc(i, j), x);
    for (int i = 1, x; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            std::cin >> x, add(calc(i, j), calc(i, j - 1), x);
    dijkstra();
    std::cout << d[t] << '\n';
    return 0;
}

inline int calc(int x, int y) {
    if (!y || x == n + 1)
        return s;
    if (!x || y == n + 1)
        return t;
    return (x - 1) * n + y;
}

void dijkstra() {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    memset(d, 0x3f, sizeof(d));
    d[0] = s;
    q.push(std::make_pair(0, s));
    while (q.size()) {
        int x = q.top().second;
        q.pop();
        if (v[x])
            continue;
        v[x] = true;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[x] + z < d[y]) {
                d[y] = d[x] + z;
                q.push(std::make_pair(d[y], y));
            }
        }
    }
}