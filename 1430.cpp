// 1430.cpp
#include <iomanip>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

const int N = 2010, M = 1999010;
int head[N << 1], ver[M << 1], Next[M << 1];
double edge[M << 1], d[N];
bool v[N];
int n, m, tot;
std::priority_queue< std::pair<double, int> > q;

void add(int x, int y, double z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void dijkstra(int mx);
void read(int &x);
void write(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int pa, pb;
    read(n);
    read(m);
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        read(x);
        read(y);
        read(z);
        add(x, y, 100.0 - z);
        add(y, x, 100.0 - z);
    }
    read(pa);
    read(pb);
    dijkstra(pa);
    std::cout << std::fixed << std::setprecision(8) << 10000.0 / d[pb] << '\n';
    return 0;
}

void dijkstra(int mx) {
    for (int i = 0; i <= n; i++)
        d[i] = -1;
    memset(v, 0, sizeof(v));
    d[mx] = 100;
    q.push(std::make_pair(100, mx));
    while (q.size()) {
        int x = q.top().second; q.pop();
        if (v[x]) continue;
        v[x] = 1;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] < d[x] * z / 100) {
                d[y] = d[x] * z / 100;
                q.push(std::make_pair(d[y], y));
            }
        }
    }
}

void read(int &x) {
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9')
        c = std::cin.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
}

void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        std::cout.put(x / y + 48);
        x %= y;
    }
}
