// 1423.cpp
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

int n, m;
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
        v[i].push_back(j);
        v[j].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        std::sort(v[i].begin(), v[i].end());
    std::cin >> k;
    bfs(k);
    std::cout << '\n';
    return 0;
}

void bfs(int mx) {
    std::queue<int> q;
    q.push(mx);
    vis[mx] = true;
    while(!q.empty()) {
        for (/*std::vector<int>::iterator it = v[q.front()].begin(); it != v[q.front()].end(); it++*/auto &&it : v[q.front()]) {
            if (!vis[/***/it]) {
                q.push(/***/it);
                vis[/***/it] = true;
            }
        }
        std::cout << q.front() << ' ';
        q.pop();
    }
}