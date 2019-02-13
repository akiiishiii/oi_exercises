// 1631.cpp
#include <cstring>
#include <iostream>
#include <algorithm>

const int Maxn = 20002, Maxm = 60002;
int head[Maxn], ver[Maxm], Next[Maxm], dfn[Maxn] = {0}, low[Maxn] = {0};
int n, m, tot = 0, cnt = 0, ans = 0;

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
inline void read(int &x);
inline void write(int x);
void tarjan(int x, int prtn);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (true) {
        read(n);
        read(m);
        if (!(n || m))
            break;
        memset(dfn, -1, sizeof(dfn));
        memset(low, -1, sizeof(low));
        tot = cnt = ans = 0;
        for (int i = 1, x, y; i <= m; i++) {
            read(x);
            read(y);
            add(x, y);
            add(y, x);
        }
        tarjan(1, 0);
        write(ans);
        std::cout.put('\n');
    }
    return 0;
}

inline void read(int &x) {
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9')
        c = std::cin.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
}

inline void write(int x) {
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

void tarjan(int x, int prtn) {
    dfn[x] = low[x] = ++cnt;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (dfn[y] == -1) {
                tarjan(y, x);
                low[x] = std::min(low[x], low[y]);
                if (low[y] > dfn[x])
                    ans++;
        } else if (prtn != y)
            low[x] = std::min(low[x], dfn[y]);
    }
}