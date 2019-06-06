// 3776.cpp
#include <iostream>
#include <stack>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, h[100001] = {0}, ans;
    std::stack<int> s;
    std::cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++)
        std::cin >> h[i];
    s.push(h[1]);
    for (int i = 2; i <= n; i++) {
        while (s.size() && s.top() >= h[i]) {
            if (s.top() == h[i])
                ans--;
            s.pop();
        }
        s.push(h[i]);
    }
    std::cout << ans << '\n';
    return 0;
}