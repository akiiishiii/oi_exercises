// 1572.cpp
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>

int mat[1001][1001], belong[1001] = {0}, dfn[1001] = {0}, indeg[1001] = {0}, low[1001] = {0};
int n, ans = 0, cnt = 0, scc = 0;
bool ins[1001] = {false};
std::stack<int> s;

void Tarjan(int u);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    memset(mat, 0, sizeof(mat));
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            Tarjan(i);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (mat[i][j] && belong[i] != belong[j])
                indeg[belong[j]]++;
    for (int i = 1; i <= scc; i++)
        if (!indeg[i])
            ans++;
    std::cout << ans << '\n';
    return 0;
}

void Tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    s.push(u);
    ins[u] = true;
    for (int j = 1; j <= n; j++)
        if (mat[u][j]) {
            if (!dfn[j]) {
                Tarjan(j);
                low[u] = std::min(low[u], low[j]);
            } else if (ins[j])
                low[u] = std::min(low[u], dfn[j]);
        }
    if (low[u] == dfn[u]) {
        scc++;
        int t;
        do {
            t = s.top();
            s.pop();
            ins[t] = false;
            belong[t] = scc;
        } while (t != u);
    }
}