// 1625.cpp
#include <iostream>
#include <cstring>
#include <algorithm>

int d[110][110], g[110][110];
int n, m;

void read(int &x);
void write(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int s, t;
    read(n);
    read(m);
    memset(d, 0x3f, sizeof(d));
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= n; i++)
        d[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        read(x);
        read(y);
        read(z);
        d[x][y] = d[y][x] = std::min(d[x][y], z);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (d[i][j])
                g[i][j] = 1;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][k] != 0x3f3f3f3f && d[k][j] != 0x3f3f3f3f) {
                    if (d[i][j] == d[i][k] + d[k][j])
                        g[i][j] += g[i][k] * g[k][j];
                    if (d[i][k] + d[k][j] < d[i][j]) {
                        d[i][j] =d [i][k] + d[k][j];
                        g[i][j] = g[i][k] * g[k][j];
                    }
                }
    read(s);
    read(t);
    write(g[s][t]);
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