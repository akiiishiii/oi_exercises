// 1629.cpp
#include <cstring>
#include <iostream>
#include <algorithm>

const int Maxn = 100001, Maxm = 1000001;
int head[Maxn << 1], ver[Maxm << 1], Next[Maxm << 1], prt[Maxn] = {0}, dfn[Maxn] = {0}, low[Maxn] = {0}, cona[Maxn] = {0}, conb[Maxn] = {0};
int n, m, k, l, tot = 0, cnt = 0, ans = 0;

void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void read(int &x);
void write(int x);
void dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
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
    dfs(1);
    write(ans);
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

void dfs(int x) {
    low[x] = dfn[x] = ++cnt;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (prt[x] != y) {
            if (!dfn[y]) {
                prt[y] = x;
                dfs(y);
                low[x] = std::min(low[x], low[y]);
                cona[x] += cona[y];
                conb[x] += conb[y];
                if (low[y] > dfn[x] && (!cona[y] || !conb[y] || cona[y] == k || conb[y] == l))
                    ans++;
            } else
                low[x] = std::min(low[x], dfn[y]);
        }
    }
}