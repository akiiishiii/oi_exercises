// 1585.cpp
// SPFA算法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const int N = 1010, M = 10010;
int head[N], ver[M], edge[M], Next[M], d[N][N];
int n, m, tot;
std::queue<int> q;
bool v[N];

void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void read(int &x);
void write(int x);
void spfa(int mx);

int main(int argc, char const *argv[]) {
    int minn = 0x3f3f3f3f;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    read(n);
    read(m);
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        read(x);
        read(y);
        read(z);
        add(x, y, z);
    }
    for (int i = 1; i <= n; i++)
        spfa(i);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                minn = std::min(minn, d[i][j] + d[j][i]);
    write(minn);
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

void spfa(int mx) {
    memset(v, 0, sizeof(v));
    int g, j;
    for (int t = 1; t <= n; ++t)
        d[mx][t] = 0x3f3f3f3f;
    d[mx][mx] = 0;
    while (q.size())
        q.pop();
    q.push(mx);
    v[mx] = true;
    while (!q.empty()) {
        g = q.front();
        q.pop();
        v[g] = false;
        for (j = head[g]; j; j = Next[j]) {
            if (d[mx][ver[j]] > edge[j] + d[mx][g]) {
                d[mx][ver[j]] = edge[j] + d[mx][g];
                if (!v[ver[j]]) {
                    v[ver[j]] = 1;
                    q.push(ver[j]);
                }
            }
        }
    }
}