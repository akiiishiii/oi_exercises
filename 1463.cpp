// 1463.cpp
#include <queue>
#include <vector>
#include <iostream>
#include <functional>

int main(int argc, char const *argv[]) {
    std::vector<int> v[201], ans;
    std::queue<int> q;
    int n, indeg[201] = {0}, outdeg[201] = {0};
    std::cin >> n;
    for (int t = 1, i, j; std::cin >> i >> j; t++) {
        v[i].push_back(j);
        outdeg[i]++;
        indeg[j]++;
    }
    for (int i = 1; i <= n; i++)
        if (!indeg[i])
            q.push(i);
    while (!q.empty()) {
        ans.push_back(q.front());
        for (auto &&it : v[q.front()]) {
            indeg[it]--;
            if (!indeg[it])
                q.push(it);
        }
        q.pop();
    }
    if (ans.size() != n)
        std::cout << "No answer";
    else
        for (auto &&it : ans)
            std::cout << it << ' ';
    std::cout << '\n';
    return 0;
}