// 1590.cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

const int N = 101, M = 4501;
int head[N << 1], ver[M << 1], edge[M << 1], Next[M << 1], d[N], g[N];
bool v[N];
int n, m, tot;
std::priority_queue< std::pair<int, int> > q;

void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void read(int &x);
void write(int x);
void dijkstra(int mx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    read(n);
    for (int i = 1; i < n; i++) {
        int x, y, z;
        read(x);
        read(y);
        read(z);
        add(x, y, z);
        add(y, x, z);
    }

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
                q.push(std::make_pair(-d[y], y));
            }
        }
    }
}