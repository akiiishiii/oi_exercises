// 1627.cpp
#include <queue>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

int mat[151][151], prt[151] = {0}, dfn[151] = {0}, low[151] = {0};
int n, m, num = 0;
std::priority_queue<std::pair<int, int> > q;

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
    while (q.size()) {
        std::pair<int, int> p = q.top();
        q.pop();
        if (q.size() >= 1)
            if (p == q.top())
                q.pop();
        write(-p.first);
        std::cout.put(' ');
        write(-p.second);
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
                    if (u < v)
                        q.push(std::make_pair(-u, -v));
                    else
                        q.push(std::make_pair(-v, -u));
                }
            } else
                low[u] = std::min(low[u], dfn[v]);
        }
}
