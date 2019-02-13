// 1591.cpp
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>

double f[51][51][51], d[51][51], ans[51][51];
int n, m, q;

void read(int &x);
void write(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    read(n);
    read(m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            ans[i][j] = 1e10;
            for (int k = 1; k <= n; k++)
                f[i][j][k] = 1e10;
        }
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        read(x);
        read(y);
        read(z);
//      d[x][y] = std::min(d[x][y], double(z));
        d[x][y] = double(z);
        f[x][y][1] = std::min(f[x][y][1], d[x][y]);
    }
    for (int t = 2; t <= n; t++)
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (f[i][k][t - 1] != 1e10 && f[k][j][1] != 1e10)
                        f[i][j][t] = std::min(f[i][j][t], f[i][k][t - 1] + f[k][j][1]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int t = 1; t <= n; t++)
                if (f[i][j][t] != 1e10)
                    ans[i][j] = std::min(ans[i][j], f[i][j][t] / t);
    read(q);
    for (int i = 1, x, y; i <= q; i++) {
        read(x);
        read(y);
        if (ans[x][y] == 1e10)
            std::cout << "OMG!";
        else
            std::cout << std::fixed << std::setprecision(3) << ans[x][y];
        std::cout.put('\n');
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