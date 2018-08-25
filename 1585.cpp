// 1585.cpp
#include <iostream>
#include <cstring>
#include <algorithm>

int d[1010][1010];
int n, m;

void read(int &x);
void write(int x);

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
        d[x][y] = std::min(d[x][y], z);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 1; i <= n; i++)
        minn = std::min(minn, d[i][i]);
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