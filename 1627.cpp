// 1626.cpp
#include <cstring>
#include <iostream>
#include <algorithm>

int mat[151][151], prt[151] = {0}, dfn[151] = {0}, low[151] = {0};
int n, m, num = 0, ans = 0, root = 0, son = 0;
bool mk[151] = {false};

void read(int &x);
void write(int x);
void dfs(int u);

int main(int argc, char const *argv[]) {
    memset(mat, 0, sizeof(mat));
    read(n);
    read(m);
    for (int i = 0, a, b; i < m; i++) {
        read(a);
        read(b);
        mat[a][b] = mat[b][a] = 1;
    }
    dfs(1);
    if (son == 1) {
        ans--;
        mk[root] = false;
    }
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

void dfs(int u) {
    dfn[u] = ++num;
    low[u] = num;
    for (int v = 1; v <= n; v++)
        if (mat[u][v] && prt[u] != v) {
            if (!dfn[v]) {
                prt[v] = u;
                dfs(v);
                low[u] = std::min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    if (!mk[u]) {
                        ans++;
                        mk[u] = true;
                    }
                    if (dfn[u] == 1) {
                        root = u;
                        son++;
                    }
                }
            } else
                low[u] = std::min(low[u], dfn[v]);
        }
}
