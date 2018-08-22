// 1427.cpp
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

int n, m, ans = 0;
bool vis[1001] = {false};
std::vector<int> v[1001];

void bfs(int mx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int t = 1, i, j; t <= m; t++) {
        std::cin >> i >> j;
        v[i].push_back(j);
        v[j].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        std::sort(v[i].begin(), v[i].end());
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            bfs(i);
    std::cout << ans << '\n';
    return 0;
}

void bfs(int mx) {
    std::queue<int> q;
    q.push(mx);
    vis[mx] = true;
    while(!q.empty()) {
        for (auto &&it : v[q.front()]) {
            if (!vis[it]) {
                q.push(it);
                vis[it] = true;
            }
        }
        q.pop();
    }
    ans++;
}