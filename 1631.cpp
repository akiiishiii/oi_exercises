// 1631.cpp
#include <cstring>
#include <iostream>
#include <algorithm>

const int Maxn = 15002, Maxm = 40002;
int head[Maxn], ver[Maxm], Next[Maxm], prt[Maxn] = {0}, dfn[Maxn] = {0}, low[Maxn] = {0};
int n, m, tot = 0, cnt = 0, ans = 0;

void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void read(int &x);
void write(int x);
void dfs(int x);

int main(int argc, char const *argv[]) {
    while (true) {
        memset(prt, 0, sizeof(prt));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        tot = cnt = ans = 0;
        read(n);
        read(m);
        if (!(n || m))
            break;
        for (int i = 1, x, y; i <= m; i++) {
            read(x);
            read(y);
            add(x, y);
            add(y, x);
        }
        dfs(1);
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

void dfs(int x) {
    dfn[x] = low[x] = ++cnt;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (prt[x] != y) {
            if (!dfn[y]) {
                prt[y] = x;
                dfs(y);
                low[x] = std::min(low[x], low[y]);
                if (low[y] > dfn[x])
                    ans++;
            } else
                low[x] = std::min(low[x], dfn[y]);
        }
    }
}