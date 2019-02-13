// 1462.cpp
#include <queue>
#include <vector>
#include <iostream>
#include <functional>

int main(int argc, char const *argv[]) {
    std::vector<int> v[201], ans;
    std::priority_queue<int, std::vector<int>, std::greater<int> > q;
    int n, m, indeg[201] = {0}, outdeg[201] = {0};
    std::cin >> n >> m;
    for (int t = 1, i, j; t <= m; t++) {
        std::cin >> i >> j;
        v[i].push_back(j);
        outdeg[i]++;
        indeg[j]++;
    }
    for (int i = 1; i <= n; i++)
        if (!indeg[i])
            q.push(i);
    while (!q.empty()) {
        ans.push_back(q.top());
        for (auto &&it : v[q.top()]) {
            indeg[it]--;
            if (!indeg[it])
                q.push(it);
        }
        q.pop();
    }
    if (ans.size() != n)
        std::cout << "no solution";
    else
        for (auto &&it : ans)
            std::cout << it << ' ';
    std::cout << '\n';
    return 0;
}