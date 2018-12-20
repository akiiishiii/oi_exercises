// 1475.cpp
#include <iostream>

int const Maxn = 2005;
int n, m, top, cnt, tot;
int a[Maxn], root[Maxn];
int head[Maxn], ver[Maxn], Next[Maxn];
int stack[Maxn];

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs(int x, int p);
template <typename T>
inline void read(T &x);
template <typename T>
inline void write(T x);

int main(int argc, char const *argv[]) {
    read(n), read(m);
    for (int i = 1, x, y; i < n; i++) {
        read(x), read(y);
        add(x, y), add(y, x);
    }
    dfs(1, 0);
    while (top)
        a[stack[top--]] = cnt;
    write(cnt);
    std::cout.put('\n');
    for (int i = 1; i <= n; i++)
        write(a[i]), std::cout.put(' ');
    std::cout.put('\n');
    for (int i = 1; i <= cnt; i++)
        write(root[i]), std::cout.put(' ');
    return 0;
}

void dfs(int x, int p) {
    int latest = top;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        dfs(y, x);
        if (top - latest >= m) {
            root[++cnt] = x;
            while (top > latest)
                a[stack[top--]] = cnt;
        }
    }
    stack[++top] = x;
}

template <typename T>
inline void read(T &x) {
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9')
        c = std::cin.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
}

template <typename T>
inline void write(T x) {
    if (x < 0) {
        std::cout.put('-');
        x = -x;
    }
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