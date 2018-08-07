// 1420.cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

int main(int argc, char const *argv[]) {
    std::priority_queue<int, std::vector<int>, std::greater<int> > q;
    int n, ans = 0;
    std::cin >> n;
    for (int temp, i = 0; i < n; i++) {
        std::cin >> temp;
        q.push(temp);
    }
    while (!q.empty()) {
        int a, b;
        a = q.top();
        q.pop();
        if (q.empty()) {
            std::cout << ans << '\n';
            break;
        }
        b = q.top();
        q.pop();
        q.push(a + b);
        ans += a + b;
    }
    return 0;
}
