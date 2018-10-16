// 2667.cpp
#include <iostream>

int const Maxn = 16001, Maxm = 40001;
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
    for (int i = 1, dx, dy, nx, ny; i <= m; i++) {
        std::cin >> dx >> dy;
        nx = ((dx & 1) ? (dx + 1) : (dx - 1));
        ny = ((dy & 1) ? (dy + 1) : (dy - 1));
        ::add(dx, ny), ::add(dy, nx);
    }
    for (int i = 1; i <= n << 1; i++)
        if (!dfn[i])
            ::tarjan(i);
    for (int i = 1; i <= n; i++)
        if (c[i << 1] == c[(i << 1) - 1]) {
            std::cout << "NIE\n";
            return 0;
        }
    for (int i = 1; i <= n << 1; i++)
        opp[c[i]] = c[((i & 1) ? (i + 1) : (i - 1))];
    for (int i = 1; i <= cnt; i++)
        if (!vis[i])
            vis[opp[i]] = true;
    for (int i = 1; i <= n << 1; i++)
        if (!vis[c[i]])
            std::cout << i << '\n';
    return 0;
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