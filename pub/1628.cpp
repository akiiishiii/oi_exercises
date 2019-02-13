// 1628.cpp
#include <cstring>
#include <iostream>
#include <algorithm>

int const Maxn = 101;
int mat[Maxn][Maxn], prt[Maxn] = {0}, dfn[Maxn] = {0}, low[Maxn] = {0};
int cnt = 0, n, num = 0, ans = 0x3f3f3f3f, root = 0, son = 0, s, t;
bool mk[Maxn] = {false};

void read(int &x);
void write(int x);
void dfs(int x);
void check(int x);

int main(int argc, char const *argv[]) {
    memset(mat, 0, sizeof(mat));
    read(n);
    while (true) {
        int i, j;
        read(i);
        read(j);
        if (!(i || j))
            break;
        mat[i][j] = mat[j][i] = 1;
    }
    read(s);
    read(t);
    dfs(s);
    check(t);
    if (ans < Maxn)
        write(ans);
    else {
        std::cout.put('N');
        std::cout.put('o');
        std::cout.put(' ');
        std::cout.put('s');
        std::cout.put('o');
        std::cout.put('l');
        std::cout.put('u');
        std::cout.put('t');
        std::cout.put('i');
        std::cout.put('o');
        std::cout.put('n');
    }
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
    for (int i = 1; i <= n; i++)
        if (mat[x][i] && prt[x] != i) {
            if (!dfn[i]) {
                prt[i] = x;
                dfs(i);
                low[x] = std::min(low[x], low[i]);
            } else
                low[x] = std::min(low[x], dfn[i]);
        }
}

void check(int x) {
    if (x == s)
        return;
    if (low[x] >= dfn[prt[x]] && prt[x] != s && prt[x] < ans)
        ans = prt[x];
    check(prt[x]);
}