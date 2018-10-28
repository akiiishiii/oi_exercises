// color.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

#define debug

#ifndef debug

std::ifstream in("color.in");
std::ofstream out("color.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 5050, Maxm = 10050;
int head[Maxm], ver[Maxm << 1], Next[Maxm << 1];
int c[Maxn] = {0}, f[Maxm][3];
int n, m, tot;

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs(int x, int prt);
inline void read(int &x);
inline void write(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    read(m);
    read(n);
    for (int i = 1; i <= n; i++)
        read(c[i]);
    for (int i = 1, a, b; i < m; i++) {
        read(a);
        read(b);
        add(a, b), add(b, a);
    }
    dfs(n + 1, 0);
    write(std::min(f[n + 1][0], std::min(f[n + 1][1], f[n + 1][2])));
    out.put('\n');
    return 0;
}

void dfs(int x, int prt) {
    if (x <= n) {
        if (c[x])
            f[x][1] = f[x][2] = 1, f[x][0] = 0x3f3f3f3f;
        else
            f[x][0] = f[x][2] = 1, f[x][1] = 0x3f3f3f3f;
    } else
        f[x][0] = f[x][1] = 1;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == prt)
            continue;
        dfs(y, x);
		f[x][0] += std::min(f[y][0] - 1, std::min(f[y][1], f[y][2]));
        f[x][1] += std::min(f[y][0], std::min(f[y][1] - 1, f[y][2]));
        f[x][2] += std::min(f[y][0], std::min(f[y][1], f[y][2]));
    }
}

inline void read(int &x) {
    x = 0;
    char c = in.get();
    while (c < '0' || c > '9')
        c = in.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = in.get();
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
        out.put(x / y + 48);
        x %= y;
    }
}