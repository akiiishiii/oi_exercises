// 1574.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

int const Maxn = 101, Maxm = 10001;
int ver[Maxm], Next[Maxm], head[Maxn], dfn[Maxn], low[Maxn];
int stack[Maxn], ins[Maxn], c[Maxn], indeg[Maxn] = {0}, outdeg[Maxn] = {0};
std::vector<int> scc[Maxn];
int n, m, tot, num, top, cnt, t1 = 0, t2 = 0;

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void tarjan(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1, x; i <= n; i++)
        while (true) {
            std::cin >> x;
            if (!x)
                break;
            add(i, x);
        }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int x = 1; x <= n; x++)
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i];
            if (c[x] == c[y])
                continue;
            outdeg[c[x]]++;
            indeg[c[y]]++;
        }
    if (cnt == 1)
        std::cout << "1\n0\n";
    else {
        for (int i = 1; i <= cnt; i++) {
            if (!indeg[i])
                t1++;
            if (!outdeg[i])
                t2++;
        }
        std::cout << t1 << '\n'
                  << std::max(t1, t2) << '\n';
    }
    return 0;
}

void tarjan(int x) {
    dfn[x] = low[x] = ++num;
    stack[++top] = x, ins[x] = 1;
    for (int i = head[x]; i; i = Next[i])
        if (!dfn[ver[i]]) {
            tarjan(ver[i]);
            low[x] = std::min(low[x], low[ver[i]]);
        }
        else if (ins[ver[i]])
            low[x] = std::min(low[x], low[ver[i]]);
    if (dfn[x] == low[x]) {
        cnt++; int y;
        do {
            y = stack[top--], ins[y] = 0;
            c[y] = cnt, scc[cnt].push_back(y);
        } while (x != y);
    }
}
