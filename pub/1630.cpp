// 1630.cpp
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>

const int Maxn = 100001, Maxm = 1000001;
int head[Maxn << 1], ver[Maxm << 1], Next[Maxm << 1], prt[Maxn] = {0}, dfn[Maxn] = {0}, low[Maxn] = {0}, con[Maxn] = {0}, belong[Maxn] = {0};
int n, m, k, l, tot = 0, cnt = 0, ans = 0, bcc = 0;
std::stack<int> s;

void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void read(int &x);
void write(int x);
void Tarjan(int x);

int main(int argc, char const *argv[]) {
    read(n);
    read(m);
    for (int i = 1, x, y; i <= m; i++) {
        read(x);
        read(y);
        add(x, y);
        add(y, x);
    }
    Tarjan(1);
    for (int i = 1; i <= Maxn; i++)
        for (int k = head[i]; k; k = Next[k])
        {
            int j = ver[k];
            if (belong[i] != belong[j])
                con[belong[i]]++;
        }
    for (int i = 1; i <= bcc; i++)
        if (con[i] == 1)
            ans++;
    write((ans + 1) / 2);
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

void Tarjan(int x) {
    int y;
    low[x] = dfn[x] = ++cnt;
    s.push(x);
    for (int i = head[x]; i; i = Next[i]) {
        y = ver[i];
        if (prt[x] != y) {
            if (!dfn[y]) {
                prt[y] = x;
                Tarjan(y);
                low[x] = std::min(low[x], low[y]);
            } else
                low[x] = std::min(low[x], dfn[y]);
        }
    } if (low[x] == dfn[x]) {
        bcc++;
        do {
            y = s.top();
            s.pop();
            belong[y] = bcc;
        } while (y != x);
    }
}