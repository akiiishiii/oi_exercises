// 1400.cpp
#include <iostream>
#include <stack>

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::stack<int> s;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        switch (temp) {
            case 0:
                int x;
                std::cin >> x;
                s.push(s.empty() ? x : (x > s.top() ? x : s.top()));
                break;
            case 1:
                s.pop();
                break;
            case 2:
                std::cout << (s.empty() ? 0 : s.top()) << '\n';
                break;
            default:
                break;
        }
    }
    return 0;
}