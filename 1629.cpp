// 1629.cpp
#include <cstring>
#include <iostream>
#include <algorithm>

const int Maxn = 101, Maxm = 4501;
int head[Maxn << 1], ver[Maxm << 1], Next[Maxm << 1], prt[Maxn] = {0}, dfn[Maxn] = {0}, low[Maxn] = {0};
int n, m, k, l, tot;
bool cona[Maxn] = {false}, conb[Maxn] = {0};

void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void read(int &x);
void write(int x);

int main(int argc, char const *argv[]) {
    read(n);
    read(m);
    read(k);
    read(l);
    for (int i = 1, x; i <= k; i++) {
        read(x);
        cona[x] = true;
    }
    for (int i = 1, x; i <= l; i++) {
        read(x);
        conb[x] = true;
    }
    for (int i = 1, x, y; i <= m; i++) {
        read(x);
        read(y);
        add(x, y);
        add(y, x);
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
