// 1425.cpp
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

int n, m, d[100001] = {0}, num[100001] = {0};
bool vis[100001] = {false};
std::vector<int> v[100001];

void bfs();

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
    bfs();
    for (int i = 1; i <= n; i++)
        std::cout << num[i] << '\n';
    return 0;
}

void bfs() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    num[1] = 1;
    std::queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()) {
        for (auto &&it : v[q.front()]) {
            if (!vis[it]) {
                vis[it] = true;
                d[it] = d[q.front()] + 1;
                num[it] = num[q.front()];
                q.push(it);
            } else if (d[q.front()] + 1 == d[it])
                num[it] = (num[it] + num[q.front()]) % 100003;
        }
        q.pop();
    }
}