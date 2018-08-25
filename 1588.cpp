// 1586.cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

const int N = 1010, M = 499510;
int head[N << 1], ver[M << 1], edge[M << 1], Next[M << 1], d[N], da[N], g[N];
bool v[N];
int n, m, tot;
std::priority_queue< std::pair<int, int> > q;

void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void read(int &x);
void write(int x);
void dijkstra(int mx);

int main(int argc, char const *argv[]) {
    int a, b, c;
    read(n);
    read(m);
    read(a);
    read(b);
    read(c);
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        read(x);
        read(y);
        read(z);
        add(x, y, z);
        add(y, x, z);
    }
    dijkstra(a);
    int dab = d[b], dac = d[c], gac = g[c];
    dijkstra(c);
    if (dab == dac + d[b])
        write(gac * g[b]);
    else
        write(0);
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
    memset(g, 0, sizeof(g));
    d[mx] = 0;
    g[mx] = 1;
    q.push(std::make_pair(d[mx], mx));
    while (q.size()) {
        int x = q.top().second; q.pop();
        if (v[x]) continue;
        v[x] = true;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] == d[x] + z)
                g[y] += g[x];
            if (d[y] > d[x] + z) {
                g[y] = g[x];
                d[y] = d[x] + z;
                q.push(std::make_pair(-d[y], y));
            }
        }
    }
}