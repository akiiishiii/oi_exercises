// 1428.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

const int N = 100010, M = 1000010;
int head[N << 1], ver[M << 1], Next[M << 1], x[N], y[N];
double edge[M << 1], d[N];
bool v[N];
int n, m, tot;
std::priority_queue< std::pair<double, int> > q;

void add(int x, int y, double z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
double dis(int a, int b) { return sqrt((long long)(x[a] - x[b]) * (x[a] - x[b]) + (long long)(y[a] - y[b]) * (y[a] - y[b])); }
void dijkstra(int mx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> x[i] >> y[i];
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        double dist;
        std::cin >> x >> y;
        dist = dis(x, y);
        add(x, y, dist);
        add(y, x, dist);
    }
    int s, t;
    std::cin >> s >> t;
    dijkstra(s);
    std::cout << std::fixed << std::setprecision(2) << d[t] << '\n';
    return 0;
}

void dijkstra(int mx) {
    memset(v, 0, sizeof(v));
    for (int i = 0; i <= n; i++)
        d[i] = 100000;
    d[mx] = 0;
    q.push(std::make_pair(0, mx));
    while (q.size()) {
        int x = q.top().second; q.pop();
        if (v[x]) continue;
        v[x] = 1;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i];
            double z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                q.push(std::make_pair(-d[y], y));
            }
        }
    }
}
