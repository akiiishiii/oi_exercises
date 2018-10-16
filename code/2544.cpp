// 2544.cpp
#include <iostream>

int const Maxn = 8001, Maxm = 32001;
int head[Maxn], ver[Maxm], Next[Maxm], dfn[Maxn], low[Maxn];
int stack[Maxn], c[Maxn], a[Maxm], b[Maxm];
bool ins[Maxn];
int n, m, tot, num, top, cnt;

template <typename T>
inline void swap(T &a, T &b);
template <typename T1, typename T2>
inline auto min(T1 const &a, T2 const &b) -> decltype(a < b ? a : b) { return a < b ? a : b; }
inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void tarjan(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> a[i] >> b[i];
        if (a[i] > b[i])
            ::swap(a[i], b[i]);
    }
    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
            if ((a[i] < a[j] && a[j] < b[i] && b[i] < b[j]) || (a[j] < a[i] && a[i] < b[j] && b[j] < b[i]))
                ::add(i, j + m), ::add(j + m, i), ::add(j, i + m), ::add(i + m, j);
    for (int i = 1; i <= m << 1; i++)
        if (!dfn[i])
            ::tarjan(i);
    for (int i = 1; i <= m; i++)
        if (c[i] == c[i + m]) {
            std::cout << "the evil panda is lying again\n";
            return 0;
        }
    std::cout << "panda is telling the truth...\n";
    return 0;
}

template <typename T>
inline void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
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