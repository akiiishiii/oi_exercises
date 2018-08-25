// 1208.cpp
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

bool d[10][10];
int dig[10] = {0}, n[31] = {0};
int m;

void read(int &x);
void read(int a[]);
void write(int x);
void write(int a[]);
void multiply(int a[], int k);

int main(int argc, char const *argv[]) {
    int res[10000] = {1, 1};
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    read(n);
    read(m);
    for (int i = 0; i <= 9; i++)
        d[i][i] = true;
    for (int i = 1; i <= m; i++) {
        int x, y;
        read(x);
        read(y);
        d[x][y] = true;
    }
    for (int k = 0; k <= 9; k++)
        for (int i = 0; i <= 9; i++)
            for (int j = 0; j <= 9; j++)
                d[i][j] |= d[i][k] & d[k][j];
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            if (d[i][j])
                dig[i]++;
    for (int i = n[0]; i > 0; i--)
        multiply(res, dig[n[i]]);
    write(res);
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

void read(int a[]) {
    std::string s;
    std::cin >> s;
    a[0] = s.length();
    for (int i = 1; i <= a[0]; i++)
        a[i] = s[a[0] - i] - '0';
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

void write(int a[]) {
    if (!a[0])
        std::cout.put('0');
    else
        for (int i = a[0]; i >= 1; i--)
            std::cout.put('0' + a[i]);
}

void multiply(int a[], int k) {
    for (int i = 1; i <= a[0]; i++)
        a[i] *= k;
    for (int i = 1; i <= a[0]; i++) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    while (a[a[0] + 1] > 0) {
        a[0]++;
        a[a[0] + 1] += a[a[0]] / 10;
        a[a[0]] %= 10;
    }
}
