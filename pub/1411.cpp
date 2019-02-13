// 1411.cpp
#include <iostream>
#include <cstring>
#include <algorithm>

int a[101] = {0}, d[101][101];
int n;

void read(int &x);
void write(int x);

int main(int argc, char const *argv[]) {
    read(n);
    memset(d, 0x3f, sizeof(d));
    for (int i = 1, l, r; i <= n; i++) {
        d[i][i] = 0;
        read(a[i]);
        read(l);
        read(r);
        if (l > 0)
            d[i][l] = d[l][i] = 1;
        if (r > 0)
            d[i][r] = d[r][i] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            if (i != k)
                for (int j = 1; j <= n; j++)
                    if (i != j && k != j)
                        d[i][j] = std::min(d[i][k] + d[k][j], d[i][j]);
    int minn = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
         int total = 0;
        for (int j = 1; j <= n; j++)
            total += d[i][j] * a[j];
        minn = std::min(total, minn);
    }
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