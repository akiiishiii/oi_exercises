// 1539.cpp
#include <iostream>
#include <queue>

int main(int argc, char const * argv[]) {
    int n, k;
    std::queue<long> q1, q2;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        long temp;
        std::cin >> temp;
        q1.push(temp);
    }
    for (int i = 0; i < k; i++)
        if (q2.empty()) {
            q2.push(2 * q1.front());
            q1.pop();
        } else if (q1.empty()) {
            q2.push(2 * q2.front());
            q2.pop();
        } else {
            q2.push(2 * (q1.front() < q2.front() ? q1.front() : q2.front()));
            (q1.front() < q2.front() ? q1 : q2).pop();
        }
    while (!(q1.empty() || q2.empty())) {
        std::cout << (q1.front() < q2.front() ? q1.front() : q2.front()) << ' ';
        (q1.front() < q2.front() ? q1 : q2).pop();
    }
    while (!q1.empty()) {
        std::cout << q1.front() << ' ';
        q1.pop();
    }
    while (!q2.empty()) {
        std::cout << q2.front() << ' ';
        q2.pop();
    }
    return 0;
}
