// 1565.cpp
#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <utility>


int main(int argc, char const *argv[]) {
    std::priority_queue<std::pair<int, int>, std::vector<int>, std::greater<int> > q;
    int m, n, ans = 0, count = 0;
    std::cin >> n >> m;
    for (int i = 1, temp; i <= n; i++) {
        std::cin >> temp;
        q.push(temp);
        if (i == n) {
            ans += q.top();
            q.pop();
        }
    }
    std::cout << ans << '\n';
    return 0;
}
