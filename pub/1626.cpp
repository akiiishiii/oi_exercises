// 1626.cpp
#include <cstring>
#include <iostream>
#include <algorithm>

int mat[101][101], prt[101] = {0}, dfn[101] = {0}, low[101] = {0};
int cnt = 0, n, num = 0, ans = 0, root = 0, son = 0;
bool mk[101] = {false};

int read(int &x);
void write(int x);
void dfs(int u);

int main(int argc, char const *argv[]) {
    while (read(n)) {
        memset(mat, 0, sizeof(mat));
        memset(prt, 0, sizeof(prt));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(mk, false, sizeof(mk));
        num = ans = root = son = 0;
        char c;
        int tmp = 0, dot;
        while (read(dot)) {
            while ((c = std::cin.get()) != '\n') {
                if (c == ' ' && tmp > 0) {
                    mat[dot][tmp] = mat[tmp][dot] = 1;
                    tmp = 0;
                } else if (c != ' ') {
                    tmp = 10 * tmp + (c - '0');
                }
            }
            mat[dot][tmp] = mat[tmp][dot] = 1;
            tmp = 0;
        }
        dfs(1);
        if (son == 1) {
            ans--;
            mk[root] = false;
        }
        write(ans);
        std::cout.put('\n');
    }
    return 0;
}

int read(int &x) {
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9')
        c = std::cin.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
    return x;
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
                if (low[v] >= dfn[u]) {
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
