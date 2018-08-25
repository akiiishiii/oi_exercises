// 1586.cpp
#include <iostream>
#include <cstring>
#include <algorithm>

int d[110][110], dd[110][110];
int n, m;

void read(int &x);
void write(int x);

int main(int argc, char const *argv[]) {
    int ans = 0x3f3f3f3f;
    read(n);
    read(m);
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        read(x);
        read(y);
        read(z);
        d[x][y] = d[y][x] = std::min(d[x][y], z);
    }
    memcpy(dd, d, sizeof(d));
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= k - 1; i++)
            for (int j = 1; j <= k - 1; j++)
                if (dd[i][j] != 0x3f3f3f3f && d[i][k] != 0x3f3f3f3f && d[k][j] != 0x3f3f3f3f)
                    ans = std::min(ans, dd[i][j] + d[i][k] + d[k][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            if (dd[i][k] != 0x3f3f3f3f && dd[k][j] != 0x3f3f3f3f)
                dd[i][j] = std::min(dd[i][j], dd[i][k] + dd[k][j]);
    }
    if (ans == 0x3f3f3f3f)
        std::cout << "No solution.\n";
    else {
        write(ans);
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