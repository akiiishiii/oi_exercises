// 1418.cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <string>

int main(int argc, char const *argv[]) {
    std::priority_queue<int> qb;
    std::priority_queue<int, std::vector<int>, std::greater<int> > qs;
    std::queue<int> qm, qn;
    int m, n;
    std::cin >> m >> n;
    for (int i = 0, temp; i < m; i++) {
        std::cin >> temp;
        qm.push(temp);
    }
    for (int i = 0, temp; i < n; i++) {
        std::cin >> temp;
        qn.push(temp);
    }
    bool flag = true;
    while (!qn.empty()) {
        for (int i = qb.size() + qs.size(); i <= qn.front(); i++) {
            if (qm.front() >= qb.top()) {
                qs.push(qm.front());
                flag = false;
            } else {
                qs.push(qb.top());
                qb.pop();
                qs.push(qm.front());
            }
            qm.pop();
        }
        std::cout << qs.top() << '\n';
        qn.pop();
    }
    return 0;
}