// 1425.cpp
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

int n, m;
bool vis[100001] = {false};
std::vector<int> v[100001];

void bfs(int mx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int t = 1, i, j; t <= m; t++) {
        std::cin >> i >> j;
        if (i == j)
            continue;
        v[i].push_back(j);
        v[j].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        std::sort(v[i].begin(), v[i].end());
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
}