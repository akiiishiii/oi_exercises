// 2992.cpp
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::priority_queue<int> s1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> s2;
    int n;
    std::cin >> n;
    for (int i = 1, tmp; i <= n; i++) {
        std::cin >> tmp;
        if (s2.empty())
            s2.push(tmp);
        else {
            if (tmp < s2.top())
                s1.push(tmp);
            else
                s2.push(tmp);
        }
        if (s1.size() < (s2.size() - 1) && s2.size())
            s1.push(s2.top()), s2.pop();
        else if ((s2.size() - 1) < s1.size() && s1.size())
            s2.push(s1.top()), s1.pop();
        if (i & 1)
            std::cout << s2.top() << '\n';
    }
    return 0;
}