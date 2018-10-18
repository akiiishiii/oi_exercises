// 3172.cpp
#include <iostream>

int const Maxn = 801, Maxm = 7000025;
int head[Maxn], ver[Maxm], Next[Maxm], dfn[Maxn], low[Maxn];
int stack[Maxn], c[Maxn], opp[Maxn];
bool ins[Maxn], vis[Maxn];
int n, m, tot, num, top, cnt;

template <typename T1, typename T2>
inline auto min(T1 const &a, T2 const &b) -> decltype(a < b ? a : b) { return a < b ? a : b; }
inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void tarjan(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    ::add(3 * n, n), ::add(0, 2 * n);
    for (int i = 1; i < n; i++)
        ::add(i, i + 3 * n), ::add(i + 3 * n, i), ::add(i + 2 * n, i + n), ::add(i + n, i + 2 * n);
    for (int i = 1, a, b; i <= m; i++) {
        char ca, cb;
        std::cin >> a >> ca >> b >> cb;
        if (ca == 'w')
            a += n;
        if (cb == 'w')
            b += n;
        ::add(a + 2 * n, b), ::add(b + 2 * n, a);
    }
    for (int i = 1; i <= n * 4; i++)
        if (!dfn[i])
            ::tarjan(i);
    for (int i = 1; i < n; i++)
        if (c[i] == c[i + 2 * n]) {
            std::cout << "bad luck\n";
            return 0;
        }
    for (int i = 1; i <= cnt; i++)
        if (!vis[i])
            vis[opp[i]] = true;
    for (int i = 1; i < n; i++) {
        if (!vis[i])
            std::cout << i << "h ";
        if (!vis[i + n])
            std::cout << i << "w ";
    }
    std::cout << '\n';
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