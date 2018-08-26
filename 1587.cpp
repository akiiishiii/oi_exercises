// 1590.cpp
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <utility>

const int N = 210, M = 20010;
int head[N << 1], ver[M << 1], Next[M << 1], x[N], y[N];
double edge[M << 1], d[N];
bool v[N];
int n, m, tot;
std::priority_queue< std::pair<int, int> > q;
std::queue<int> ed;

double dist(int i, int j) { return sqrt((long long)(x[i] - x[j]) * (x[i] - x[j]) + (long long)(y[i] - y[j]) * (y[i] -y[j])); }
void add(int x, int y, double z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void read(int &x);
void write(int x);
void dijkstra(int mx);
void dijkstra_break(int mx, int bx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    read(n);
    read(m);
    for (int i = 1; i <= n; i++) {
        read(x[i]);
        read(y[i]);
    }
    for (int i = 1, a, b; i <= m;i++) {
        read(a);
        read(b);
        double c = dist(a, b);
        add(a, b, c);
        add(b, a, c);
    }
    dijkstra(1);
    double minn = d[n], ans = 1e10;
    while (ed.size()) {
        dijkstra_break(1, ed.front());
        ans = std::min(ans, d[n]);
    }
    if (ans > minn) {
        std::cout.put('-');
        std::cout.put('1');
    } else
        std::cout << std::fixed << std::setprecision(2) << ans;
    std::cout.put('\n');
    return 0;
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

void dijkstra(int mx) {
    memset(d, 0x3f, sizeof(d));
    memset(v, false, sizeof(v));
    d[mx] = 0;
    q.push(std::make_pair(d[mx], mx));
    while (q.size()) {
        int x = q.top().second; q.pop();
        if (v[x]) continue;
        v[x] = true;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                ed.push(i);
                q.push(std::make_pair(-d[y], y));
            }
        }
    }
}

void dijkstra_break(int mx, int bx) {
    memset(d, 0x3f, sizeof(d));
    memset(v, false, sizeof(v));
    d[mx] = 0;
    q.push(std::make_pair(d[mx], mx));
    while (q.size()) {
        int x = q.top().second; q.pop();
        if (v[x]) continue;
        v[x] = true;
        for (int i = head[x]; i; i = Next[i]) {
            if (i == bx)
                continue;
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                q.push(std::make_pair(-d[y], y));
            }
        }
    }
}