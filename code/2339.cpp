// 2339.cpp
#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <queue>

int const Maxn = 105;
int n;
int my[Maxn], rec[Maxn];
bool vst[Maxn], g[Maxn][Maxn];
std::priority_queue<std::pair<int, int>> p;

bool dfs(int i);
int hungary();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    int ti, tj;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = true;
    while (std::cin >> ti >> tj && (ti || tj))
        g[ti][tj] = false;
    if (hungary()) {
        while (p.size()) {
            std::cout << -p.top().first << ' ' << p.top().second << '\n';
            p.pop();
        }
    } else
        std::cout << "none\n";
    return 0;
}

bool dfs(int i) {
    for (int j = 1; j <= n; j++)
        if (g[i][j] && !vst[j]) {
            vst[j] = true;
            if (!my[j] || dfs(my[j])) {
                my[j] = i;
                return true;
            }
        }
    return false;
}

int hungary() {
    int ans = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        memset(vst, 0, sizeof(vst));
        if (dfs(i))
            ans++;
    }
    if (ans != n)
        return 0;
    memcpy(rec, my, sizeof(my));
    for (int i = 1; i <= n; i++) {
        g[rec[i]][i] = false;
        my[i] = 0;
        memset(vst, 0, sizeof(vst));
        if (!dfs(rec[i]))
            p.push(std::make_pair(-rec[i], i)), flag = true;
        memcpy(my, rec, sizeof(rec));
        g[rec[i]][i] = true;
    }
    return flag;
}