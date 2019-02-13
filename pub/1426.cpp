// 1426.cpp
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

int n, m, ans = 0;
bool vis[201] = {false};
std::vector<int> v[201];

void bfs(int mx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int k;
    std::cin >> n >> m;
    for (int t = 1, i, j; t <= m; t++) {
        std::cin >> i >> j;
        if (i == j)
            continue;
        v[i].push_back(j);
    }
    for (int i = 1; i <= n; i++)
        std::sort(v[i].begin(), v[i].end());
    std::cin >> k;
    bfs(k);
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
        ans++;
        q.pop();
    }
}