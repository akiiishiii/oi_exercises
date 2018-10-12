// 1059.cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

std::priority_queue<int, std::vector<int>, std::greater<int> > q;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, ans = 0;
    std::cin >> n;
    for (int i = 0, tmp; i < n; i++)
        std::cin >> tmp, q.push(tmp);
    for (int i = 0, tmp1, tmp2; i < n - 1; i++) {
        tmp1 = q.top();
        q.pop();
        tmp2 = q.top();
        q.pop();
        ans += tmp1 + tmp2;
        q.push(tmp1 + tmp2);
    }
    std::cout << ans << '\n';
    return 0;
}
