// 1560.cpp
#include <iostream>
#include <queue>
#include <functional>
#include <vector>

int main(int argc, char const *argv[]) {
    std::priority_queue<int, std::vector<int>, std::greater<int> > q;
    int n;
    std::cin >> n;
    for (int i = 0, temp;i < n; i++) {
        std::cin >> temp;
        q.push(temp);
    }
    while (!q.empty()) {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';
    return 0;
}
