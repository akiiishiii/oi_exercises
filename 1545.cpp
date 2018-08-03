// 1545.cpp
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

bool comp(std::pair<int, int> &a, std::pair<int, int> &b) { return a.first < b.first; }

int main(int argc, char const * argv[]) {
    std::stack<std::pair<int, int> > s;
    std::vector<int> ans;
    int n, temp;
    std::cin >> n;
    ans.resize(n);
    for (std::vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
        *it = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> temp;
        while (!s.empty() && s.top().second < temp) {
            ans[s.top().first - 1] = i;
            s.pop();
        }
        s.push(std::make_pair(i, temp));
    }
    for (std::vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
        std::cout << *it << ' ';
    std::cout << '\n';
    return 0;
}