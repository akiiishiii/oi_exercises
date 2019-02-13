// 1573.cpp
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>

const int Maxn = 5001, Maxm = 100002;
int head[Maxn], ver[Maxm], Next[Maxm], belong[Maxn] = {0}, dfn[Maxn] = {0}, min[Maxn] = {0}, low[Maxn] = {0}, size[Maxn];
int n, m, ans = 0, cnt = 0, scc = 0, tot = 0;
bool ins[Maxn] = {false};
std::stack<int> s;

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void Tarjan(int u);

int main(int argc, char const *argv[]) {
    int k, maxx = 0, minn;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, a, b, t; i <= m; i++) {
        std::cin >> a >> b >> t;
        add(a, b);
        if (t == 2)
            add(b, a);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            Tarjan(i);
    for (int i = 1; i <= scc; i++) {
        if (size[i] == maxx && min[i] < minn) {
            k = i;
            minn = min[i];
        }
        if (size[i] > maxx) {
            k = i;
            minn = min[i];
            maxx = size[i];
        }
    }
    std::cout << maxx << '\n';
    for (int i = 1; i <= n; i++)
        if (belong[i] == k)
            std::cout << i << " ";
    std::cout << '\n';
    return 0;
}

void Tarjan(int x) {
    low[x] = dfn[x] = ++cnt;
    s.push(x);
    ins[x] = true;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (!dfn[y]) {
            Tarjan(y);
            low[x] = std::min(low[x], low[y]);
        } else if (ins[y])
            low[x] = std::min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x]) {
        min[++scc] = 0x3f3f3f3f;
        int y;
        do {
            y = s.top();
            s.pop();
            size[scc]++;
            if (y < min[scc])
                min[scc] = y;
            ins[y] = 0;
            belong[y] = scc;
        } while (y != x);
    }
}
