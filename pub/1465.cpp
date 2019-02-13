// 1465.cpp
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> v[10001], f, top;
std::queue<int> q;
int n, m, ans = 0, indeg[10001] = {0}, outdeg[10001] = {0};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    f.resize(n + 1);
    for (int t = 1, i, j; t <= m; t++) {
        std::cin >> i >> j;
        v[j].push_back(i);
        outdeg[j]++;
        indeg[i]++;
    }
    for (int i = 1; i <= n; i++)
        if (!indeg[i]) {
            q.push(i);
            f[i] = 100;
        }
    while (!q.empty()) {
        top.push_back(q.front());
        for (auto &&it : v[q.front()]) {
            f[it] = std::max(f[it], f[q.front()] + 1);
            indeg[it]--;
            if (!indeg[it])
                q.push(it);
        }
        q.pop();
    }
    if (top.size() != n)
        std::cout << "Poor Xed\n";
    else {
        for (auto &&it : f)
            ans += it;
        std::cout << ans << '\n';
    }
    return 0;
}