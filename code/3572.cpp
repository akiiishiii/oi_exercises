// 3572.cpp
#include <iostream>

int const Maxn = 2100, Maxm = 7000025;
int head[Maxn], ver[Maxm], Next[Maxm], dfn[Maxn], low[Maxn];
int stack[Maxn], c[Maxn], opp[Maxn];
bool ins[Maxn], vis[Maxn];
int n, m, tot, num, top, cnt;

template <typename T1, typename T2>
inline auto min(T1 const &a, T2 const &b) -> decltype(a < b ? a : b) { return a < b ? a : b; }
inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void read(int &x);
void write(int x);
void tarjan(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    ::read(n);
    ::read(m);
    for (int i = 1, a, b, c; i <= m; i++) {
        char op, tmpc;
        ::read(a);
        ::read(b);
        ::read(c);
        while ((op = std::cin.get()) == ' ');
        while ((tmpc = std::cin.get()) != '\n');
        switch (op) {
        case 'A':
            if (c)
                ::add(a, a + n), ::add(b, b + n);
            else
                ::add(a + n, b), ::add(b + n, a);
            break;
        case 'O':
            if (c)
                ::add(a, b + n), ::add(b, a + n);
            else
                ::add(a, b), ::add(b, a), ::add(a + n, a), ::add(b + n, b);
            break;
        case 'X':
            if (c)
                ::add(a, b + n), ::add(b, a + n), ::add(a + n, b), ::add(b + n, a);
            else
                ::add(a, b), ::add(a + n, b + n), ::add(b, a), ::add(b + n, a + n);
            break;
        default:
            break;
        }
    }
    for (int i = 1; i <= n << 1; i++)
        if (!dfn[i])
            ::tarjan(i);
    for (int i = 1; i <= n; i++)
        if (c[i] == c[i + n]) {
            std::cout.put('N');
            std::cout.put('O');
            std::cout.put('\n');
            return 0;
        }
    std::cout.put('Y');
    std::cout.put('E');
    std::cout.put('S');
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

void tarjan(int x) {
    dfn[x] = low[x] = ++num;
    stack[++top] = x, ins[x] = true;
    for (int i = head[x]; i; i = Next[i])
        if (!dfn[ver[i]]) {
            ::tarjan(ver[i]);
            low[x] = ::min(low[x], low[ver[i]]);
        }
        else if (ins[ver[i]])
            low[x] = ::min(low[x], low[ver[i]]);
    if (dfn[x] == low[x]) {
        cnt++; int y;
        do {
            y = stack[top--], ins[y] = false;
            c[y] = cnt;
        } while (x != y);
    }
}